#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

// 列主元消去法求解线性方程组
void columnPivotElimination(vector<vector<double>>& A) {
    int n = A.size();

    for (int i = 0; i < n; i++) { // 找主元
        int maxRow = i;

        for (int j = i + 1; j < n; j++) {
            if (abs(A[j][i]) > abs(A[maxRow][i])) {
                maxRow = j;
            }
        }

        // 交换行
        swap(A[i], A[maxRow]);

        // 消元
        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i] / A[i][i];
            for (int k = i; k <= n; k++) {
                A[j][k] -= factor * A[i][k];
            }
        }
    }
}

// 回代求解
vector<double> backSubstitution(const vector<vector<double>>& A) {
    int n = A.size();
    vector<double> x(n, 0.0);

    for (int i = n - 1; i >= 0; i--) {
        x[i] = A[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    return x;
}

int main() {
    int n = 4;
    int m = 5;

    vector<vector<double>> A = {
        {1, -1, 2, -1, -8},
        {2, -2, 3, -3, -20},
        {1, 1, 1, 0, -2},
        {1, -1, 4, 3, 4}
    };

    columnPivotElimination(A);
    vector<double> solution = backSubstitution(A);

    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(2) << solution[i] << endl;
    }

    return 0;
}
