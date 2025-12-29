#ifndef _USER_UI_H
#define _USER_UI_H

#include "services/LibraryService.h"

class UserUI {
    private:
    LibraryService& service;

    public:
    UserUI(LibraryService& service);
    void run();
};

#endif