#include <iostream>
#include <vector>

using namespace std;

// LU分解
bool luDecomposition(const vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();
    L.assign(n, vector<double>(n, 0.0));
    U.assign(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; ++i) {
        // 上三角矩阵 U
        for (int j = i; j < n; ++j) {
            double sum = 0.0;
            for (int k = 0; k < i; ++k) {
                sum += L[i][k] * U[k][j];
            }
            U[i][j] = A[i][j] - sum;
        }

        // 下三角矩阵 L
        for (int j = i; j < n; ++j) {
            if (i == j) {
                L[i][i] = 1.0; // 对角线为1
            } else {
                double sum = 0.0;
                for (int k = 0; k < i; ++k) {
                    sum += L[j][k] * U[k][i];
                }
                L[j][i] = (A[j][i] - sum) / U[i][i];
            }
        }
    }
    return true;
}

// 前向替换
vector<double> forwardSubstitution(const vector<vector<double>>& L, const vector<double>& b) {
    int n = L.size();
    vector<double> y(n);
    
    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        for (int j = 0; j < i; ++j) {
            sum += L[i][j] * y[j];
        }
        y[i] = b[i] - sum;
    }
    return y;
}

// 后向替换
vector<double> backwardSubstitution(const vector<vector<double>>& U, const vector<double>& y) {
    int n = U.size();
    vector<double> x(n);
    
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0.0;
        for (int j = i + 1; j < n; ++j) {
            sum += U[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / U[i][i];
    }
    return x;
}

// 主函数
int main() {
    // 示例矩阵 A 和向量 b
    vector<vector<double>> A = {
        {4, -2, -4},
        {-2, 17, 10},
        {-4, 10, 9}
    };
    
    vector<double> b = {10, 3, 7};
    
    vector<vector<double>> L, U;

    // 进行LU分解
    if (luDecomposition(A, L, U)) {
        // 前向替换
        vector<double> y = forwardSubstitution(L, b);
        // 后向替换
        vector<double> x = backwardSubstitution(U, y);
        
        // 输出结果
        for (double xi : x) {
            cout << xi << " ";
        }
        cout << endl;
    } else {
        cout << "LU分解失败。" << endl;
    }   
    return 0;
}