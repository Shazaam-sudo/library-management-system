#include "library.hpp"
#include "book.hpp"
#include "utils.hpp"
#include <limits>
#include <climits>
#include <iostream>
#include "logger.hpp"

int main()
{
    Library library;
    library.loadBooksFromFile("books.txt");
    int choice = 0;

    do
    {
        std::cout<<std::endl;
        std::cout<<"========= Library Management ========="<<std::endl;
        std::cout<<"1. Add Book"<<std::endl;
        std::cout<<"2. Remove Book"<<std::endl;
        std::cout<<"3. Search Book"<<std::endl;
        std::cout<<"4. Display Books"<<std::endl;
        std::cout<<"5. Issue Book"<<std::endl;
        std::cout<<"6. Return Book"<<std::endl;
        std::cout<<"7. Exit"<<std::endl;
        std::cout<<std::endl;

        choice = getValidInteger("Enter choice: ", 1, 7);

        std::cout<<std::endl;

        switch(choice)
        {
            case 1:
            {
                int id = getValidInteger("Enter the id of the book: ", 1, INT_MAX);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::string title = getValidString("Enter the title of the book: ");
                std::string author = getValidString("Enter the author of the book: ");

                Book book(id, title, author);

                if(library.addBook(book))
                {
                    Logger::info("Book added successfully");
                    //std::cout<<"Book added successfully"<<std::endl;
                }
                else
                {
                    Logger::warning("Unable to add book");
                    //std::cout<<"Unable to add book"<<std::endl;
                }

                break;
            }

            case 2:
            {
                int id = getValidInteger("Enter the id of the book: ", 1, INT_MAX);

                if(library.removeBook(id))
                {
                    Logger::info("Book removed successfully");
                    //std::cout<<"Book removed successfully"<<std::endl;
                }
                else
                {
                    Logger::warning("Unable to remove book");
                    //std::cout<<"Failed to remove book"<<std::endl;
                }

                break;
            }

            case 3:
            {
                int id = getValidInteger("Enter the id of the book: ", 1, INT_MAX);

                const Book* book = library.searchBook(id);

                if(book == nullptr)
                {
                    Logger::warning("Book is not present");
                    //std::cout<<"Book is not present"<<std::endl;
                }
                else
                {
                    std::cout<<"-------------------------"<<std::endl;
                    std::cout<<"Book Found"<<std::endl;
                    std::cout<<"-------------------------"<<std::endl;
                    std::cout<<"Book id: "<<book->getId()<<std::endl;
                    std::cout<<"Book title: "<<book->getTitle()<<std::endl;
                    std::cout<<"Book author: "<<book->getAuthor()<<std::endl;
                    if(book -> getIssuedStatus())
                    {   
                        std::cout<<"Book status: Unavailable"<<std::endl;
                    }
                    else 
                    {
                        std::cout<<"Book status: Available"<<std::endl;
                    }
                    std::cout<<"-------------------------"<<std::endl;
                }

                break;
            }

            case 4:
            {
                if(!library.displayBooks())
                {
                    Logger::info("No books present");
                    //std::cout<<"No books present"<<std::endl;
                }

                break;
            }

            case 5:
            {
                int id = getValidInteger("Enter the id of the book: ", 1, INT_MAX);

                if(library.issueBook(id))
                {
                    Logger::info("Book issued successfully");
                    //std::cout<<"Book issued successfully"<<std::endl;
                }
                else 
                {
                    Logger::warning("Unable to issue book");
                    //std::cout<<"Unable to issue book"<<std::endl;
                }

                break;
            }

            case 6:
            {
                int id = getValidInteger("Enter the id of the book: ", 1, INT_MAX);

                if(library.returnBook(id))
                {
                    Logger::info("Book returned successfully");
                    //std::cout<<"Book returned successfully"<<std::endl;
                }
                else 
                {
                    Logger::warning("Unable to return book");
                    //std::cout<<"Unable to return book"<<std::endl;
                }

                break;
            }

            case 7:
            {
                library.saveBooksToFile("books.txt");
                std::cout << "Exiting..." << std::endl;
                break;
            }       

            default:
            {
                std::cout<<"Invalid input"<<std::endl;
            }
        }
    }while(choice != 7);

    return 0;
}