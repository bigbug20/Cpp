#include <iostream>
using namespace std;

int T, n;
int arr[1001];
long long max_defeated;

long long defeated_troops(int start, int direction)
{
    long long cnt = 0;
    long long check = arr[start];

    for (int i = start + direction; i >= 0 && i < n; i += direction)
    {
        if (check <= 0)
            break;
        if (check <= arr[i])
        {
            cnt += check;
            break;
        }
        if (check / 2 >= arr[i])
        {
            cnt += arr[i];
            check -= arr[i];
        }
        else
        {
            check -= arr[i];
            cnt += arr[i];
        }
    }
    return cnt;
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        max_defeated = 0;
        for (int i = 0; i < n; i++)
        {
            max_defeated = max(max_defeated, defeated_troops(i, -1));
            max_defeated = max(max_defeated, defeated_troops(i, 1));
        }
        cout << "#" << t << " " << max_defeated << endl;
    }
    return 0;
}
