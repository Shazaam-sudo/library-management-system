#ifndef BOOK_H
#define BOOK_H

#include<string>

class Book 
{
private:
    int id;
    std::string title;
    std::string author;
    bool isIssued;

public:
    Book(int _id, const std::string& _title, const std::string& _author, bool _isIssued = false);
    int getId() const;
    const std::string& getTitle() const;
    const std::string& getAuthor() const;
    bool getIssuedStatus() const;
    bool issueBook();
    bool returnBook();
};

#endif