#include<bits/stdc++.h>
using namespace std;

// 定义下对角线、主对角线、上对角线以及右端项
vector<double> a = {0, -1, -1, -1};  // 下对角线，a[0]没有使用
vector<double> b = {2, 2, 2, 2};     // 主对角线
vector<double> c = {-1, -1, -1};     // 上对角线
vector<double> d = {5, -12, 11, -1}; // 右端项

// 追逐法函数
vector<double> chase(vector<double>& a, vector<double>& b, vector<double>& c, vector<double>& d) {
    int n = b.size();
    vector<double> x(n);

    // 前向消去
    for (int i = 1; i < n; ++i) {
        double m = a[i] / b[i - 1];  // 消去因子
        b[i] -= m * c[i - 1];        // 修改主对角线
        d[i] -= m * d[i - 1];        // 修改右端项
    }

    // 回代求解
    x[n - 1] = d[n - 1] / b[n - 1];  // 最后一行的未知数
    for (int i = n - 2; i >= 0; --i) {
        x[i] = (d[i] - c[i] * x[i + 1]) / b[i];  // 回代
    }

    return x;
}

int main() {
    // 使用追逐法求解
    vector<double> results = chase(a, b, c, d);

    // 输出解
    for (double result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}
