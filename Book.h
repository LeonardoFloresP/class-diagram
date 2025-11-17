#ifndef BOOK_H
#define BOOK_H


#include "Media.h" 
#include <string>
#include <iostream>

using namespace std;


class Book : public Media {
private:

    string author;
    string isbn;
    int publicationYear;

public:

    Book(string t, string a, string i, int year) : Media(t), author(a), isbn(i), publicationYear(year) {} 
    
    string getIsbn() const;

    void printInfo() const override; 
};

#endif // BOOK_H
