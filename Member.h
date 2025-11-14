#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <iostream>

using namespace std;

class Member {
private:
    string name;
    string memberId;
    int maxBooks;

public:
    Member(string n, string id, int maxB = 5);
    string getId() const;
    string getName() const;
    int getMaxBooks() const;
    void printInfo() const;
};

#endif // MEMBER_H

