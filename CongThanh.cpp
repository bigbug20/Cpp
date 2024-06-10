#include <iostream>
using namespace std;

int T, n;
long long arr[1005];
long long cnt_trai, cnt_phai;
long long max_cnt;
int vi_tri_max;

void danh_trai(int i)
{
    cnt_trai = 0;
    int check = arr[i];
    if (i > 0)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            int x = check / 2;
            if (x >= arr[j])
            {
                cnt_trai += arr[j];
                check += arr[j];
            }
            else
            {
                if (check <= arr[j])
                {
                    cnt_trai += check;
                    return;
                }
                else if (check > arr[j])
                {
                    check -= arr[j];
                    cnt_trai += arr[j];
                }
            }
        }
    }
}

void danh_phai(int i)
{
    cnt_phai = 0;
    int check = arr[i];
    if (i < n - 1)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x = check / 2;
            if (x >= arr[j])
            {
                cnt_phai += arr[j];
                check += arr[j];
            }
            else
            {
                if (check <= arr[j])
                {
                    cnt_phai += check;
                    return;
                }
                else if (check > arr[j])
                {
                    check -= arr[j];
                    cnt_phai += arr[j];
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
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        max_cnt = 0;
        for (int i = 0; i < n; i++)
        {
            danh_phai(i);
            danh_trai(i);
            long long current_max = max(cnt_trai, cnt_phai);
            if (current_max > max_cnt)
            {
                max_cnt = current_max;
                vi_tri_max = i;
            }
        }
        cout << "#" << t << " " << max_cnt << " " << vi_tri_max << endl;
    }
    return 0;
}
