#ifndef _LIBRARYSERVICE_H_
#define _LIBRARYSERVICE_H_
#include "repositories/IBookRepository.h"
#include "repositories/IUserRepository.h"
#include "repositories/IBorrowRepository.h"


class LibraryService {
    private:
    IBookRepository* bookRepo;
    IUserRepository* userRepo;
    IBorrowRepository* borrowRepo;

    public:

    LibraryService(IBookRepository* b, IUserRepository* u, IBorrowRepository* r);

    void load();
    void save();

    bool borrowBook(int userId, int bookId);
    bool returnBook(int userId, int bookId);
};
#endif