#include "models/User.h"

User::User() {
    this->id = 0;
    this->name = "";
}

User::User(int id, string name) {
    this->id = id;
    this->name = name;
}

int User::getId() const {
    return this->id;
}

string User::getName() const {
    return this->name;
}