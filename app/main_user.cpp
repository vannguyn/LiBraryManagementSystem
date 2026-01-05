#include "repositories/BookRepository.h"
#include "repositories/UserRepository.h"
#include "repositories/BorrowRepository.h"
#include "services/LibraryService.h"
#include "ui/UserUI.h"

int main() {
    BookRepository bookRepo;
    UserRepository userRepo;
    BorrowRepository borrowRepo;

    LibraryService service(&bookRepo, &userRepo, &borrowRepo);
    service.loadData();

    UserUI app(service);
    app.run();
    
    return 0;
}