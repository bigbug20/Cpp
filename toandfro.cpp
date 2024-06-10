#include <iostream>

using namespace std;

int main()
{
    int cols;
    while (true)
    {
        // nhap vao so luong cot
        cin >> cols;
        if (cols == 0)
            break;
        // mang 1 chieu ban dau
        char s[201];
        cin >> s;
        // mang can tach thanh 2 chieu
        char c[101][21];
        // tinh toan do dai cua chuoi string nhap vao
        int lens = 0;

        // xuly
        while (s[lens] != '\0')
            lens++;
        // vi tri hien tai trong mang string nhap vao
        int index = 0;
        // chuyen doi 1 chieu sang 2 chieu
        for (int i = 0; i < lens / cols; i++)
        {
            // kiem tra neu hang la so chan thi duyet tu trai sang phai
            if (i % 2 == 0)
            {
                for (int j = 0; j < cols; j++)
                {
                    c[i][j] = s[index];
                    index++;
                }
            }
            else
            {
                // hang le thi duyet tu phai qua trai
                for (int j = cols - 1; j >= 0; j--)
                {
                    c[i][j] = s[index];
                    index++;
                }
            }
        }
        // in ra chuoi string duyet theo cot tu tren xuong
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < lens / cols; j++)
            {
                cout << c[j][i];
            }
        }
        cout << endl;
    }
    return 0;
}