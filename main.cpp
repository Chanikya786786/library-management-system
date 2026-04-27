#include "Library.h"
#include <iostream>

int main() {
    Library lib;
    lib.load();

    int choice;

    do {
        std::cout << "\n1. Add Book\n";
        std::cout << "2. Display All\n";
        std::cout << "3. Search Book\n";
        std::cout << "4. Issue Book\n";
        std::cout << "5. Return Book\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: lib.addBook(); break;
        case 2: lib.displayAll(); break;
        case 3: lib.searchBook(); break;
        case 4: lib.issueBook(); break;
        case 5: lib.returnBook(); break;
        case 6: break;
        default: std::cout << "Invalid\n";
        }

    } while (choice != 6);

    return 0;
}
