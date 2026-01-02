#include "repositories/UserRepository.h"

void UserRepository::load() {
    users.clear();
    ifstream file("data/users.csv");
    string line;
    while(getline(file, line)) {
        users.push_back(User::readFromCSV(line));
    }
}

void UserRepository::save() {
    ofstream file("data/users.csv");
    for(auto& user : users) {
        file << user.toCSV() << '\n';
    }
}

vector<User>& UserRepository::getAll() {
    return users;
}

User* UserRepository::findById(int id) {
    for(auto& user : users) {
        if(user.getId() == id) return &user;
    }
    return nullptr;
}