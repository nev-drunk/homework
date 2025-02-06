#include <bits/stdc++.h>

using namespace std;

vector<double> x = {20, 21, 22, 23, 24};
vector<double> y = {1.3010, 1.3222, 1.3424, 1.3617, 1.3802};
double a[5][5];

void newton() {//计算差商
    for (int j = 0; j < x.size(); j++) {
        for (int i = 0; i < x.size() - j; i++) {
            if (j == 0) {
                a[j][i] = y[i];
            } 
            else {
                a[j][i] = (a[j-1][i+1] - a[j-1][i]) / (x[i+j] - x[i]);
            }
        }
    }
}

double cal(double x1)
{
    double ans;
    return ans = a[0][0] + a[1][0]*(x1-x[0])+a[2][0]*(x1-x[0])*(x1-x[1])+a[3][0]*(x1-x[0])*(x1-x[1])*(x1-x[2]);
}

int main() {
    newton();
    for (int j = 0; j < x.size(); j++) {
        for (int i = 0; i < x.size() - j; i++) {
            cout <<a[j][i] <<fixed<<setprecision(4)<< "\t";
        }
        cout << endl;
    }
    cout.precision(6);
    cout<<cal(21.4);
    return 0;
}