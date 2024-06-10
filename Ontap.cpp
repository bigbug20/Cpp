#include <iostream>
using namespace std;

int T, n;
int m1, m2, arr[10001];
int tang[10001];

void sort_arr()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}

void sort_tang()
{
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (tang[j] > tang[i])
                {
                    int tmp = tang[j];
                    tang[j] = tang[i];
                    tang[i] = tmp;
                }
            }
        }
    }
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n >> m1 >> m2;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < m1; i++)
        {
            tang[i] = i + 1;
        }
        for (int i = m1; i < m1 + m2; i++)
        {
            tang[i] = i + 1 - m1;
        }
        sort_arr();
        sort_tang();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i] * tang[i];
        }
        cout << "#" << t << " " << sum << endl;
    }
    return 0;
}