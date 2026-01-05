#include <cassert>
#include <iostream>
#include "repositories/BookRepository.h"
#include "repositories/UserRepository.h"
#include "repositories/BorrowRepository.h"
#include "models/Book.h"
#include "models/User.h"
#include "models/BorrowRecord.h"

using namespace std;

void testBookRepository() {
    BookRepository repo;

    repo.add(Book(1, "CPP", "Bjarne", 5));
    repo.add(Book(2, "DSA", "CLRS", 3));

    assert(repo.getAll().size() == 2);

    Book* b = repo.findById(1);
    assert(b != nullptr);
    assert(b->getTitle() == "CPP");

    repo.remove(1);
    assert(repo.findById(1) == nullptr);

    cout << "[PASS] BookRepository\n";
}

void testUserRepository() {
    UserRepository repo;

    repo.add(User(1, "Alice"));
    repo.add(User(2, "Bob"));

    assert(repo.getAll().size() == 2);
    assert(repo.findById(2)->getName() == "Bob");

    repo.remove(1);
    assert(repo.findById(1) == nullptr);

    cout << "[PASS] UserRepository\n";
}

void testBorrowRepository() {
    BorrowRepository repo;

    repo.add(BorrowRecord(1, 2, "2025-01-01", "", false));
    repo.add(BorrowRecord(2, 1, "2025-01-02", "", true));

    assert(repo.getAll().size() == 2);

    cout << "[PASS] BorrowRepository\n";
}

int main() {
    testBookRepository();
    testUserRepository();
    testBorrowRepository();

    cout << "=== ALL REPOSITORY TESTS PASSED ===\n";
    return 0;
}
