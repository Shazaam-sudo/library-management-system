#include "book.hpp"

Book::Book(int _id, const std::string& _title, const std::string& _author, bool _isIssued) : id(_id), title(_title), author(_author), isIssued(_isIssued)
{

}

int Book::getId() const
{
    return id;
}

const std::string& Book::getTitle() const
{
    return title;
}

const std::string& Book::getAuthor() const
{
    return author;
}

bool Book::getIssuedStatus() const
{
    return isIssued;
}

bool Book::issueBook()
{
    if(isIssued)
        return false;
    
    isIssued = true;
    return true;
}

bool Book::returnBook()
{
    if(!isIssued)
        return false;

    isIssued = false;
    return true;
} 