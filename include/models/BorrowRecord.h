#ifndef _BORROWRECORD_H_
#define _BORROWRECORD_H_
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class BorrowRecord {
    private:
    int userId;
    int bookId;
    string date;
    bool returned;

    public:
    // Constructor
    BorrowRecord();
    BorrowRecord(int userId, int bookId, string date, bool returned);

    // Getter
    int getUserId() const;
    int getBookId() const;
    string getDate() const;
    bool isReturned() const;

    // Setter
    void setReturned(bool r);


    string toCSV() const;
    static BorrowRecord readFromCSV(const string& line);
    
    // Display
    void display();
};
#endif