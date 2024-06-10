#include <iostream>
using namespace std;

int T, res;
char arr[10][10];

// Trong ngôn ngữ lập trình C++ (và nhiều ngôn ngữ lập trình khác), ký tự số và giá trị số nguyên của nó trong bảng mã ASCII là khác nhau.
// Ví dụ, ký tự '0' có giá trị ASCII là 48, ký tự '1' có giá trị ASCII là 49, và tiếp tục như vậy.

// Do đó, khi bạn có một ký tự số (như '1', '2', '3', ...), để chuyển đổi nó thành giá trị số nguyên tương ứng,
// bạn cần trừ giá trị ASCII của ký tự '0' (tức là 48) từ ký tự đó. Ví dụ:

//'1' - '0' sẽ cho giá trị số nguyên 1.
//'2' - '0' sẽ cho giá trị số nguyên 2.

void duyet_33(int t, int i, int j)
{
    int seen[10] = {0}; // Mảng để theo dõi các số đã thấy
    for (int m = i; m < i + 3; m++)
    {
        for (int n = j; n < j + 3; n++)
        {
            if (arr[m][n] != '.')
            {
                int num = arr[m][n] - '0';
                if (seen[num] == 1)
                {
                    res = 0;
                    return;
                }
                seen[num] = 1;
            }
        }
    }
}

void duyet_cot(int t)
{
    for (int j = 0; j < 9; j++)
    {
        int seen[10] = {0}; // Mảng để theo dõi các số đã thấy
        for (int i = 0; i < 9; i++)
        {
            if (arr[i][j] != '.')
            {
                int num = arr[i][j] - '0';
                if (seen[num] == 1)
                {
                    res = 0;
                    return;
                }
                seen[num] = 1;
            }
        }
    }

    if (res != 0)
    {
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                duyet_33(t, i, j);
                if (res == 0)
                    return;
            }
        }
    }
}

void duyet_hang(int t)
{
    res = 1;
    for (int i = 0; i < 9; i++)
    {
        int seen[10] = {0}; // Mảng để theo dõi các số đã thấy
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] != '.')
            {
                int num = arr[i][j] - '0';
                if (seen[num] == 1)
                {
                    res = 0;
                    return;
                }
                seen[num] = 1;
            }
        }
    }

    if (res != 0)
    {
        duyet_cot(t);
    }
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; ++j)
            {
                cin >> arr[i][j];
            }
        }
        duyet_hang(t);
        cout << "#" << t << " " << res << endl;
    }
    return 0;
}
