#include "boiler.h"

int Reverse(int n)
{
    int reverse = 0;
    while (n != 0)
    {
        int last = n % 10;
        reverse = reverse * 10 + last;
        n = n / 10;
    }
    return reverse;
}
int main()
{

    int n;
    cin >> n;
    n = Reverse(n);
    cout << n << endl;
}