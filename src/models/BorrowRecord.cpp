#include "models/BorrowRecord.h"

BorrowRecord::BorrowRecord(int userId, int bookId, string date, bool returned) {
    this->userId = userId;
    this->bookId = bookId;
    this->date = date;
    this->returned = returned;
}

int BorrowRecord::getUserId() const {
    return this->userId;
}

int BorrowRecord::getBookId() const {
    return this->bookId;
}

string BorrowRecord::getDate() const {
    return this->date;
}

bool BorrowRecord::isReturned() const {
    return this->returned;
}

void BorrowRecord::markReturned() {
    returned = true;
}

void BorrowRecord::display() {
    cout << "User ID: " << this->userId << " - " << this->bookId << " - " << this->date << '\n';
}