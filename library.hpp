#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.hpp"
#include <unordered_map>

class Library 
{
private:
    std::unordered_map<int, Book> booksMap;

public:
    bool addBook(const Book& book);
    bool removeBook(int id);
    const Book* searchBook(int id) const;
    Book* searchBook(int id);
    bool displayBooks() const;
    bool issueBook(int id);
    bool returnBook(int id);
    bool loadBooksFromFile(const std::string& filename);
    bool saveBooksToFile(const std::string& filename) const;
};

#endif