#include "boiler.h"

bool checkPrime(int n)
{

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    bool ans = checkPrime(n);
    cout << ans << endl;
}