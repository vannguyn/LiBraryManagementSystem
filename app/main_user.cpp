#include "repositories/BookRepository.h"
#include "services/LibraryService.h"
#include "ui/UserUI.h"

int main()
{
    BookRepository bookRepo("data/books.csv");
    LibraryService service(&bookRepo);
    UserUI ui(service);
    ui.run();
}