#include<bits/stdc++.h>
using namespace std;

// Declaring the functions to be used in the code :
void InsertionSort(int array[], int n);
void PrintArray(int array[], int n);

int main(){
    int n;
    cout<<"Enter the number of elements of the array : ";
    cin>>n;
    int array[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0; i<n; i++)
    {
        cin>>array[i];
    }
    cout<<"Enter the number corresponding to the type of sort you would like to execute : \n";
    cout<<"1. Insertion Sort\n";
    int choice;
    cout<<"Your choice of sort : ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        InsertionSort(array, n);
        PrintArray(array, n);
        break;
    default:
        cout<<"The input you entered is not a valid input.";
        break;
    }
    return 0;
}

// DEFINING THE FUNCTIONS USED IN THE CODE :

// Function to perform Insertion sort on the inputted array
void InsertionSort(int array[], int n) 
{ 
    int key; 
    for(int i=1; i<n; i++)
    { 
        key = array[i]; 
        int j=i-1;
        while(j>=0 && array[j]>key)
        { 
            array[j+1] = array[j]; 
            j=j-1; 
        } 
        array[j+1]=key; 
    }
}

// Function for printing an array
void PrintArray(int array[], int n) 
{ 
    cout<<"The sorted array is as follows : ";
    for (int i=0; i<n; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}