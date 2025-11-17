#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Media.h"    
#include "Book.h"
#include "Member.h"
#include "Loan.h"

using namespace std;

class Library {
private:
    vector<Media*> items; 
    vector<Member> members;
    vector<Loan> loans;


    Media* findItem(const string& query); 
    Member* findMember(const string& memberId); 
    int countActiveLoansForMember(const string& memberId) const;
    bool isItemAvailable(const string& query) const; 
    Loan* findActiveLoan(const string& memberId, const string& isbn);

public:

    void addItem(Media* item); 
    void listItems() const;     


    bool removeBook(const string& isbn);
    bool removeMember(const string& memberId);
    vector<Book> searchBook(const string& query) const;

  
    void addMember(const Member& member);
    void listMembers() const;
    void listLoans(bool onlyActive = false) const;
    bool borrowBook(const string& memberId, const string& isbn, const string& borrowDate);
    bool returnBook(const string& memberId, const string& isbn, const string& returnDate);
    
   
};

#endif // LIBRARY_H
