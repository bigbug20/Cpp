#include <iostream>
using namespace std;

int main()
{
    int T, n;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int so[100002];
        int count[100002] = {0};
        int result = -1;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> so[i];
        }
        for (int i = 0; i < n; i++)
        {
            count[so[i]]++;
            if (count[so[i]] == 2)
            {
                result = so[i];
                break;
            }
        }
        cout << "#" << t + 1 << " " << result << endl;
    }
    return 0;
}