#ifndef customerListVec_H_INCLUDED
#define customerListVec_H_INCLUDED
#include"CustomerData.h"
#include <vector>

class customerListVec
{
public:
    customerListVec();
    customerListVec(int);
    ~customerListVec();

    void insert_customer(string,string,string,string,string,string,string,string,string);
    void delete_customer(string);
    void change_name(string,string);
    void change_father_name(string,string);
    void change_nID(string,string);
    void change_gender(string,string);
    void change_nationality(string,string);
    void change_profession(string,string);
    void change_address(string,string);
    void add_mobile_number(string,string,string);
    void change_mobile_operator(string,string,string);
    void remove_mobile_number(string,string);
    bool search_nID1(string);
    bool search_mobile_number1(string);

    string get_name(string);
    string get_father_name(string);
    string get_nID(string);
    string get_gender(string);
    string get_nationality(string);
    string get_profession(string);
    string get_address(string);
    string* get_mobile_number(string);

    void print_info(string);
    void print_info();

private:
    vector<CustomerData> customerList;
};

#endif // customerListVec_H_INCLUDED
