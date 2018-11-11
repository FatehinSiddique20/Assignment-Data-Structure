#ifndef PersonInfo_H_INCLUDED
#define PersonInfo_H_INCLUDED
#include <string>
using namespace std;

class PersonInfo
{
public:
    PersonInfo();
    PersonInfo(string,string,string,string,string,string,string);
    ~PersonInfo();

    void set_name(string);
    void set_father_name(string);
    void set_nID(string);
    void set_gender(string);
    void set_nationality(string);
    void set_profession(string);
    void set_address(string);

    string get_name();
    string get_father_name();
    string get_nID();
    string get_gender();
    string get_nationality();
    string get_profession();
    string get_address();
    void print_info();

protected:
    string name;
    string fatherName;
    string nID;
    string gender;
    string nationality;
    string profession;
    string address;
};

#endif // PersonInfo_H_INCLUDED

