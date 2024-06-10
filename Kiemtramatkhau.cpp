#include <iostream>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int T, n;
int arr[4][3];
int mk[9], check[9];
int res[9] = {-1};

void tao_mang()
{
    int count = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = count;
            if (count == 11)
            {
                arr[i][j] = 0;
            }
            count++;
        }
    }
}

void kiem_tra_res()
{
    for (int i = 0; i < n; i++)
    {
        res[i] = -1;
        if (check[i] == mk[i])
        {
            res[i] = 0;
        }
    }
}

bool check_mang(int x, int y)
{
    if (x >= 0 && x < 4 && y >= 0 && y < 3)
        return true;
    return false;
}

void foult(int index)
{
    int vi_tri_loi[2] = {-1, -1};
    int vi_tri_dung[2] = {-1, -1};
    // lỗi là check[index]; mật khẩu không khớp là mk[index]
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (check[index] == arr[i][j])
            {
                vi_tri_loi[0] = i;
                vi_tri_loi[1] = j;
            }
            if (mk[index] == arr[i][j])
            {
                vi_tri_dung[0] = i;
                vi_tri_dung[1] = j;
            }
        }
    }

    for (int k = 0; k < 4; k++)
    {
        int dxl = vi_tri_loi[0] + dx[k];
        int dyl = vi_tri_loi[1] + dy[k];
        if (check_mang(dxl, dyl) && (dxl == vi_tri_dung[0] && dyl == vi_tri_dung[1]))
        {
            res[index] = 1;
        }
    }
}

void kiem_tra_check()
{
    for (int i = 0; i < n; i++)
    {
        if (res[i] != 0)
        {
            foult(i);
        }
    }
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n;
        tao_mang();
        for (int i = 0; i < n; i++)
        {
            cin >> mk[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> check[i];
        }
        kiem_tra_res();
        kiem_tra_check();
        int dung = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (res[i] == -1)
            {
                dung = -1;
                cout << "#" << t << " " << dung << endl;
                break;
            }
            if (res[i] == 1)
            {
                dung = 1;
                count++;
                if (count > 1)
                {
                    dung = -1;
                    cout << "#" << t << " " << dung << endl;
                    break;
                }
            }
        }
        if (dung == 1)
        {
            cout << "#" << t << " ";
            for (int i = 0; i < n; i++)
            {
                if (res[i] == 1)
                    cout << i + 1 << " ";
            }
            cout << endl;
        }
        else if (dung == 0)
        {
            cout << "#" << t << " " << dung << endl;
        }
    }

    return 0;
}