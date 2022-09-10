#include<bits/stdc++.h>
using namespace std;

// Declaring the functions to be used in the code :
void InsertionSort(int array[], int n);
void SelectionSort(int array[], int n);
void BubbleSort(int array[], int n);
void MergeSort(int array[], int const begin, int const end);
void QuickSort(int array[], int low, int high);
void PrintArray(int array[], int n);
void swap(int *x, int *y);
void Merge(int array[], int const left, int const mid, int const right);
int Partition (int array[], int low, int high);

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
    cout<<"2. Selection Sort\n";
    cout<<"3. Bubble Sort\n";
    cout<<"4. Merge Sort\n";
    cout<<"5. Quick Sort\n";
    int choice;
    cout<<"Your choice of sort : ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        InsertionSort(array, n);
        PrintArray(array, n);
        break;
    case 2:
        SelectionSort(array, n);
        PrintArray(array, n);
        break;
    case 3:
        BubbleSort(array, n);
        PrintArray(array, n);
        break;
    case 4:
        MergeSort(array, 0, n-1);
        PrintArray(array, n);
        break;
    case 5:
        QuickSort(array, 0, n-1);
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

// Function to perform Selection sort on the inputted array
void SelectionSort(int array[], int n)
{
    int min_index;
    for(int i = 0; i < n-1; i++)
    {
        min_index = i;
        for(int j=i+1; j<n; j++)
        if (array[j] < array[min_index])
        {
            min_index=j;
        }
        if(min_index != i)
        {
            swap(&array[min_index], &array[i]);
        }
    }
}

// Function for swapping two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to perform Bubble sort on the inputted array
void BubbleSort(int array[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

// Function that helps in the execution of the MergeSort function
void Merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne=mid-left+1;
    auto const subArrayTwo=right-mid;
  

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for(auto i=0; i<subArrayOne; i++)
    {
        leftArray[i] = array[left+i];
    }
    for(auto j=0; j<subArrayTwo; j++)
    {
        rightArray[j] = array[mid + 1 + j];
    }
  
    auto indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while(indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if(leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while(indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while(indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
  
// Function to perform Bubble sort on the inputted array
void MergeSort(int array[], int const begin, int const end)
{
    if(begin >= end)
    {
        return;
    }
    auto mid=begin+(end - begin)/2;
    MergeSort(array, begin, mid);
    MergeSort(array, mid + 1, end);
    Merge(array, begin, mid, end);
}

// Function for creating a partition of the array
/* The function takes the last element of the array
as th pivot and places it at its correct position
in the sorted array. Then it places all the elements
smaller than the pivot to the left of it and all the
elements greater then the pivot to the right of it. */
int Partition (int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);
    for (int j=low; j<=high-1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[high]);
    return (i+1);
}

// Function to perform Quick sort on the inputted array
void QuickSort(int array[], int low, int high)
{
    if(low < high)
    {
        int pi = Partition(array, low, high);
        QuickSort(array, low, pi - 1);
        QuickSort(array, pi + 1, high);
    }
}