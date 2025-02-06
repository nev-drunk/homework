#include <bits/stdc++.h>
using namespace std;

// 计算给定函数的值，此处为 e^(-x^2)
double func(double x) {
    return exp(-pow(x, 2));
}

// 龙贝格积分法
double longbeige(double x0, double x1) {
    // 初始步长
    double h = x1 - x0;
    vector<double> T;
    
    // 初始的T1计算
    double T1 = (h / 2) * (func(x0) + func(x1));
    T.push_back(T1);
    
    // 迭代计算Ti
    for (int i = 1; i <= 5; i++) {
        int num_intervals = pow(2, i); // 当前分段数
        double step = h / num_intervals; // 当前步长
        
        // 计算奇数点上的函数值之和
        double sum_fx = 0.0;
        for (int k = 1; k < num_intervals; k += 2) {
            sum_fx += func(x0 + k * step);
        }
        
        // 当前Ti值
        double Tn = 0.5 * T.back() + step * sum_fx;
        T.push_back(Tn);
    }

    // 返回最后一个Tn，即积分结果
    return T.back();
}

int main() {
    double x0 = 0.0, x1 = 0.8;
    cout << "积分结果: " << longbeige(x0, x1) << endl;
    return 0;
}
