#include "models/BorrowRecord.h"

BorrowRecord::BorrowRecord() {
    this->userId = 0;
    this->bookId = 0;
    this->borrowDate = "";
    this->returnDate = "";
    this->returned = false;
}
BorrowRecord::BorrowRecord(int userId, int bookId, string borrowDate, string returnDate, bool returned) {
    this->userId = userId;
    this->bookId = bookId;
    this->borrowDate = borrowDate;
    this->returnDate = returnDate;
    this->returned = returned;
}

int BorrowRecord::getUserId() const {
    return this->userId;
}

int BorrowRecord::getBookId() const {
    return this->bookId;
}

string BorrowRecord::getBorrowDate() const {
    return this->borrowDate;
}

string BorrowRecord::getReturnDate() const {
    return this->returnDate;
}

bool BorrowRecord::isReturned() const {
    return this->returned;
}

void BorrowRecord::setReturned(bool r) {
    returned = r;
}

void BorrowRecord::setReturnDate(string date) {
    this->returnDate = date;
}

string BorrowRecord::toCSV() const {
    stringstream ss;
    ss << userId << "," << bookId << "," << borrowDate << "," << returnDate << "," << returned;
    return ss.str();
}


BorrowRecord BorrowRecord::readFromCSV(const std::string& line) {

    stringstream ss(line);
    string item, borrowDate, returnDate;
    int uid, bid; bool r;

    getline(ss, item, ','); uid = stoi(item);
    getline(ss, item, ','); bid = stoi(item);
    getline(ss, borrowDate, ',');
    getline(ss, returnDate, ',');
    getline(ss, item); r = stoi(item);

    return BorrowRecord(uid, bid, borrowDate, returnDate, r);
}

void BorrowRecord::display() {
    cout << ">>\n";
    cout << "User ID: " << this->userId 
         << "\nID sach muon: " << this->bookId
         << "\nNgay muon: " << this->borrowDate
         << "\nNgay tra: " << this->returnDate << '\n';
}

