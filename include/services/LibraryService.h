#ifndef _LIBRARYSERVICE_H_
#define _LIBRARYSERVICE_H_
#include "repositories/IBookRepository.h"
#include "repositories/IUserRepository.h"
#include "repositories/IBorrowRepository.h"
#include <map>
#include <algorithm>
#include <iomanip>

class LibraryService {
    private:
    IBookRepository* bookRepo;
    IUserRepository* userRepo;
    IBorrowRepository* borrowRepo;

    public:
    // Constructor
    LibraryService(IBookRepository* bookRepo, IUserRepository* userRepo, IBorrowRepository* borrowRepo);

    // Common
    void loadData();
    bool findBook(int bookId);
    bool findUser(int userId);
    // User
    User* login(int userId);
    vector<Book> getAvailableBooks();
    vector<BorrowRecord> getBorrowHistory(int userId);
    bool borrowBook(int userId, int bookId, string borrowDate);
    bool returnBook(int userId, int bookId, string returnDate);
    void displayInfoUser(int id);

    // Admin
    vector<Book>& getAllBooks();
    void addBook(const Book& book);
    bool updateBook(const Book& book);
    void removeBook(int bookId);
    bool updateBookQuantity(int bookId, int newQuantity);

    void addUser(const User& user);
    bool updateUser(const User& user);
    void removeUser(int userId);

    vector<BorrowRecord>& getAllBorrowRecords();

    // Display
    void printStatistics();
};
#endif