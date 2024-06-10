#include <iostream>
using namespace std;

int main()
{
    int T = 0, n, k, arr[10000];
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int count = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == arr[i] + k)
                    count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}