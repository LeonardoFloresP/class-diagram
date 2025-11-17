#include "Book.h"
#include <iostream>

using namespace std;


Book::Book(string t, string a, string i, int year)
    : Media(t), author(a), isbn(i), publicationYear(year) {}

string Book::getIsbn() const {
    return isbn;
}


void Book::printInfo() const {

    cout << "Book Title: " << title
         << " | Author: " << author
         << " | ISBN: " << isbn
         << " | Year: " << publicationYear
         << endl;
}
