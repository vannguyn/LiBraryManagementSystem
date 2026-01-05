#include "services/LibraryService.h"

LibraryService::LibraryService(IBookRepository* bookRepo, IUserRepository* userRepo, IBorrowRepository* borrowRepo) 
: bookRepo(bookRepo), userRepo(userRepo), borrowRepo(borrowRepo) {}

void LibraryService::loadData() {
    bookRepo->load();
    userRepo->load();
    borrowRepo->load();
}
bool LibraryService::findBook(int bookId) {
    return bookRepo->findById(bookId) != nullptr;
}

bool LibraryService::findUser(int userId) {
    return userRepo->findById(userId) != nullptr;
}

// Users 
User* LibraryService::login(int userId) {
    return userRepo->findById(userId);
}

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
    vector<BorrowRecord> history;
    for(auto& record : borrowRepo->getAll()) {
        if(record.getUserId() == userId) {
            history.push_back(record);
        }
    }
    return history;
}

bool LibraryService::borrowBook(int userId, int bookId, string borrowDate) {
    Book* book = bookRepo->findById(bookId);
    if(book && book->getQuantity() > 0) {
        book->setQuantity(book->getQuantity() - 1);
        bookRepo->save();

        BorrowRecord record(userId, bookId, borrowDate, "N/A", false);
        borrowRepo->add(record);
        return true;
    }
    return false;
}

bool LibraryService::returnBook(int userId, int bookId, string returnDate) {
    vector<BorrowRecord>& records = borrowRepo->getAll();
    for(auto& record : records) {
        if(record.getUserId() == userId && record.getBookId() == bookId && !record.isReturned()) {
            record.setReturned(true);
            record.setReturnDate(returnDate);
            borrowRepo->save();

            Book* book = bookRepo->findById(bookId);
            if(book) {
                book->setQuantity(book->getQuantity() + 1);
                bookRepo->save();
            }
            return true;
        }
    }
    return false;
}

void LibraryService::displayInfoUser(int id) {
    User* user = login(id);
    if(!user) return;
    cout << " >> User ID: " << user->getId() << " - " << "Name: " << user->getName() << '\n';
}
// Admin
void LibraryService::addBook(const Book& book) {
    bookRepo->add(book);
}

bool LibraryService::updateBook(const Book& book) {
    Book* oldBook = bookRepo->findById(book.getId());
    if(!oldBook) return false;

    if(book.getAuthor() != "") oldBook->setAuthor(book.getAuthor());
    oldBook->setQuantity(book.getQuantity());
    if(book.getTitle() != "") oldBook->setTitle(book.getTitle());

    bookRepo->save();
    return true;
}

void LibraryService::removeBook(int bookId) {
    bookRepo->remove(bookId);
}

bool LibraryService::updateBookQuantity(int bookId, int newQuantity){
    Book* book = bookRepo->findById(bookId);
    if(!book) return false;

    book->setQuantity(newQuantity);
    return true;
}

void LibraryService::addUser(const User& user) {
    userRepo->add(user);
}

bool LibraryService::updateUser(const User& user) {
    User* oldUser = userRepo->findById(user.getId());
    if(!oldUser) return false;

    oldUser->setName(user.getName());

    userRepo->save();
    return true;
}

void LibraryService::removeUser(int userId) {
    userRepo->remove(userId);
}

vector<BorrowRecord>& LibraryService::getAllBorrowRecords() {
    return borrowRepo->getAll();
}

vector<Book>& LibraryService::getAllBooks() {
    return bookRepo->getAll();
}

