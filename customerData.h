#ifndef CUSTOMERDATA_H_INCLUDED
#define CUSTOMERDATA_H_INCLUDED
#include "PersonInfo.h"
#include <string>

class CustomerData :public PersonInfo
{
public:
    CustomerData();
    CustomerData(string,string,string,string,string,string,string,string,string);
    ~CustomerData();
    void set_mobile_number(string,string);
    void add_mobile_number(string,string);
    void change_mobile_operator(string,string);
    void remove_mobile_number(string);
    bool search_mobile_number(string);
    void print_info();

    int get_mobile_number_counter();
    string* get_mobile_number();

private:
    string *mobileNumber;
    string *mobileOperator;
    int mobileNumberCounter;
    int arraySize;
};

#endif // CUSTOMERDATA_H_INCLUDED
