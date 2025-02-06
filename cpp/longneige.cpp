#include <bits/stdc++.h>

using namespace std;

// 计算 exp(-x^2) 的积分，积分区间为 [x0, x1]
double longbeige(double x0, double x1) {
    double h = x1 - x0;
    vector<double> T;
    
    // T1 是 T 的初始值
    double T1 = (h / 2.0) * (exp(-pow(x0, 2)) + exp(-pow(x1, 2)));
    T.push_back(T1);
    
    // 计算 Romberg 表的 T 值
    for (int i = 1; i <= 6; i++) {
        int j = pow(2, i);  // 划分数目
        double sum = 0.0;
        
        for (int k = 1; k < j; k += 2) {
            double x = x0 + k * h / j;
            sum += exp(-pow(x, 2));
        }
        
        double Ti = 0.5 * T.back() + (h / j) * sum;
        T.push_back(Ti);
    }
    
    vector<double> S;
    for (int i = 0; i < 6; i++) {
        double Si = (4.0 * T[i+1] - T[i]) / 3.0;
        S.push_back(Si);
    }

    vector<double> C;
    for (int i = 0; i < 5; i++) {
        double Ci = (16.0 * S[i+1] - S[i]) / 15.0;
        C.push_back(Ci);
    }

    vector<double> R;
    for (int i = 0; i < 4; i++) {
        double Ri = (64.0 * C[i+1] - C[i]) / 63.0;
        R.push_back(Ri);
    }
    return R[0];
}

int main() {
    double x0 = 0.0, x1 = 0.8;
    double result = longbeige(x0, x1);
    cout << "积分结果为: " << result << endl;
}
