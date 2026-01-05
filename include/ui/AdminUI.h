#ifndef _ADMIN_UI_H
#define _ADMIN_UI_H
#include "services/LibraryService.h"

class AdminUI {
    private:
    LibraryService& service;
    
    public:
    AdminUI(LibraryService& s);
    void run();
};
#endif