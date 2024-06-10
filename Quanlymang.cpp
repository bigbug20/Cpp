#include <iostream>
using namespace std;

int T, n, l;
int arr[100001];
char lenh[7];
int vi_tri, thay_the;

void insert(int &n)
{
    for (int i = n; i > vi_tri; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[vi_tri] = thay_the;
    n++;
}

void update()
{
    arr[vi_tri] = thay_the;
}

void del(int &n)
{
    arr[vi_tri] = 0;
    for (int i = vi_tri; i < n + 1; i++)
        arr[i] = arr[i + 1];
    n--;
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
        cin >> l;
        for (int i = 1; i <= l; i++)
        {
            cin >> lenh;
            if (lenh[0] == 'i')
            {
                cin >> vi_tri >> thay_the;
                insert(n);
            }
            else if (lenh[0] == 'u')
            {
                cin >> vi_tri >> thay_the;
                update();
            }
            else if (lenh[0] == 'd')
            {
                cin >> vi_tri;
                del(n);
            }
        }
        cout << "#" << t << " ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}