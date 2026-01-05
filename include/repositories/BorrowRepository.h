#ifndef _BORROWREPOSITORY_H_
#define _BORROWREPOSITORY_H_
#include "repositories/IBorrowRepository.h"
#include <fstream>
#include <algorithm>
class BorrowRepository : public IBorrowRepository {
    private:
    vector<BorrowRecord> records;

    public:
    void load() override;
    void save() override;
    vector<BorrowRecord>& getAll() override;
    void add(const BorrowRecord& record) override;
};
#endif