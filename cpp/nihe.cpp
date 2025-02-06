#include <bits/stdc++.h>
using namespace std;

// 二次拟合
vector<double> ercinihe(double x[], double y[], int n)
{
    double a[5] = {0}; // 用于存储矩阵的元素
    double b[3] = {0}; // 表示右侧常数项的系数
    a[0] = n;
    for (int i = 0; i < n; i++)
    {
        a[1] += x[i];
        a[2] += x[i] * x[i];
        a[3] += x[i] * x[i] * x[i];
        a[4] += x[i] * x[i] * x[i] * x[i];

        b[0] += y[i];
        b[1] += x[i] * y[i];
        b[2] += x[i] * x[i] * y[i];
    }
    // 构造增广矩阵
    vector<vector<double>> matrix = {
        {double(a[0]), double(a[1]), double(a[2]), double(b[0])},
        {double(a[1]), double(a[2]), double(a[3]), double(b[1])},
        {double(a[2]), double(a[3]), double(a[4]), double(b[2])}};
    
    // 高斯消元法
    int n_vars = 3; // 方程数
    for (int i = 0; i < n_vars; i++)
    {
        // 寻找主元
        int max_row = i;
        for (int k = i + 1; k < n_vars; k++)
        {
            if (abs(matrix[k][i]) > abs(matrix[max_row][i]))
                max_row = k;
        }
        // 交换当前行和主元行
        swap(matrix[i], matrix[max_row]);

        // 消元
        for (int k = i + 1; k < n_vars; k++)
        {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j <= n_vars; j++)
            {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    // 回代求解
    vector<double> coefficients(n_vars);
    for (int i = n_vars - 1; i >= 0; i--)
    {
        coefficients[i] = matrix[i][n_vars] / matrix[i][i];
        for (int j = i - 1; j >= 0; j--)
        {
            matrix[j][n_vars] -= matrix[j][i] * coefficients[i];
        }
    }

    return coefficients;
}
//曲线拟合

/*
在一次拟合的基础上，再次计算系数即可
*/


vector<double> qvxiannihe(double x[], double y[], int n)
{
    double a[5] = {0}; // 用于存储矩阵的元素
    double b[3] = {0}; // 表示右侧常数项的系数
    a[0] = n;
    // 一次拟合
     for (int i = 0; i < n; i++)
    {
        a[1] += x[i];
        a[2] += x[i] * x[i];

        b[0] += log(y[i]);
        b[1] += x[i] * log(y[i]);
    }
    // 构造增广矩阵
    vector<vector<double>> matrix = {
        {double(a[0]), double(a[1]), double(b[0])},
        {double(a[1]), double(a[2]), double(b[1])}};
    // 高斯消元法
    int n_vars = 2; // 方程数
    for (int i = 0; i < n_vars; i++)
    {
        // 寻找主元
        int max_row = i;
        for (int k = i + 1; k < n_vars; k++)
        {
            if (abs(matrix[k][i]) > abs(matrix[max_row][i]))
                max_row = k;
        }
        // 交换当前行和主元行
        swap(matrix[i], matrix[max_row]);

        // 消元
        for (int k = i + 1; k < n_vars; k++)
        {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j <= n_vars; j++)
            {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
    // 回代求解
    vector<double> coefficients(n_vars);
    for (int i = n_vars - 1; i >= 0; i--)
    {
        coefficients[i] = matrix[i][n_vars] / matrix[i][i];
        for (int j = i - 1; j >= 0; j--)
        {
            matrix[j][n_vars] -= matrix[j][i] * coefficients[i];
        }
    }
    coefficients[0] = exp(coefficients[0]);
    return coefficients;
}



int main()
{
    double x[] = {1,1.5,2,2.5,3,3.5,4,4.5,5,5.5,6,6.5,7,7.5,8};
    double y[] = {33.4,79.5,122.65,159.05,189.15,214.15,238.65,252.5,267.55,280.5,296.65,301.4,310.4,318.15,325.15};
    int n = 15;
    vector<double> coefficients = ercinihe(x, y, n);
    cout << "二次拟合的系数: ";
    for (double coeff : coefficients)
        cout << coeff << " ";
    cout << endl;
    vector<double> coefficient = qvxiannihe(x, y, n);
    cout << "曲线拟合的系数: ";
    for (double coeff : coefficient)
        cout << coeff << " ";
    return 0;
}