void LibraryService::printStatistics() {
    auto& allBooks = bookRepo->getAll();
    auto& allRecords = borrowRepo->getAll();
    
    int totalBookTitles = allBooks.size(); // Số đầu sách
    int totalBookStock = 0;                // Tổng số lượng sách trong kho
    for (const auto& b : allBooks) totalBookStock += b.getQuantity();

    int totalBorrowedActive = 0;           // Số sách đang bị mượn (chưa trả)
    map<int, int> bookPopularity;          // Đếm số lần sách được mượn (BookID -> Count)
    map<int, int> userActivity;            // Đếm số lần user mượn (UserID -> Count)

    for (const auto& rec : allRecords) {
        // Thống kê tần suất mượn (bất kể đã trả hay chưa)
        bookPopularity[rec.getBookId()]++;
        userActivity[rec.getUserId()]++;

        if (!rec.isReturned()) {
            totalBorrowedActive++;
        }
    }
    // Danh sách sách
    vector<Book>& books = getAllBooks();
    cout << "\n------------------------------------ DANH SACH SACH ------------------------------------\n";
        
    cout << left << setw(8)  << "ID"
        << left << setw(40) << "Ten Sach"
        << left << setw(30) << "Tac Gia"
        << right << setw(10) << "So Luong" << '\n';
        
    cout << string(90, '-') << '\n';
    for (auto& book : books) {
        cout << left << setw(8)  << book.getId()
            << left << setw(40) << book.getTitle()
            << left << setw(30) << book.getAuthor()
            << right << setw(10) << book.getQuantity() << '\n';
    }
    cout << string(90, '-') << '\n';

    // Giao diện thống kê
    cout << string(60, '=');
    cout << " Bao cao thong ke ";
    cout << string(60, '=') << "\n\n";

    // Tổng quan
    cout << "[A] Tong quan:\n";
    cout << " + So dau sach quan ly:      " << totalBookTitles << "\n";
    cout << " + Tong so luong sach ton:   " << totalBookStock << "\n";
    cout << " + So phieu muon tich luy:   " << allRecords.size() << "\n";
    cout << " + Sach dang duoc muon:      " << totalBorrowedActive << " (Chua tra)\n\n";

    // Danh sách sách đã mượn
    cout << "[B] Danh sach sach duoc muon(chua tra):\n";
    if (totalBorrowedActive == 0) {
        cout << "   >> Hien tai khong co sach nao dang duoc muon.\n";
    } else {
        cout << left << setw(10) << "User ID" << setw(20) << "Nguoi muon" 
             << setw(10) << "Book ID" << setw(20) << "Ngay muon" << endl;
        cout << string(60, '-') << endl;

        for (const auto& rec : allRecords) {
            if (!rec.isReturned()) {
                User* u = userRepo->findById(rec.getUserId());
                string userName = (u) ? u->getName() : "Unknown";
                cout << left << setw(10) << rec.getUserId() 
                     << setw(20) << userName
                     << setw(10) << rec.getBookId() 
                     << setw(20) << rec.getBorrowDate() << endl;
            }
        }
    }
    cout << "\n";

    // Top user
    // Chuyển Map sang Vector để sort
    vector<pair<int, int>> sortedUsers(userActivity.begin(), userActivity.end());
    // Sort giảm dần theo số lượng mượn
    sort(sortedUsers.begin(), sortedUsers.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    cout << "[C] Top 3 nguoi muon tich cuc:\n";
    if (sortedUsers.empty()) cout << "   >> Chua co du lieu.\n";
    else {
        int limit = min((int)sortedUsers.size(), 3);
        for (int i = 0; i < limit; ++i) {
            int uid = sortedUsers[i].first;
            int count = sortedUsers[i].second;
            User* u = userRepo->findById(uid);
            string name = (u) ? u->getName() : "Unknown";
            cout << "   " << (i + 1) << ". " << name << " (User ID: " << uid << ") - " << count << " luot muon.\n";
        }
    }
    cout << "\n";

    // --- PHẦN D: TOP BOOK (SÁCH HOT) ---
    vector<pair<int, int>> sortedBooks(bookPopularity.begin(), bookPopularity.end());
    sort(sortedBooks.begin(), sortedBooks.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    cout << "[D] TOP 3 SACH DUOC MUON NHIEU NHAT:\n";
    if (sortedBooks.empty()) cout << "   >> Chua co du lieu.\n";
    else {
        int limit = min((int)sortedBooks.size(), 3);
        for (int i = 0; i < limit; ++i) {
            int bid = sortedBooks[i].first;
            int count = sortedBooks[i].second;
            Book* b = bookRepo->findById(bid);
            string title = (b) ? b->getTitle() : "Unknown Book";
            cout << "   " << (i + 1) << ". " << title << " (ID: " << bid << ") - " << count << " lan duoc muon.\n";
        }
    }
    cout << string(60, '=') << "\n";
}