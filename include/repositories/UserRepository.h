#ifndef _USERREPOSITORY_H_
#define _USERREPOSITORY_H_
#include "repositories/IUserRepository.h"
#include <fstream>
class UserRepository : public IUserRepository {
    private:
    vector<User> users;

    public:
    void load() override;
    void save() override;
    vector<User>& getAll() override;
    User* findById(int id) override;
};
#endif