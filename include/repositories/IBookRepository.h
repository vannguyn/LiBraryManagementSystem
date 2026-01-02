#ifndef _IBOOKREPOSITORY_H_
#define _IBOOKREPOSITORY_H_
#include <vector>
#include "models/Book.h"

class IBookRepository {
    public:
    
    virtual void load() = 0;
    virtual void save() = 0;
    virtual vector<Book>& getAll() = 0;
    virtual Book* findById(int id) = 0;
    virtual void add(const Book& b) = 0;
    virtual void remove(int id) = 0;
    virtual ~IBookRepository() = default;
};
#endif