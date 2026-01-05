#include "ui/UserUI.h"
#include <iostream>

UserUI::UserUI(LibraryService &service)
    : service(service) {}

void UserUI::run() {
    int userId;
    cout << "Nhap ID nguoi dung: "; cin >> userId;
    if(service.login(userId) == nullptr) {
        cout << " >> Nguoi dung khong ton tai. Vui long them tai khoan o admin.\n";
    }
    else {
        service.displayInfoUser(userId);
        while(true) {
            cout << "====================== MENU ======================\n";
            cout << "1. Xem danh sach sach trong thu vien.\n";
            cout << "2. Muon sach.\n";
            cout << "3. Tra sach.\n";
            cout << "4. Xem danh sach sach da muon tu thu vien.\n";
            cout << "0. Thoat chuong trinh.\n";
            int choice; 
            cout << "Nhap lua chon cua ban: "; cin >> choice;
            if(choice == 0) {
                cout << "Thoat chuong trinh.\n";
                break;
            }
            if(choice == 1) {
                vector<Book> books = service.getAvailableBooks();
                if(books.empty()) {
                    cout << "\n Hien tai khong co sach nao trong thu vien.\n";
                } else {
                    cout << "\n-------------------------- DANH SACH SACH --------------------------\n";
        
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
                }
            }
            if(choice == 2) {
                int bookId;
                string date;
                cout << "Nhap ID sach muon: "; cin >> bookId;
                cout << "Nhap ngay muon sach (nhap theo dinh dang dd-mm-yy): "; cin >> date;
                if(service.borrowBook(userId, bookId, date)) {
                    cout << " >> Muon sach thanh cong.\n";
                } else {
                    cout << " >> Muon sach khong thanh cong, vui long thu lai.\n";
                }
            }
            if(choice == 3) {
                int bookId;
                string date;
                cout << "Nhap ID sach tra: "; cin >> bookId;
                cout << "Nhap ngay tra sach (nhap theo dinh dang dd-mm-yy): "; cin >> date;
                if(service.returnBook(userId, bookId, date)) {
                    cout << " >> Tra sach thanh cong.\n";
                } else {
                    cout << " >> Tra sach khong thanh cong, vui long thu lai.\n";
                }
            }
            if(choice == 4) {
                cout << "Danh sach sach nguoi dung da muon: \n";
                for(auto& book : service.getBorrowHistory(userId)) {
                    book.display();
                }
            }
        }
    }
}