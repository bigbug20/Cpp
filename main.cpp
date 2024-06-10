#include <iostream>
#include <iomanip>
#include <math.h>        // thư viện tính toán
#include <bits/stdc++.h> // thư viện vecto
#include <set>           // thư viện set
#include <map>           // thư viện map
#include <algorithm>     // thư viện thuật toán tìm kiếm

using namespace std;

// Số nguyên: int, long long
// Số thực: float, double
// Tạo hàm:
// void tên_hàm(đối số (đối số và kiểu dữ liệu đầu vào phải giống nhau)){
// code block và return tương tự Py;
//}
// Đọc file: freopen("input.txt","r",stdin);

// Binary search: Tìm kiếm nhị phân, phải sắp xếp thứ tự
// bool binary_search(int a[], int l, int r, int x)
// {
//     if (l > r)
//         return false;
//     int m = (l + r) / 2;
//     if (a[m] == r)
//         return true;
//     else if (a[m] < x)
//         return binary_search(a, m + 1, r, x);
//     else
//         return binary_search(a, l, m - 1, x);
// }

int main()
{
    // độ chính xác của float trong c++ bằng thư viện <iomanip>
    // vd cout << fixed << setprecision(n) << a << endl;
    // float a;
    // cout << "Nhap gia tri cua a: ";
    // cin >> a;
    // cout << fixed << setprecision(4) << a << endl;
    // return 0;
    // với thư viện math.h
    // abs (x): trị tuyệt đối
    // pow(a,b): tính a^b, kết quả sẽ là double
    // sqrt(x): tính căn, kết quả là double
    // getline(cin, s) : nhập sâu kí tự có dấu " ",
    // cin.ignore(): xóa dấu enter nếu có cin đứng trước getline để tránh trôi lệnh
    // VD: string s;
    //     getline(cin, s);
    //     cout << s << endl;
    // hàm compare : a.compare(b)
    // stoi() : chuyển chuỗi thành số interger VD: s = "123"; int x = stoi(s)
    // stoll():  chuyển chuỗi thành số long long
    // to_string(): chuyển kiểu dữ liệu thành string
    // tách sâu kí tự:
    // string s = "Em be Map thui";
    // stringstream ss(s);
    // string tmp;
    // while (ss >> tmp)
    // {
    //     cout << tmp << endl;
    // }
    // return 0;
    // vector<int> v;
    // // vector<int> v(n,value);
    // //  pushback(): đẩy phần tử vào vecto
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);
    // // size(): tìm kích thước
    // // duyệt bằng interator
    // for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    // // dịch: vector(giá trị là int) khai báo 1 iterator tên là it bắt đầu trỏ vào
    // // giá trị đầu tiên của vector, điều kiện lặp là it khác giá trị kết thúc của vector,
    // {
    //     cout << *it << endl;
    //     // *it là in ra giá trị vì it chỉ là 1 địa chỉ
    // }
    // pair<datatype1, datatype2> v = {};
    // set <datatype> s;
    // set.insert();set.find();set.count();set.erase();
    // set k lưu các phần tử giống nhau và phần tử cuối cùng của set hay vecto là
    // rbegin()
    // multiset(): cho phép các phần tử giống nhau
    // unordered_set(): k sắp xếp phần tử
    // map là các cặp key:value : map<datatype1, datatype2> mp
    // insert phần tử : mp[key] = value hoặc mp.insert({key, value})
    // duyệt map :
    // for (map<int>::iterator it = mp.begin(); it != mp.end(); it++){
    //     cout << (*it).first << " " <<(*it).second << endl;}
    // tìm kiếm trong map: count() hoặc find() (Chỉ kiểm tra được key)
    // Linear search: tìm kiếm tuyến tính (Duyệt tất cả các phần tử trong mảnh)
    // Binary search: Tìm kiếm nhị phân, phải sắp xếp thứ tự
    // Tim vi tri dau tien cua 1 phan tu x trong 1 mang da sap xep
    // con trỏ NULL hay nullptr
    int a;
    cout << (&a) << endl;
    int *ptr;
    ptr = &a;
    cout << (*ptr) << endl;
    return 0;
}
