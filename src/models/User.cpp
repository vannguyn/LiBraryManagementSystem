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

string User::toCSV() const {
    stringstream ss;
    ss << this->id << "," << this->name;
    return ss.str();
}

User User::readFromCSV(const string& line) {
    stringstream ss(line);
    string item, name;
    int id;
    getline(ss, item, ','); id = stoi(item);
    getline(ss, name, ',');
    return User(id, name);
}