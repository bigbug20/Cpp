#include <iostream>
#include <string>

// dung thuat toan slidingwindow ma cac bai truoc da ap dung
using namespace std;
// chuoi string con
string s_con;
// chuoi string cha
string s_cha;
// do dai chuoi string con
int len_con;
// do dai chuoi string cha
int len_cha;

// kiem tra xem 2 chuoi co giong nhau ko
bool check(int index)
{
    int j = 0;
    int i = 0;

    for (i = index; i < index + len_con; i++)
    {
        if (s_cha[i] != s_con[j])
        {
            return false;
        }
        j++;
    }
    return true;
}

int main()
{

    for (int t = 1; t <= 10; t++)
    {
        string tc;
        // nhap vao
        getline(cin, tc);
        getline(cin, s_con);
        getline(cin, s_cha);
        // do dai 2 chuoi string
        len_con = s_con.length();
        len_cha = s_cha.length();
        // bien dem so luong chuoi con trong chuoi cha
        int count1 = 0;
        for (int i = 0; i <= len_cha - len_con; i++)
        {
            if (check(i))
            {
                count1++;
            }
        }
        cout << "#" << t << " " << count1 << endl;
    }
    return 0;
}