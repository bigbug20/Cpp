#include <iostream>
using namespace std;
int a[100][100];
void nhap_ham_ngang(int n)
{
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = num;
            num = num + 1;
        }
    }
}
void nhap_ham_nxenke(int n)
{
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = num;
                num = num + 1;
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                a[i][j] = num;
                num = num + 1;
            }
        }
    }
}
void nhap_ham_doc(int n)
{
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[j][i] = num++;
        }
    }
}
void nhap_ham_dxenke(int n)
{
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i % 2 == 0 ? j : n - j - 1][i] = num++;
        }
    }
}
void nhap_ham_cxuong(int n)
{
    int count = 1;
    // duyet nua duoi cua ma tran
    int row = n - 1;
    while (row >= 0)
    {
        int j = 0;
        for (int i = row; i < n; i++)
        {
            a[i][j] = count;
            count++;
            j++;
        }
        row--;
    }

    // duyet nua tren cua ma tran

    int col = 1;
    while (col < n)
    {
        int i = 0;
        for (int j = col; j < n; j++)
        {
            a[i][j] = count;
            count++;
            i++;
        }
        col++;
    }
}

void ham_xoan_oc(int n = 0)
{
    int count = 1;
    int top = 0, left = 0, bot = n - 1, right = n - 1;
    while (count <= n * n)
    {
        // duyet tu trai sang phai
        for (int i = left; i <= right; i++)
        {
            a[top][i] = count++;
        }
        top++;

        // duyet tren xuong duoi
        for (int i = top; i <= bot; i++)
        {
            a[i][right] = count++;
        }
        right--;
        // duyet tu phai sang trai
        for (int i = right; i >= left; i--)
        {
            a[bot][i] = count++;
        }
        bot--;
        // duyet tu duoi len tren
        for (int i = bot; i >= top; i--)
        {
            a[i][left] = count++;
        }
        left++;
    }
}
void xuat_ham(int n)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int n = 5;
    // nhap_ham_ngang(n);
    // nhap_ham_nxenke(n);
    // nhap_ham_doc(n);
    // nhap_ham_dxenke(n);
    // nhap_ham_cxuong(n);
    ham_xoan_oc(n);
    xuat_ham(n);
    return 0;
}