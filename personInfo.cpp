#include "PersonInfo.h"
#include<iostream>
using namespace std;

PersonInfo::PersonInfo()
{
     name="";
     fatherName="";
     nID="";
     gender="";
     nationality="";
     profession="";
     address="";
}

PersonInfo::PersonInfo(string name, string fatherName, string nID, string gender,
        string  nationality, string profession, string address)
{
    this->name = name;
    this->fatherName = fatherName;
    this->nID = nID;
    this->gender = gender;
    this->nationality = nationality;
    this->profession = profession;
    this->address = address;
}

PersonInfo::~PersonInfo()
{

}

void PersonInfo::set_name(string name)
{
    this->name = name;
}

void PersonInfo::set_father_name(string fatherName)
{
    this->fatherName = fatherName;
}

void PersonInfo::set_nID(string nID)
{
    this->nID = nID;
}

void PersonInfo::set_gender(string gender)
{
    this->gender = gender;
}

void PersonInfo::set_nationality(string nationality)
{
    this->nationality = nationality;
}

void PersonInfo::set_profession(string profession)
{
    this->profession = profession;
}

void PersonInfo::set_address(string address)
{
    this->address = nullptr;
}

string PersonInfo::get_name()
{
    cout<<this->name;
    return name;
}

string PersonInfo::get_father_name()
{
    return fatherName;
}

string PersonInfo::get_nID()
{
    return nID;
}

string PersonInfo::get_gender()
{
    return gender;
}

string PersonInfo::get_nationality()
{
    return nationality;
}

string PersonInfo::get_profession()
{
    return profession;
}

string PersonInfo::get_address()
{
    return address;
}

void PersonInfo::print_info()
{
    cout<<endl<<"Name            : "<<name<<endl;
    cout<<"Father Name     : "<<fatherName<<endl;
    cout<<"National ID     : "<<nID<<endl;
    cout<<"Gender          : "<<gender<<endl;
    cout<<"Nationality     : "<<nationality<<endl;
    cout<<"Profession      : "<<profession<<endl;
    cout<<"Address         : "<<address<<endl;
}
