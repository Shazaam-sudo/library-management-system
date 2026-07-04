#include "library.hpp"
#include "book.hpp"
#include <limits>
#include <iostream>

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
        std::cin>>choice;
        std::cout<<std::endl;

        switch(choice)
        {
            case 1:
            {
                int id;
                std::string title;
                std::string author;

                std::cout<<"Enter the id of the book: ";
                std::cin>>id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout<<"Enter the title of the book: ";
                std::getline(std::cin, title);

                std::cout<<"Enter the author of the book: ";
                std::getline(std::cin, author);

                Book book(id, title, author);

                if(library.addBook(book))
                {
                    std::cout<<"Book added successfully"<<std::endl;
                }
                else
                {
                    std::cout<<"Unable to add book"<<std::endl;
                }

                break;
            }

            case 2:
            {
                int id;
                std::cout<<"Enter the id of the book to be removed: ";
                std::cin>>id;

                if(library.removeBook(id))
                {
                    std::cout<<"Book removed successfully"<<std::endl;
                }
                else
                {
                    std::cout<<"Failed to remove book"<<std::endl;
                }

                break;
            }

            case 3:
            {
                int id;
                std::cout<<"Enter the id of the book to be searched: ";
                std::cin>>id;

                const Book* book = library.searchBook(id);

                if(book == nullptr)
                {
                    std::cout<<"Book is not present"<<std::endl;
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
                    std::cout<<"No books present"<<std::endl;
                }

                break;
            }

            case 5:
            {
                int id;
                std::cout<<"Enter the id of the book to be issued: ";
                std::cin>>id;

                if(library.issueBook(id))
                {
                    std::cout<<"Book issued successfully"<<std::endl;
                }
                else 
                {
                    std::cout<<"Unable to issue book"<<std::endl;
                }

                break;
            }

            case 6:
            {
                int id;
                std::cout<<"Enter the id of the book to be returned: ";
                std::cin>>id;

                if(library.returnBook(id))
                {
                    std::cout<<"Book returned successfully"<<std::endl;
                }
                else 
                {
                    std::cout<<"Unable to return book"<<std::endl;
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