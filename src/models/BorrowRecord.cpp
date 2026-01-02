#include "models/BorrowRecord.h"

BorrowRecord::BorrowRecord() {
    this->userId = 0;
    this->bookId = 0;
    this->date = "";
    this->returned = false;
}
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

void BorrowRecord::setReturned(bool r) {
    returned = r;
}

string BorrowRecord::toCSV() const {
    stringstream ss;
    ss << userId << "," << bookId << "," << date << "," << returned;
    return ss.str();
}


BorrowRecord BorrowRecord::readFromCSV(const std::string& line) {

    stringstream ss(line);
    string item, date;
    int uid, bid; bool r;

    getline(ss, item, ','); uid = std::stoi(item);
    getline(ss, item, ','); bid = std::stoi(item);
    getline(ss, date, ',');
    getline(ss, item); r = std::stoi(item);

    return BorrowRecord(uid, bid, date, r);
}

void BorrowRecord::display() {
    cout << "User ID: " << this->userId << " - " << this->bookId << " - " << this->date << '\n';
}

