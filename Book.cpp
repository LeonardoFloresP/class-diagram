#include "Book.h"

Book::Book(string t, string a, string i, int year)
    : title(t), author(a), isbn(i), publicationYear(year) {}

string Book::getIsbn() const {
    return isbn;
}

string Book::getTitle() const {
    return title;
}

void Book::printInfo() const {
    cout << "Title: " << title
         << " | Author: " << author
         << " | ISBN: " << isbn
         << " | Year: " << publicationYear
         << endl;
}

