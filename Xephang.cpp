#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define MAX_N 1001

int T, N;
int Height[MAX_N], TallerCnt[MAX_N];
int ret[MAX_N];

void sort()
{
    int i, j, tmp;
    for (i = 0; i < N - 1; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (Height[j] < Height[i] || (Height[j] == Height[i] && TallerCnt[j] < TallerCnt[i]))
            {
                tmp = Height[i]; // sap xep tu be den lớn, nếu 2 số bằng nhau sẽ sắp xếp theo thứ tự cao hơn đứng trước
                Height[i] = Height[j];
                Height[j] = tmp;
                tmp = TallerCnt[i];
                TallerCnt[i] = TallerCnt[j];
                TallerCnt[j] = tmp;
            }
        }
    }
}

int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> Height[i];
            ret[i] = -1; // chua dat ng nao vao
        }
        for (int i = 0; i < N; i++)
        {
            cin >> TallerCnt[i];
        }

        sort();

        int cnt;
        for (int i = 0; i < N; i++)
        {
            cnt = 0;

            for (int j = 0; j < N; j++)
            {
                if (ret[j] == -1)
                { // nếu vị trí đó trống, biến đếm sẽ tăng lên
                    cnt++;
                    if (cnt > TallerCnt[i])
                    {                       // khi biến đếm lớn hơn số người cao hơn đằng trước
                        ret[j] = Height[i]; // đặt biến đó tại vị trí trống và dừng vòng lặp
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            cout << ret[i] << " ";
        }
        cout << endl;
    }
    return 0;
}