#include <iostream>
#include <string>

using namespace std;

void tach(string s)
{
    // reset giá trị của part
    int n;
    string part[n];
    int ind = 0;
    size_t pos = 0;
    size_t found;
    int index = 0;
    // string::npos = null
    // trong khi tìm dấu cách trong string s khác giá trị null và index <4
    while ((found = s.find(' ', pos)) != string::npos && index < n - 1)
    {
        // s.substr(pos, found - pos) sẽ trả về một phần của chuỗi s, bắt đầu từ vị trí pos và có độ dài là found - pos.
        // Điều này tương đương với việc lấy phần tử từ vị trí pos đến vị trí trước dấu cách (found)
        // Phần tử này sau đó được gán vào mảng part tại chỉ số index, và index được tăng lên sau mỗi lần gán để chuẩn bị cho phần tử tiếp theo.
        part[index++] = s.substr(pos, found - pos);
        pos = found + 1;
    }
    part[index] = s.substr(pos);
}