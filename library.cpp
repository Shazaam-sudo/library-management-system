#include "library.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

bool Library::addBook(const Book& book) 
{
    const int bookId = book.getId();

    //Now check if the book is already present
    if(booksMap.find(bookId) != booksMap.end()) {
        return false;
    }

    booksMap.emplace(bookId, book);
    return true;
}

bool Library::removeBook(int id) 
{
    auto it = booksMap.find(id);

    //Check if book is present or not in library
    if(it == booksMap.end())
        return false;

    //Now check if book is issued or not
    const Book& currentBook = it -> second;
    
    if(currentBook.getIssuedStatus())
        return false;

    booksMap.erase(it);
    return true;
}

const Book* Library::searchBook(int id) const
{
    auto it = booksMap.find(id);

    if(it == booksMap.end())
    {
        return nullptr;
    }

    return &(it -> second);
}

Book* Library::searchBook(int id)
{
    auto it = booksMap.find(id);

    if(it == booksMap.end())
    {
        return nullptr;
    }

    return &(it -> second);
}

bool Library::displayBooks() const
{
    if(booksMap.empty())
    {
        return false;
    }

    for(const auto& it : booksMap)
    {
        const Book& currentBook = it.second;

        std::cout<<"Id: "<<currentBook.getId()<<std::endl;
        std::cout<<"Title: "<<currentBook.getTitle()<<std::endl;
        std::cout<<"Author: "<<currentBook.getAuthor()<<std::endl;
        if(currentBook.getIssuedStatus())
        {
            std::cout<<"Status: Not Available"<<std::endl;
        }else
        {
            std::cout<<"Status: Available"<<std::endl;
        }

        std::cout<<"------------------------------------------------"<<std::endl;
    }

    return true;
}

bool Library::issueBook(int id)
{
    Book* currentBook = searchBook(id);

    if(currentBook == nullptr)
    {
        return false;
    }

    return currentBook -> issueBook();
}

bool Library::returnBook(int id)
{
    Book* currentBook = searchBook(id);

    if(currentBook == nullptr)
    {
        return false;
    }

    return currentBook -> returnBook();
}

bool Library::loadBooksFromFile(const std::string& filename)
{
    //open file in read mode
    std::ifstream file(filename);

    //File doesn't exist means it is first time case
    if(!file)
    {
        return true;
    }

    std::string line;

    while(std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string idStr;
        std::string title;
        std::string author;
        std::string status;

        std::getline(ss, idStr, '|');
        std::getline(ss, title, '|');
        std::getline(ss, author, '|');
        std::getline(ss, status, '|');

        int id = stoi(idStr);
        bool isIssued = (status == "1");

        Book book(id, title, author, isIssued);
        booksMap.emplace(id, book);
    }

    return true;
}

bool Library::saveBooksToFile(const std::string& filename) const
{
    //open file in write mode
    std::ofstream file(filename);

    if(!file)
    {
        return false;
    }

    for(const auto& it : booksMap)
    {
        const Book& currentBook = it.second;

        file << currentBook.getId()
             << '|'
             << currentBook.getTitle()
             << '|'
             << currentBook.getAuthor()
             <<'|'
             << currentBook.getIssuedStatus()
             << '\n';
    }

    return true;
}