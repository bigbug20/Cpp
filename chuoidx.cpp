#include <iostream>
#include <string>
using namespace std;

int T, len;
string s;
char res[1001];

bool check(int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int main()
{
    cin >> T;
    cin.ignore();
    for (int t = 1; t <= T; t++)
    {
        getline(cin, s);
        len = s.length();
        int count = 0;
        for (int i = 0; i < len; i++)
        {
            for (int j = i; j < len; j++)
            {
                if (check(i, j))
                    count++;
            }
        }

        cout << "#" << t << " " << count << endl;
    }
    return 0;
}