#include <cassert>
#include <iostream>
#include "services/LibraryService.h"
#include "repositories/BookRepository.h"
#include "repositories/UserRepository.h"
#include "repositories/BorrowRepository.h"

using namespace std;

void testLogin() {
    BookRepository bookRepo;
    UserRepository userRepo;
    BorrowRepository borrowRepo;

    userRepo.add(User(1, "Alice"));
    userRepo.add(User(2, "Bob"));

    LibraryService service(&bookRepo, &userRepo, &borrowRepo);

    User* u = service.login(1);
    assert(u != nullptr);
    assert(u->getName() == "Alice");

    assert(service.login(999) == nullptr);
    cout << "testLogin passed\n";
}

void testBorrowAndReturn() {
    BookRepository bookRepo;
    UserRepository userRepo;
    BorrowRepository borrowRepo;

    bookRepo.add(Book(1, "C++", "Bjarne", 2));
    userRepo.add(User(1, "Alice"));

    LibraryService service(&bookRepo, &userRepo, &borrowRepo);

    bool ok = service.borrowBook(1, 1, "2025-01-01");
    assert(ok == true);
    assert(bookRepo.findById(1)->getQuantity() == 1);

    auto history = service.getBorrowHistory(1);
    assert(history.size() == 1);
    assert(history[0].isReturned() == false);

    ok = service.returnBook(1, 1, "2025-01-10");
    assert(ok == true);
    assert(bookRepo.findById(1)->getQuantity() == 2);

    history = service.getBorrowHistory(1);
    assert(history[0].isReturned() == true);

    cout << "testBorrowAndReturn passed\n";
}

void testBorrowFail() {
    BookRepository bookRepo;
    UserRepository userRepo;
    BorrowRepository borrowRepo;

    bookRepo.add(Book(1, "OS", "Tanenbaum", 0));
    userRepo.add(User(1, "Alice"));

    LibraryService service(&bookRepo, &userRepo, &borrowRepo);

    bool ok = service.borrowBook(1, 1, "2025-01-01");
    assert(ok == false);

    cout << "testBorrowFail passed\n";
}

int main() {
    testLogin();
    testBorrowAndReturn();
    testBorrowFail();

    cout << "\nALL LibraryService tests PASSED\n";
    return 0;
}
