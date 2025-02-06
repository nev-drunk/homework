#include<bits/stdc++.h>

using namespace std;

vector<double> x1 = {2, -1, 5};
vector<double> x2 = {-1, 2, -1, -12};
vector<double> x3 = {-1, 2, -1, 11};
vector<double> x4 = {-1, 2, -1};

vector<double> change(vector<double> n1, vector<double> n2) {
    int a = n1.size();
    int b = n2.size();
    double c = 0;
    vector<double> n;

    for (int i = 1; i < a; i++) {
        c = n1[i] / n1[0] * n2[0];  // 这里可以直接处理 n2[i]
        n2[i] = n2[i] - c; 
    }
    n2.back() = n2.back()-(n1.back()/n1[0]*n2[0]);
    for (int j = 1; j < b; j++) {
        n.push_back(n2[j]);
    }
    return n;
}

double calculate(vector<double> a, double b) {
    return (a.back() - a[1] * b) / a[0];
}

int main() {
    x2 = change(x1, x2);
    x3 = change(x2, x3);
    x4 = change(x3, x4);
    vector<double> results(4);
    results[0] = x4.back() / x4[0];
    results[1] = calculate(x3, results[0]);
    results[2] = calculate(x2, results[1]);
    results[3] = calculate(x1, results[2]);
    
    for (const auto& val : results) {
        cout << val << " ";
    }
    
    return 0;
}