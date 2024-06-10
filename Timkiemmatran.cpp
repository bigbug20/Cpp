#include <iostream>

using namespace std;

// so luong tc
int T;
// ma tran dau vao
int arr[101][101];
// N la kich thuoc ma tran cha, M la kich thuoc ma tran con, K la tong
int N, M, K;
// toa do x va y can tim
int x, y;

// Ma tran luu lai toan bo ket qua cac tong
int result[4][10001];

// nhap ma tran dau vao
void nhap()
{
    x = 0;
    y = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
}

// ham tinh tong
long tong(int i, int j)
{
    long sum1 = 0;
    for (int u = i; u < i + M; u++)
    {
        for (int v = j; v < j + M; v++)
        {
            sum1 += arr[u][v];
        }
    }
    return sum1;
}

// ham xu ly
void xuly()
{
    int dem = 0;
    for (int i = 0; i <= N - M; i++)
    {
        for (int j = 0; j <= N - M; j++)
        {
            long sumMatrix = tong(i, j);
            // result[0][x] luu hieu hai tong
            if (K - sumMatrix < 0)
            {
                result[0][dem] = sumMatrix - K;
            }
            else
            {
                result[0][dem] = K - sumMatrix;
            }
            // result[1][x] luu hang
            result[1][dem] = i;
            // result[2][x] luu cot
            result[2][dem] = j;
            // result[3][x] luu gia tri
            result[3][dem] = sumMatrix;
            dem++;
        }
    }
    // gia tri gan nhat so voi K
    int gtgn = result[0][0];
    // check tong
    int check = 0;
    x = result[1][0];
    y = result[2][0];

    for (int i = 0; i < dem; i++)
    {
        // so sanh gtgn
        if (result[0][i] < gtgn)
        {
            gtgn = result[0][i];
            x = result[1][i];
            y = result[2][i];
            check = i;
        }
        // neu gtgn bang nhau, so sanh tong
        else if (result[0][i] == gtgn && result[3][i] < result[3][check])
        {
            gtgn = result[0][i];
            x = result[1][i];
            y = result[2][i];
            check = i;
        }
        // neu gtgn, tong bang nhau so sanh hang
        else if (result[0][i] == gtgn && result[3][i] == result[3][check] && result[1][i] < x)
        {
            gtgn = result[0][i];
            x = result[1][i];
            y = result[2][i];
            check = i;
        }
        // neu gtgn,tong, hang bang nhau thi so sanh cot
        else if (result[0][i] == gtgn && result[3][i] == result[3][check] && result[1][i] == x && result[2][i] < y)
        {
            gtgn = result[0][i];
            x = result[1][i];
            y = result[2][i];
            check = i;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> N >> M >> K;
        nhap();
        xuly();
        cout << "#" << t << " " << x << " " << y << endl;
    }
    return 0;
}