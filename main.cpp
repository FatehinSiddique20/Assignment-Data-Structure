#include <iostream>
#include "customerListDynArray.h"
#include "customerListVec.h"
using namespace std;

void  runner_function_dynamic_array()
{
    customerListDynArray customerList;
    customerList.insert_customer("Fatehin","Chowdhury","9898989898","male","bangladeshi","student","Dhaka bangladesh","01972027234","Banglalink");
    customerList.insert_customer("Asmita","Ahmed","22222222222","male","bangladeshi","student","Dhaka bangladesh","01935664754","Banglalink");
    customerList.add_mobile_number("01952411514","Banglalink","11111111111");
    customerList.insert_customer("Fatehin3"," father3","33333333333","male","bangladeshi","student","Dhaka bangladesh","01952411513","Banglalink");
    customerList.insert_customer("Fatehin4"," father4","44444444444","male","bangladeshi","student","Dhaka bangladesh","11111111111","Banglalink");
    customerList.insert_customer("Fatehin5"," father5","55555555555","male","bangladeshi","student","Dhaka bangladesh","01952411515","Banglalink");
    customerList.insert_customer("Fatehin6"," father6","66666666666","male","bangladeshi","student","Dhaka bangladesh","01952411516","Banglalink");
    customerList.insert_customer("Fatehin7"," father7","77777777777","male","bangladeshi","student","Dhaka bangladesh","01952411517","Banglalink");
    customerList.remove_mobile_number("01952411511","11111111111");
    customerList.remove_mobile_number("01952411514","11111111111");
    customerList.change_mobile_operator("01952411512","Grameen Phone","22222222222222222");
    cout<<"Customer using Dinamic Array: "<<endl;

    customerList.print_info();

}
void runner_function_vector()
{
    customerListVec customerList;
    customerList.insert_customer("Fatehin1","Fatehin father1","11111111111","male","bangladeshi","student","Dhaka bangladesh","01952411511","Banglalink");
    customerList.insert_customer("Fatehin2","Fatehin father2","22222222222","male","bangladeshi","student","Dhaka bangladesh","01952411512","Banglalink");
    customerList.add_mobile_number("01972027234","Banglalink","11111111111");
    customerList.insert_customer("Fatehin3","Fatehin father3","33333333333","male","bangladeshi","student","Dhaka bangladesh","01952411513","Banglalink");
    customerList.insert_customer("Fatehin4","Fatehin father4","44444444444","male","bangladeshi","student","Dhaka bangladesh","01952411514","Banglalink");
    customerList.insert_customer("Fatehin5","Fatehin father5","55555555555","male","bangladeshi","student","Dhaka bangladesh","01952411515","Banglalink");
    customerList.insert_customer("Fatehin6","Fatehin father6","66666666666","male","bangladeshi","student","Dhaka bangladesh","01952411516","Banglalink");
    customerList.insert_customer("Fatehin7","Fatehin father7","77777777777","male","bangladeshi","student","Dhaka bangladesh","01952411517","Banglalink");
    //customerList.remove_mobile_number("01952411513","11111111111");
    //customerList.remove_mobile_number("01952411514","11111111111");
    customerList.change_mobile_operator("01952411512","Grameen Phone","22222222222");

    cout<<"Customer using vector: "<<endl;

    customerList.print_info();
}


int main()
{
    runner_function_vector();
    runner_function_dynamic_array();

    return 0;
}
