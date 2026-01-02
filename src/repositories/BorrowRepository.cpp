#include "repositories/BorrowRepository.h"

void BorrowRepository::load() {
    records.clear();
    ifstream file("data/borrows.csv");
    string line;
    while (getline(file, line)) {
        records.push_back(BorrowRecord::readFromCSV(line));
    }
}

void BorrowRepository::save() {
    ofstream file("data/borrows.csv");
    for(auto& record : records) {
        file << record.toCSV() << '\n';
    } 
}

vector<BorrowRecord>& BorrowRepository::getAll() {
    return records;
}

void BorrowRepository::add(const BorrowRecord& record) {
    records.push_back(record);
}