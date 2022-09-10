#include<bits/stdc++.h>
using namespace std;

float add(float a, float b);

int main(){
    int choice;
    cout<<"Enter the number corresponding to the operation to be performed : \n";
    cout<<"1 - Addtion\n2 - Subtraction\n3 - Multiplication\n4 - Division\n5 - Average\n";
    cout<<"The chosen operation number is : ";
    cin>>choice;
    float x, y;
    cout<<"Enter the two numbers on which the operation is to be performed : ";
    cin>>x>>y;
    switch (choice)
    {
        case 1 :
            add(x, y);
            break;
        default :
            cout<<"The number you entered for choosing the operation is not a valid input.\n";
            break;
    }
    return 0;
}

float add(float a, float b)
{
    float output=a+b;
    cout<<"The sum of the two numbers you entered is : "<<output;
}