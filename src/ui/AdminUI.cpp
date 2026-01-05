#include "ui/AdminUI.h"
#include <iostream>

AdminUI::AdminUI(LibraryService& s) : service(s) {}

void AdminUI::run() {
    while(true) {
        cout << "\n================ Library Admin App ===============\n";
        cout << "1. Them sach.\n";
        cout << "2. Sua sach.\n";
        cout << "3. Xoa sach.\n";
        cout << "4. Cap nhap so luong sach.\n";
        cout << "5. Them user.\n";
        cout << "6. Sua user.\n";
        cout << "7. Xoa user.\n";
        cout << "8. Xem danh sach phieu muon.\n";
        cout << "9. In thong ke muon sach.\n";
        cout << "0. Thoat chuong trinh.\n";

        int choice;
        cout << "Nhap lua chon cua ban: "; cin >> choice;
        
        switch(choice) {
            case 0: {
                cout << "Thoat chuong trinh.\n";
                return;
            }
            case 1: {
                int bookId, quantity;
                string title, author;
                cout << "Nhap ID sach: "; cin >> bookId;
                cin.ignore();
                if(service.findBook(bookId)) {
                    cout << " >> ID sach da ton tai.\n";
                    break;
                }
                cout << "Nhap ten sach: "; getline(cin, title);
                cout << "Nhap ten tac gia: "; getline(cin, author);
                cout << "Nhap so luong: "; cin >> quantity;
                service.addBook(Book(bookId, title, author, quantity));
                cout << " >> Them sach thanh cong.\n";
                break;
            }
            case 2: {
                int bookId;
                cout << "Nhap ID sach can thay doi: "; cin >> bookId;
                cin.ignore();
                if(!service.findBook(bookId)) {
                    cout << " >> Khong tim thay sach.\n";
                    break;
                }
                string newTitle, newAuthor;
                cout << "Nhap ten sach moi (Neu khong thay doi ten thi khong can nhap, nhan Enter): "; getline(cin, newTitle);
                cout << "Nhap ten tac gia moi (Neu khong thay doi tac gia thi khong can nhap, nhan Enter): "; getline(cin, newAuthor);
                int newQuantity;
                cout << "Nhap so luong sach: "; cin >> newQuantity;
                if(service.updateBook(Book(bookId, newTitle, newAuthor, newQuantity))) {
                    cout << " >> Cap nhap thanh cong.\n";
                } else {
                    cout << " >> Cap nhap khong thanh cong.\n";
                }
                break;
            }
            case 3: {
                int bookId;
                cout << "Nhap ID sach can xoa: "; cin >> bookId;
                if(!service.findBook(bookId)) {
                    cout << " >> Khong tim thay sach.\n";
                    break;
                }
                service.removeBook(bookId);
                cout << " >> Xoa sach thanh cong.\n";
                break;
            }
            case 4: {
                int bookId, newQuantity;
                cout << "ID sach: "; cin >> bookId;
                cin.ignore();
                if(!service.findBook(bookId)) {
                    cout << " >> Khong tim thay sach.\n";
                    break;
                }
                cout << "So luong sach moi: "; cin >> newQuantity;
                service.updateBookQuantity(bookId, newQuantity);
                cout << " >> Cap nhap thanh cong.\n";
                break;
            }
            case 5: {
                int userId;
                string name;
                cout << "ID user: "; cin >> userId;
                cin.ignore();
                if(service.findUser(userId)) {
                    cout << " >> Da ton tai user.\n";
                    break;
                }
                cout << "Ten user: "; getline(cin, name);
                service.addUser(User(userId, name));
                cout << " >> Them user thanh cong.\n";
                break;
            }
            case 6: {
                int userId;
                string name;
                cout << "ID user can thay doi: "; cin >> userId;
                cin.ignore();
                if(!service.findUser(userId)) {
                    cout << " >> Khong tim thay user.\n";
                    break;
                }
                cout << "Ten user moi: "; getline(cin, name);
                if(service.updateUser(User(userId, name))) {
                    cout << " >> Cap nhap user thanh cong.\n";
                } else {
                    cout << " >> Cap nhap user khong thanh cong.\n";
                }
                break;
            }
            case 7: {
                int userId;
                cout << "ID user can xoa: "; cin >> userId;
                if(!service.findUser(userId)) {
                    cout << " >> Khong tim thay user.\n";
                    break;
                }
                service.removeUser(userId);
                cout << " >> Xoa nguoi dung thanh cong.\n";
                break;
            }
            case 8: {
                vector<BorrowRecord>& list = service.getAllBorrowRecords();
                if (list.empty()) {
                    cout << "Hien tai khong co phieu muon nao.\n";
                    break;
                }

                cout << "\n----------------------- DANH SACH PHIEU MUON -----------------------\n";
                cout << left << setw(10) << "UserID"
                     << left << setw(10) << "BookID"
                     << left << setw(15) << "Ngay Muon"
                     << left << setw(12) << "Trang Thai" << '\n';

                cout << string(60, '-') << '\n';

                for (auto& r : list) {
                    cout << left << setw(10) << r.getUserId()
                         << left << setw(10) << r.getBookId()
                         << left << setw(15) << r.getBorrowDate()
                         << left << setw(12) << (r.isReturned() ? "Da tra" : "Dang muon") << '\n';
                }

                cout << string(60, '-') << '\n';
                break;
            }
            case 9: {
                service.printStatistics();
                break;
            }
            default:
                break;
        }
    }
}