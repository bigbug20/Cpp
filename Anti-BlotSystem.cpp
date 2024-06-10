#include <iostream>
#include <string>
using namespace std;

string cha, con = "machula", ketqua;
int len = con.length();
string part[5];
int num1 = 0, num2 = 0, result = 0;
int ind = 0;

void tinh()
{
    // reset các tham số tính toán
    result = 0;
    num1 = 0, num2 = 0, result = 0;
    // npos hay còn gọi là null
    if (part[0].find(con) != string::npos)
    {
        // stoi = string to int
        num2 = stoi(part[2]);
        result = stoi(part[4]);
        num1 = result - num2;
        part[0] = to_string(num1);
        // ngược lại của stoi, chuyển về string
    }
    else if (part[2].find(con) != string::npos)
    {
        num1 = stoi(part[0]);
        result = stoi(part[4]);
        num2 = result - num1;
        part[2] = to_string(num2);
    }
    else if (part[4].find(con) != string::npos)
    {
        num1 = stoi(part[0]);
        num2 = stoi(part[2]);
        result = num1 + num2;
        part[4] = to_string(result);
    }
    ketqua = to_string(result);
    for (int i = 0; i < 5; i++)
    {
        if (part[i].find(con) != string::npos)
            part[i] = ketqua;
    }
}

void tach(string s)
{
    // reset giá trị của part
    ind = 0;
    size_t pos = 0;
    size_t found;
    int index = 0;
    // string::npos = null
    // trong khi tìm dấu cách trong string s khác giá trị null và index <4
    while ((found = s.find(' ', pos)) != string::npos && index < 4)
    {
        // s.substr(pos, found - pos) sẽ trả về một phần của chuỗi s, bắt đầu từ vị trí pos và có độ dài là found - pos.
        // Điều này tương đương với việc lấy phần tử từ vị trí pos đến vị trí trước dấu cách (found)
        // Phần tử này sau đó được gán vào mảng part tại chỉ số index, và index được tăng lên sau mỗi lần gán để chuẩn bị cho phần tử tiếp theo.
        part[index++] = s.substr(pos, found - pos);
        pos = found + 1;
    }
    part[index] = s.substr(pos);
    tinh();
}

int main()
{
    int T;
    cin >> T;
    cin.ignore();
    for (int t = 0; t < T; t++)
    {
        ketqua = "";
        string rac;
        getline(cin, rac);
        getline(cin, cha);
        tach(cha);
        for (int i = 0; i < 5; i++)
        {
            cout << part[i];
            if (i < 4)
                cout << " "; // Add spaces between the parts
            else
                cout << endl;
        }
    }
    return 0;
}
