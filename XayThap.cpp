#include <iostream>
using namespace std;

int n, m1, m2, T;
int tang[102];
int sum = 0;
int gach[1002];

void sort_tang()
{
    for (int i = 0; i < m1 + m2; i++)
    {
        for (int j = 0; j < m1 + m2; j++)
        {
            if (tang[i] > tang[j])
            {
                int tmp = tang[i];
                tang[i] = tang[j];
                tang[j] = tmp;
            }
        }
    }
}

void sort_gach()
{
    for (int i = 0; i < m1 + m2; i++)
    {
        for (int j = 0; j < m1 + m2; j++)
        {
            if (gach[i] < gach[j])
            {
                int tmp = gach[i];
                gach[i] = gach[j];
                gach[j] = tmp;
            }
        }
    }
}

void cal()
{
    for (int i = 0; i < m1 + m2; i++)
    {
        int x = (gach[i]) *= (tang[i]);
        sum += x;
    }
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n >> m1 >> m2;
        int count1 = 1;
        int count2 = 1;
        for (int i = 0; i < m1; i++)
        {
            tang[i] = count1;
            count1++;
        }
        for (int i = m1; i < m1 + m2; i++)
        {
            tang[i] = count2;
            count2++;
        }
        sort_tang();
        for (int i = 0; i < n; i++)
        {
            cin >> gach[i];
        }
        sort_gach();
        sum = 0;
        cal();
        cout << "#" << t << " " << sum << endl;
    }
    return 0;
}