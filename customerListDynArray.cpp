#include "customerListDynArray.h"
#include <string>
#include <iostream>
using namespace std;

customerListDynArray::customerListDynArray()
{
    arraySize = 2;
    listSize = 0;
    customerList = new CustomerData[2];
}

customerListDynArray::customerListDynArray(int size)
{
    arraySize= size;
    listSize = 0;
    customerList = new CustomerData[size];
}
customerListDynArray::~customerListDynArray()
{
    delete[]customerList;
}
int get_digit1(string mobileNumber)
{
    return mobileNumber.length();
}
bool check_mobile_number1(string mobileNumber)
{
    return get_digit1(mobileNumber)==11;
}
bool check_nId1(string nID)
{
    return (get_digit1(nID)==11 || get_digit1(nID)==17);

}
bool customerListDynArray::search_nID(string nID)
{
            bool found=false;
            for(int index=0; index<listSize; index++)
            {
                if(!(nID.compare(this->customerList[index].get_nID())))
                {
                    found = true;
                    break;
                }

            }
            return found;
}
bool customerListDynArray::search_mobile_number(string mobileNumber)
{
            bool found=false;
            for(int index=0; index<listSize; index++)
            {
                if((this->customerList[index].search_mobile_number(mobileNumber)))
                {
                    found = true;
                    break;
                }
            }
            return found;
}

void customerListDynArray::insert_customer(string name, string fatherName, string nID, string gender,
        string  nationality, string profession, string address, string mobileNumber, string mobileOperator)
{
    if(check_mobile_number1(mobileNumber) && check_nId1(nID) && !search_nID(nID) && !search_mobile_number(mobileNumber) )
    {
    CustomerData customer( name,  fatherName,  nID,  gender,
                           nationality,  profession,  address, mobileNumber,mobileOperator);
    if(listSize == arraySize)
    {
        CustomerData* temp;
        temp = customerList;
        customerList = new CustomerData[arraySize*2];
        arraySize=arraySize*2;
        for(int index =0; index<listSize; index++)
        {
            customerList[index]=temp[index];
        }
        delete[] temp;
        listSize++;
        customerList[listSize-1]=customer;
    }
    else
    {
        listSize++;
        this->customerList[listSize-1]=customer;
    }
    }
    else
    {
        if(search_mobile_number(mobileNumber))
        {
        cout<<"Mobile Number already in list!!"<<endl;
        cout<<"Customer Not added in list."<<endl;
        }
        else if(search_nID(nID))
        {
        cout<<"NID IS already Registered!!"<<endl;
        cout<<"Customer Not added in list."<<endl;
        }
        else if(!check_nId1(nID))
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
void customerListDynArray::delete_customer(string nID)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
    {
        if(!nID.compare(customerList[index].get_nID()))
        {
            found = index;
            break;
        }
    }
    if(listSize == 1)
    {
        listSize=0;
        delete[] customerList;
        customerList=nullptr;
    }
    else
    {
        customerList[found]=customerList[listSize-1];
        listSize--;
    }
    if(listSize == arraySize/2)
    {
        CustomerData* temp;
        temp = customerList;
        customerList = new CustomerData[arraySize/2];
        arraySize=arraySize/2;
        for(int index =0; index<listSize; index++)
        {
            customerList[index]=temp[index];
        }
        delete[] temp;
    }
}
void customerListDynArray::change_name(string name,string nID)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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

void customerListDynArray::change_father_name(string fatherName, string nID)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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

void customerListDynArray::change_nID(string nID,string newnID)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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

void customerListDynArray::change_gender(string gender,string nID )
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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

void customerListDynArray::change_nationality(string nationality,string nID)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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

void customerListDynArray::change_profession(string profession,string nID)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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

void customerListDynArray::change_address(string address,string nID)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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

void customerListDynArray::add_mobile_number(string mobileNumber,string mobileOperator,string nID)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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

void customerListDynArray::change_mobile_operator(string mobileNumber, string mobileOperator,string nID)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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

void customerListDynArray::remove_mobile_number(string mobileNumber,string nID)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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
        if(customerList[found].get_mobile_number_counter()==1  && customerList[found].search_mobile_number(mobileNumber))
        {
            delete_customer(customerList[found].get_nID());
        }
        else
        {
            customerList[found].remove_mobile_number(mobileNumber);
        }
    }

}

string customerListDynArray::get_name(string nID)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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

string customerListDynArray::get_father_name(string nID)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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

string customerListDynArray::get_nID(string name)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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

string customerListDynArray::get_gender(string nID)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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

string customerListDynArray::get_nationality(string nID)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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

string customerListDynArray::get_profession(string nID)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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

string customerListDynArray::get_address(string nID)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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

string* customerListDynArray::get_mobile_number(string nID)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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

void customerListDynArray::print_info(string nID)
{
    int found=-1;
    for(int index=0; index<listSize; index++)
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


void customerListDynArray::print_info()
{
    for(int index=0; index<listSize; index++)
    {
        cout<<endl<<"Customer "<<index+1<<" :";
        customerList[index].print_info();
    }
}
