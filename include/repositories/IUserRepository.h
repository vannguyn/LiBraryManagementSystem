#ifndef _IUSERREPOSITORY_H_
#define _IUSERREPOSITORY_H_
#include <vector>
#include <models/User.h>
class IUserRepository {
    public:
    virtual void load() = 0;
    virtual void save() = 0;
    virtual std::vector<User>& getAll() = 0;
    virtual User* findById(int id) = 0;
    virtual ~IUserRepository() = default;
}
#endif