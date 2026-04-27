#include "Book.h"
#include <iostream>

Book::Book() : id(0), title(""), author(""), issued(false) {}

Book::Book(int id, std::string title, std::string author)
    : id(id), title(title), author(author), issued(false) {}

int Book::getId() const { return id; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
bool Book::isIssued() const { return issued; }

void Book::issueBook() { issued = true; }
void Book::returnBook() { issued = false; }

void Book::display() const {
    std::cout << "\nID: " << id
              << "\nTitle: " << title
              << "\nAuthor: " << author
              << "\nStatus: " << (issued ? "Issued" : "Available") << "\n";
}
