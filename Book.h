#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    int publicationYear;

public:
    Book(string t, string a, string i, int year);
    string getIsbn() const;
    string getTitle() const;
    void printInfo() const;
};

#endif // BOOK_H

