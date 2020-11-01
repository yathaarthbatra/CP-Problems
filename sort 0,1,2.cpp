#include <iostream>
using namespace std;

void demo(int p[], int size)
{
    int mid = 0;
    int low = 0;
    int high = size - 1;

    while (mid <= high)
    {
        if (p[mid] == 0)
        {
            swap(p[low], p[mid]);
            mid++;
            low++;
        }
        else if (p[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(p[mid], p[high]);
            high--;
        }
    }
}
int main()
{
    //int i = 10;
    int arr[] = {2, 2, 1, 1, 0};

    cout << "Befor Fn=" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    demo(arr, 5); //arr acts as pointer
    cout << "After fn=" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}