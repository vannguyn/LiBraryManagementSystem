#include "ui/UserUI.h"
#include <iostream>

UserUI::UserUI(LibraryService &service)
    : service(service) {}

void UserUI::run() {
    int userId;
    cout << "Nhap ID nguoi dung: "; cin >> userId;
    while(true) {
        cout << "=========== MENU ===========\n";
        cout << "0. Thoat chuong trinh.\n";
        cout << "1. Xem danh sach sach trong thu vien.\n";
        cout << "2. Muon sach.\n";
        cout << "3. Tra sach.\n";
        cout << "4. Xem danh sach sach da muon tu thu vien.\n";
        int choice; 
        cout << "Nhap lua chon cua ban: "; cin >> choice;
        if(choice == 0) {
            cout << "Thoat chuong trinh.\n";
            break;
        }
        if(choice == 1) {
            cout << "\n------------- DANH SACH SACH -------------\n";
            for(auto& book : service.getAvailableBooks()) {
                cout << book.getId() << "-" << book.getAuthor() << '\n';
            }
        }
        if(choice == 2) {
            int bookId;
            string date;
            cout << "Nhap ID sach muon: "; cin >> bookId;
            cout << "Nhap ngay muon sach (nhap theo dinh dang dd-mm-yy): "; cin >> date;
            if(service.borrowBook(userId, bookId, date)) {
                cout << "Muon sach thanh cong.\n";
            } else {
                cout << "Muon sach khong thanh cong, vui long thu lai.\n";
            }
        }
        if(choice == 3) {
            int bookId;
            string date;
            cout << "Nhap ID sach tra: "; cin >> bookId;
            cout << "Nhap ngay tra sach (nhap theo dinh dang dd-mm-yy): "; cin >> date;
            if(service.returnBook(userId, bookId, date)) {
                cout << "Tra sach thanh cong.\n";
            } else {
                cout << "Tra sach khong thanh cong, vui long thu lai.\n";
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