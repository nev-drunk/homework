#include <bits/stdc++.h>

using namespace std;

class MyString {
public:
    string str; 
    MyString() : str() {}
    MyString(const char* s) : str(s) {}
};

bool operator >(const MyString& a, const MyString& b) {
return (a.str + b.str) > (b.str + a.str); // 比较拼接后的结果
}

int main() {
    int n;
    cin >> n; // 输入字符串数量
    MyString a[n];

    for (int i = 0; i < n; i++) {
        char buffer[100];
        cin >> buffer; // 输入每个字符串
        a[i] = MyString(buffer);
    }

    // 根据自定义的 > 运算符进行排序
    sort(a, a + n, [](const MyString& a, const MyString& b) {
        return a > b;
    });

    for (int i = 0; i < n; i++) {
        cout << a[i].str; // 输出结果
    }
    return 0;
}
