#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>

class Library {
private:
    std::vector<Book> books;

public:
    void load();
    void save();

    void addBook();
    void displayAll();
    void searchBook();
    void issueBook();
    void returnBook();
};

#endif
