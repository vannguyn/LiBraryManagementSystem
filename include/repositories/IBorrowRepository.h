#ifndef _IBORRROWREPOSITORY_H_
#define _IBORRROWREPOSITORY_H_
#include <vector>
#include "models/BorrowRecord.h"
class IBorrowRepository {
    public:

    virtual void load() = 0;
    virtual void save() = 0;
    virtual std::vector<BorrowRecord>& getAll() = 0;
    virtual void add(const BorrowRecord& record) = 0;
    virtual ~IBorrowRepository() = default;
};
#endif