#ifndef _USER_H_
#define _USER_H_
#include <string>
#include <sstream>
using namespace std;

class User {
    private:
    int id;
    string name;
    
    public:
    // Constructor
    User();
    User(int id, string name);
    
    // Getter
    int getId() const;
    string getName() const;
    
    // Setter
    void setName(string name);

    string toCSV() const;
    static User readFromCSV(const string& line);
};
#endif