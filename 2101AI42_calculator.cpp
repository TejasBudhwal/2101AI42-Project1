#include<bits/stdc++.h>
using namespace std;

float add(float a, float b);
float sub(float a, float b);
float multi(float a, float b);
float div(float a, float b);

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
        case 2 :
            sub(x, y);
            break;
        case 3 :
            multi(x, y);
            break;
        case 4 :
            div(x, y);
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

float sub(float a, float b)
{
    float output=a-b;
    cout<<"The difference of the two numbers you entered is : "<<output;
}

float multi(float a, float b)
{
    float output=a*b;
    cout<<"Multiplication of the two numbers you entered gives : "<<output;
}

float div(float a, float b)
{
    float output=a/b;
    cout<<"Division of the two numbers you entered gives : "<<output;
}