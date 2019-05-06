#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class PhoneBook
{
public:
    void save_To_DataBase(string name,string number);
    void delete_Contact(string string_of_contact);
    vector <string> find_Contact(string name);
};

#endif // PHONEBOOK_H
