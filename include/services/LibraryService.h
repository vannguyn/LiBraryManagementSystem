#ifndef _LIBRARYSERVICE_H_
#define _LIBRARYSERVICE_H_
#include "repositories/IBookRepository.h"
#include "models/BorrowRecord.h"
#include <vector>
class LibraryService {
    private:
    IBookRepository *bookRepo;
    vector<BorrowRecord> borrows;

    public:
    // Constructor
    LibraryService(IBookRepository* bookRepo);

    vector<Book> getAvailableBooks();
    vector<BorrowRecord> getBorrowHistory(int userId);
    bool borrowBook(int userId, int bookId, string date);
    bool returnBook(int userId, int bookId);
};
#endif