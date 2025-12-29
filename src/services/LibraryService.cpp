#include "services/LibraryService.h"

LibraryService::LibraryService(IBookRepository* bookRepo) : bookRepo(bookRepo) {}

vector<Book> LibraryService::getAvailableBooks() {
    vector<Book> availableBooks;
    for(auto& book : bookRepo->getAll()) {
        if(book.getQuantity() > 0) {
            availableBooks.push_back(book);
        }
    }
    return availableBooks;
}

vector<BorrowRecord> LibraryService::getBorrowHistory(int userId) {
    vector<BorrowRecord> result;
    for(const auto& record : borrows) {
        if(record.getUserId() == userId) {
            result.push_back(record);
        }
    }
    return result;
}
bool LibraryService::borrowBook(int userId, int bookId, string date) {
    vector<Book> books = bookRepo->getAll();
    for(auto& b : books) {
        if(b.getId() == bookId && b.getQuantity() > 0) {
            b.setQuantity(b.getQuantity() - 1);
            borrows.emplace_back(userId, bookId, date, false);
            bookRepo->save(books);
            return true;
        }
    }
    return false;
}

bool LibraryService::returnBook(int userId, int bookId) {
    for(auto& br : borrows) {
        if(br.getUserId() == userId && br.getBookId() == bookId && !br.isReturned()) {
            br.markReturned();
            return true;
        }
    }
    return false;
}