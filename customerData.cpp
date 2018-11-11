
#include"CustomerData.h"
#include<iostream>
using namespace std;
CustomerData::CustomerData()
{
    mobileNumberCounter = 0;
    arraySize = 2;
    mobileNumber = new string[2];
    mobileOperator = new string[2];
}

CustomerData::CustomerData(string name, string fatherName, string nID, string gender,
                           string  nationality, string profession, string address,string mobileNumber,string mobileOperator)
{

    arraySize = 2;
    this->mobileNumber = new string[2];
    this->mobileOperator = new string[2];
    mobileNumberCounter = 0;
    set_mobile_number(mobileNumber,mobileOperator);
    this->name = name;
    this->fatherName = fatherName;
    this->nID = nID;
    this->gender = gender;
    this->nationality = nationality;
    this->profession = profession;
    this->address = address;

}
CustomerData::~CustomerData()
{

}
bool multiple_number_checker(int mobileNumberCounter)
{
    return mobileNumberCounter<15;
}
int get_digit(string mobileNumber)
{
    return mobileNumber.length();
}
bool check_mobile_number(string mobileNumber)
{
    return get_digit(mobileNumber)==11;
}
void CustomerData::set_mobile_number(string mobileNumber, string mobileOperator)
{
    if(check_mobile_number(mobileNumber))
    {
        if(multiple_number_checker(mobileNumberCounter))
        {
            bool found=false;
            for(int index=0; index<mobileNumberCounter; index++)
            {
                if(!(this->mobileNumber[index].compare(mobileNumber)))
                {
                    found = true;
                    break;
                }

            }
            if(!found)
            {
                if(mobileNumberCounter == arraySize)
                {
                    string* temp;
                    string* temp1;
                    temp = this->mobileNumber;
                    temp1 = this->mobileOperator;
                    this->mobileNumber = new string[arraySize*2];
                    this->mobileOperator = new string[arraySize*2];
                    arraySize=arraySize*2;
                    for(int index =0; index<mobileNumberCounter; index++)
                    {
                        this->mobileNumber[index]=temp[index];
                        this->mobileOperator[index]=temp1[index];
                    }
                    delete[] temp;
                    delete[] temp1;
                    mobileNumberCounter++;
                    this->mobileNumber[mobileNumberCounter-1]=mobileNumber;
                    this->mobileOperator[mobileNumberCounter-1]=mobileOperator;
                }
                else
                {
                    mobileNumberCounter++;
                    this->mobileNumber[mobileNumberCounter-1]=mobileNumber;
                    this->mobileOperator[mobileNumberCounter-1]=mobileOperator;

                }
            }
            else
            {
                cout<<"Mobile number is already in list"<<endl;
            }
        }
        else
        {
            cout<<"Request Denied!!"<<endl;
            cout<<"You cannot get more than fifteen Mobile Number."<<endl;
        }
    }
    else
    {
        cout<<"Request Denied!!"<<endl;
        cout<<"Your Mobile Number is Invalid."<<endl;
    }
}

void CustomerData::add_mobile_number(string mobileNumber, string mobileOperator)
{
    set_mobile_number(mobileNumber,mobileOperator);
}

void CustomerData::change_mobile_operator(string mobileNumber,string mobileOperator)
{
    if(mobileNumberCounter == 0)
    {
        cout<<"Invalid Request"<<endl;
        cout<<"You don't have any mobile number yet!!"<<endl;
    }
    else
    {
        int found=-1;
        for(int index=0; index<mobileNumberCounter; index++)
        {
            if(!(this->mobileNumber[index].compare(mobileNumber)))
            {
                found=index;
                break;
            }
        }
        if(found<0)
        {
            cout<<"Number not in the list"<<endl;
            cout<<"Mobile number operator no changed"<<endl;
        }
        else
        {
            this->mobileOperator[found]=mobileOperator;
        }
    }

}
void CustomerData::remove_mobile_number(string mobileNumber)
{
    int found = -1;
    for(int index=0; index<mobileNumberCounter; index++)
    {
        if(!(this->mobileNumber[index].compare(mobileNumber) ) )
        {
            found=index;
            break;
        }
    }
    if(found>=0)
    {
        if(mobileNumberCounter==1)
        {
            this->name = "";
            this->fatherName = "";
            this->nID = "";
            this->gender = "";
            this->nationality = "";
            this->profession = "";
            this->address = "";
            delete[] this->mobileNumber;
            this->mobileNumber = nullptr;
            delete[] this->mobileOperator;
            this->mobileOperator = nullptr;
        }
        else
        {
            this->mobileNumber[found] = this->mobileNumber[mobileNumberCounter-1];
            this->mobileOperator[found] = this->mobileOperator[mobileNumberCounter-1];
            mobileNumberCounter--;
            if(mobileNumberCounter == 2 || mobileNumberCounter == 4 || mobileNumberCounter == 8)
            {
                    string* temp;
                    string* temp1;
                    temp = this->mobileNumber;
                    temp1 = this->mobileOperator;
                    this->mobileNumber = new string[arraySize*2];
                    this->mobileOperator = new string[arraySize*2];
                    arraySize=arraySize*2;
                    for(int index =0; index<mobileNumberCounter; index++)
                    {
                        this->mobileNumber[index]=temp[index];
                        this->mobileOperator[index]=temp1[index];
                    }
                    delete[] temp;
                    delete[] temp1;
            }
        }
    }
    else
    {
        cout<<"Deletion not possible."<<endl;
        cout<<"Number not found."<<endl;
    }
}


void CustomerData::print_info()
{
    cout<<endl<<"Name             : "<<name<<endl;
    cout<<"Father Name      : "<<fatherName<<endl;
    cout<<"National ID      : "<<nID<<endl;
    cout<<"Gender           : "<<gender<<endl;
    cout<<"Nationality      : "<<nationality<<endl;
    cout<<"Profession       : "<<profession<<endl;
    cout<<"Address          : "<<address<<endl;
    for(int index = 0; index<mobileNumberCounter; index++)
        cout<<"Mobile Number "<<index+1<<"  : "<<mobileNumber[index]<<" "<<"Operator : "<<mobileOperator[index]<<endl;
}
bool CustomerData::search_mobile_number(string mobileNumber)
{
            bool found=false;
            for(int index=0; index<mobileNumberCounter; index++)
            {
                if(!(this->mobileNumber[index].compare(mobileNumber)))
                {
                    found = true;
                    break;
                }

            }
            return found;
}

string* CustomerData::get_mobile_number()
{
    if(mobileNumberCounter)
        return mobileNumber;
    else
        return nullptr;
}

int CustomerData::get_mobile_number_counter()
{
    return mobileNumberCounter;
}

