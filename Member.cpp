#include "Member.h"

Member::Member(string n, string id, int maxB)
    : name(n), memberId(id), maxBooks(maxB) {}

string Member::getId() const {
    return memberId;
}

string Member::getName() const {
    return name;
}

int Member::getMaxBooks() const {
    return maxBooks;
}

void Member::printInfo() const {
    cout << "Member: " << name
         << " | ID: " << memberId
         << " | Max books: " << maxBooks
         << endl;
}

