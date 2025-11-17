#include "Library.h"
#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;



Member* Library::findMember(const string& memberId) {
    for (auto& member : members) {
        if (member.getId() == memberId) {
            return &member;
        }
    }
    return nullptr;
}

int Library::countActiveLoansForMember(const string& memberId) const {
    int count = 0;
    for (const auto& loan : loans) {
        if (loan.getMemberId() == memberId && loan.isActive()) {
            count++;
        }
    }
    return count;
}


bool Library::isBookAvailable(const string& isbn) const {
    for (const auto& loan : loans) {
        if (loan.getIsbn() == isbn && loan.isActive()) {
            return false; 
        }
    }
    return true;
}

Loan* Library::findActiveLoan(const string& memberId, const string& isbn) {
    for (auto& loan : loans) {
        if (loan.getMemberId() == memberId &&
            loan.getIsbn() == isbn &&
            loan.isActive()) {
            return &loan;
        }
    }
    return nullptr;
}

void Library::addMember(const Member& member) {
    members.push_back(member);
}

void Library::listMembers() const {
    cout << "=== Members ===" << endl;
    for (const auto& member : members) {
        member.printInfo();
    }
    cout << endl;
}

void Library::listLoans(bool onlyActive) const {
    cout << (onlyActive ? "=== Active loans ===" : "=== All loans ===") << endl;
    for (const auto& loan : loans) {
        if (onlyActive && !loan.isActive()) {
            continue;
        }
        loan.printInfo();
    }
    cout << endl;
}



void Library::addItem(Media* item) {
    items.push_back(item);
}


void Library::listItems() const {
    cout << "=== Items en la Colección (Books & CDs) ===" << endl;
    for (const auto& item : items) {
        // Polimorfismo: llama al printInfo() correcto
        item->printInfo(); 
    }
    cout << endl;
}


bool Library::removeBook(const string& isbn) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        
        Book* bookPtr = dynamic_cast<Book*>(*it); 
        
        if (bookPtr && bookPtr->getIsbn() == isbn) {
            delete *it; 
            items.erase(it);
            return true;
        }
    }
    return false;
}


bool Library::removeMember(const string& memberId) {
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (it->getId() == memberId) {
        
            members.erase(it);
            return true;
        }
    }
    return false;
}


vector<Book> Library::searchBook(const string& query) const {
    vector<Book> results;
    string lowerQuery = query;

    transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);

    for (const auto& item : items) {
        Book* bookPtr = dynamic_cast<Book*>(item);
        
        if (bookPtr) { 
            string lowerTitle = bookPtr->getTitle();
            transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);

          
            if (bookPtr->getIsbn() == query || lowerTitle.find(lowerQuery) != string::npos) {
                results.push_back(*bookPtr); // Devuelve el objeto Book, no el puntero
            }
        }
    }
    return results;
}



bool Library::borrowBook(const string& memberId, const string& isbn, const string& borrowDate) {
    Member* member = findMember(memberId);
    if (!member) {
        cout << "Member not found." << endl;
        return false;
    }



    if (!isBookAvailable(isbn)) {
        cout << "Item is currently not available." << endl;
        return false;
    }

    int activeLoans = countActiveLoansForMember(memberId);
    if (activeLoans >= member->getMaxBooks()) {
        cout << "Member has reached the maximum number of active loans." << endl;
        return false;
    }


    loans.push_back(Loan(isbn, memberId, borrowDate));
    cout << "Item borrowed successfully." << endl;
    return true;
}

bool Library::returnBook(const string& memberId, const string& isbn, const string& returnDate) {
    Member* member = findMember(memberId);
    if (!member) {
        cout << "Member not found." << endl;
        return false;
    }


    Loan* loan = findActiveLoan(memberId, isbn);
    if (!loan) {
        cout << "No active loan found for this member and item." << endl;
        return false;
    }

    loan->setReturnDate(returnDate);
    cout << "Item returned successfully." << endl;
    return true;
}
