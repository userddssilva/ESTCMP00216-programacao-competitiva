#include <iostream>
using namespace std;

int n, m, i;

int main()
{

    while (cin >> n)
    {

        m = 0;
        i = 0;
        do
        {
            int pot10 = (10 % n * m % n) % n;
            m = (pot10 % n + 1 % n) % n;
            // cout << m << endl;
            i++;
        } while (m != 0);
        // cout << m << endl;
        cout << i << endl;
    }
    return 0;
}