#include "phonebook.h"

void PhoneBook::save_To_DataBase(string name,string number)
{
    ofstream file;
    file.open("database.txt",ios::app);
    file << name << "\t" << number<<"\n";
    file.close();
}
void PhoneBook::delete_Contact(string string_of_contact)
{
    ifstream file;
    file.open("database.txt");
    vector<string> strings;
    string str;
    while (!file.eof())
    {
        file >> str;
        strings.push_back(str);
    }
    file.close();
    for(int i=0;i<=strings.size();i++)
    {
        if(string_of_contact==strings.at(i))
            strings.at(i) = "zero";
    }

    ofstream clear;
    clear.open("database.txt", ios::trunc);
    clear.close();

    ofstream new_file;
    new_file.open("database.txt");
    for(int i=0;i<strings.size();i++)
    {
        if(strings.at(i)=="zero")
            continue;

        new_file << strings.at(i);
    }
}
