#include <iostream>
#include <vector>
#include <string>

class Book {
public:
    int id;
    std::string title;
    std::string author;
    bool isIssued;

    Book(int id, std::string title, std::string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->isIssued = false;
    }
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(int id, std::string title, std::string author) {
        books.push_back(Book(id, title, author));
        std::cout << "Book added successfully.\n";
    }

    void issueBook(int id) {
        for (auto &book : books) {
            if (book.id == id) {
                if (!book.isIssued) {
                    book.isIssued = true;
                    std::cout << "Book issued successfully.\n";
                } else {
                    std::cout << "Book is already issued.\n";
                }
                return;
            }
        }
        std::cout << "Book not found.\n";
    }

    void returnBook(int id) {
        for (auto &book : books) {
            if (book.id == id) {
                if (book.isIssued) {
                    book.isIssued = false;
                    std::cout << "Book returned successfully.\n";
                } else {
                    std::cout << "Book was not issued.\n";
                }
                return;
            }
        }
        std::cout << "Book not found.\n";
    }

    void displayBooks() {
        for (const auto &book : books) {
            std::cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << ", Issued: " << (book.isIssued ? "Yes" : "No") << "\n";
        }
    }
};

int main() {
    Library library;
    int choice, id;
    std::string title, author;

    while (true) {
        std::cout << "1. Add Book\n2. Issue Book\n3. Return Book\n4. Display Books\n5. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter book ID: ";
                std::cin >> id;
                std::cout << "Enter book title: ";
                std::cin.ignore(); // to ignore the newline character left in the buffer
                std::getline(std::cin, title);
                std::cout << "Enter book author: ";
                std::getline(std::cin, author);
                library.addBook(id, title, author);
                break;
            case 2:
                std::cout << "Enter book ID to issue: ";
                std::cin >> id;
                library.issueBook(id);
                break;
            case 3:
                std::cout << "Enter book ID to return: ";
                std::cin >> id;
                library.returnBook(id);
                break;
            case 4:
                library.displayBooks();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}