#include "Library.h"
#include <fstream>
#include <iostream>

void Library::load() {
    std::ifstream file("books.txt");
    int id;
    std::string title, author;
    bool issued;

    while (file >> id >> title >> author >> issued) {
        Book b(id, title, author);
        if (issued) b.issueBook();
        books.push_back(b);
    }
}

void Library::save() {
    std::ofstream file("books.txt");

    for (auto &b : books) {
        file << b.getId() << " "
             << b.getTitle() << " "
             << b.getAuthor() << " "
             << b.isIssued() << "\n";
    }
}

void Library::addBook() {
    int id;
    std::string title, author;

    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cout << "Enter Title: ";
    std::cin >> title;
    std::cout << "Enter Author: ";
    std::cin >> author;

    books.emplace_back(id, title, author);
    save();
}

void Library::displayAll() {
    for (auto &b : books) {
        b.display();
    }
}

void Library::searchBook() {
    std::string title;
    std::cout << "Enter Title: ";
    std::cin >> title;

    for (auto &b : books) {
        if (b.getTitle() == title) {
            b.display();
            return;
        }
    }
    std::cout << "Not found\n";
}

void Library::issueBook() {
    int id;
    std::cout << "Enter Book ID: ";
    std::cin >> id;

    for (auto &b : books) {
        if (b.getId() == id && !b.isIssued()) {
            b.issueBook();
            save();
            std::cout << "Book issued\n";
            return;
        }
    }
    std::cout << "Cannot issue\n";
}

void Library::returnBook() {
    int id;
    std::cout << "Enter Book ID: ";
    std::cin >> id;

    for (auto &b : books) {
        if (b.getId() == id && b.isIssued()) {
            b.returnBook();
            save();
            std::cout << "Book returned\n";
            return;
        }
    }
    std::cout << "Cannot return\n";
}
