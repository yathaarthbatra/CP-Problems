#include <iostream>
using namespace std;
#include <bits/stdc++.h>
//the code for returning the duplicate value from the array
//whose size is N+1 and contains the element ranging from 1 to N

void duplicate(int arr[], int n)
{

    int slow = arr[0];
    int fast = arr[0];

    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];

    } while (slow != fast);

    fast = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    cout << slow << endl;
}

//here using the approach of cycle
int main()
{
    int arr[] = {1, 3, 4, 3, 2};
    duplicate(arr, 5);
    return 0;
}