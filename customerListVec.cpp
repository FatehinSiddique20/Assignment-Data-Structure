#include "customerListVec.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

customerListVec::customerListVec()
{
    vector<CustomerData> list;
    customerList = list;
}

customerListVec::customerListVec(int size)
{
    vector<CustomerData> list;
    list.reserve(size);
    customerList = list;
}
int get_digit2(string mobileNumber)
{
    return mobileNumber.length();
}
bool check_mobile_number2(string mobileNumber)
{
    return get_digit2(mobileNumber)==11;
}
bool check_nId2(string nID)
{
    return get_digit2(nID)==11 || get_digit2(nID)==17;

}
bool customerListVec::search_nID1(string nID)
{
            bool found=false;
            for(int index=0; index<customerList.size(); index++)
            {
                if(!(nID.compare(this->customerList[index].get_nID())))
                {
                    found = true;
                    break;
                }

            }
            return found;
}
bool customerListVec::search_mobile_number1(string mobileNumber)
{
            bool found=false;
            for(int index=0; index<customerList.size(); index++)
            {
                if((this->customerList[index].search_mobile_number(mobileNumber)))
                {
                    found = true;
                    break;
                }
            }
            return found;
}
void customerListVec::insert_customer(string name, string fatherName, string nID, string gender,
        string  nationality, string profession, string address, string mobileNumber, string mobileOperator)
{
    if(check_mobile_number2(mobileNumber) && check_nId2(nID) && !search_nID1(nID) && !search_mobile_number1(mobileNumber))
    {
           CustomerData customer( name,  fatherName,  nID,  gender,
                           nationality,  profession,  address, mobileNumber, mobileOperator);
    customerList.push_back(customer);
    }
    else
    {
        if(search_mobile_number1(mobileNumber))
        {
        cout<<"Mobile Number already in list!!"<<endl;
        cout<<"Customer Not added in list."<<endl;
        }
        else if(search_nID1(nID))
        {
        cout<<"NID IS already Registered!!"<<endl;
        cout<<"Customer Not added in list."<<endl;
        }
        else if(!check_nId2(nID))
        {
        cout<<"NID is wrong!!"<<endl;
        cout<<"Customer Not added in list."<<endl;
        }
        else
        {
        cout<<"Mobile Number is wrong!!"<<endl;
        cout<<"Customer Not added in list."<<endl;
        }
    }

}
customerListVec::~customerListVec()
{
   customerList.clear();
}
void customerListVec::delete_customer(string nID)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(customerList.size() == 1)
    {
        customerList.clear();
    }
    else
    {
        customerList.erase(customerList.begin()+found);
    }
    if(customerList.size() == customerList.capacity()/2)
    {
        customerList.resize(customerList.size());
    }
}
void customerListVec::change_name(string name,string nID)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
    }
    else
    {
        customerList[found].set_name(name);
    }
}

void customerListVec::change_father_name(string fatherName, string nID)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
    }
    else
    {
        customerList[found].set_father_name(fatherName);
    }
}

void customerListVec::change_nID(string nID,string newnID)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
    }
    else
    {
        customerList[found].set_nID(newnID);
    }
}

void customerListVec::change_gender(string gender,string nID )
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
    }
    else
    {
        customerList[found].set_gender(gender);
    }
}

void customerListVec::change_nationality(string nationality,string nID)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
    }
    else
    {
        customerList[found].set_nationality(nationality);
    }
}

void customerListVec::change_profession(string profession,string nID)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
    }
    else
    {
        customerList[found].set_profession(profession);
    }
}

void customerListVec::change_address(string address,string nID)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
    }
    else
    {
        customerList[found].set_address(address);
    }
}

void customerListVec::add_mobile_number(string mobileNumber, string mobileOperator, string nID)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
    }
    else
    {
        customerList[found].add_mobile_number(mobileNumber,mobileOperator);
    }
}

void customerListVec::change_mobile_operator(string mobileNumber, string mobileOperator,string nID)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
    }
    else
    {
        customerList[found].change_mobile_operator(mobileNumber,mobileOperator);
    }
}

void customerListVec::remove_mobile_number(string mobileNumber,string nID)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
    }
    else
    {
        if(customerList[found].get_mobile_number_counter()==1 && customerList[found].search_mobile_number(mobileNumber))
        {
            delete_customer(customerList[found].get_nID());
        }
        else
        {
            customerList[found].remove_mobile_number(mobileNumber);
        }
    }

}

string customerListVec::get_name(string nID)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
        return nullptr;
    }
    else
    {
        return customerList[found].get_name();
    }
}

string customerListVec::get_father_name(string nID)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
        return nullptr;

    }
    else
    {
        return customerList[found].get_father_name();
    }
}

string customerListVec::get_nID(string name)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!name.compare(customerList[index].get_name()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
        return nullptr;

    }
    else
    {
        return customerList[found].get_nID();
    }
}

string customerListVec::get_gender(string nID)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
        return nullptr;

    }
    else
    {
        return customerList[found].get_gender();
    }
}

string customerListVec::get_nationality(string nID)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
        return nullptr;

    }
    else
    {
        return customerList[found].get_nationality();
    }
}

string customerListVec::get_profession(string nID)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
        return nullptr;

    }
    else
    {
        return customerList[found].get_profession();
    }
}

string customerListVec::get_address(string nID)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
        return nullptr;

    }
    else
    {
        return customerList[found].get_address();
    }
}

string* customerListVec::get_mobile_number(string nID)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
        return nullptr;

    }
    else
    {
        return customerList[found].get_mobile_number();
    }
}

void customerListVec::print_info(string nID)
{
    int found=-1;
    for(int index=0; index<customerList.size(); index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(found<0)
    {
        cout<<"No Customer available in list with this NID."<<endl;
    }
    else
    {
        customerList[found].print_info();
    }
}

void customerListVec::print_info()
{
    for(int index = 0; index<customerList.size(); index++)
    {
        cout<<endl<<"Customer "<<index+1<<" :";
        customerList[index].print_info();
    }
}

