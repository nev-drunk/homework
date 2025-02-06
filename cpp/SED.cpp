#include<bits/stdc++.h>
using namespace std;

//高斯赛德尔迭代法
vector<double> x1={10,-1,2,0,-11};
vector<double> x2={0,8,-1,3,-11};
vector<double> x3={2,-1,10,0,6};
vector<double> x4={-1,3,-1,11,25};
vector<double> x(4, 0); // 初始化x，大小为4，初始值为0

void diedai(double a,double b,double c,double d,int time=0){
    x[0] = (x1[4] - x1[1]*b - x1[2]*c - x1[3]*d)/x1[0];
    x[1] = (x2[4] - x2[0]*x[0] - x2[2]*c - x2[3]*d)/x2[1];
    x[2] = (x3[4] - x3[0]*x[0] - x3[1]*x[1] - x3[3]*d)/x3[2];
    x[3] = (x4[4] - x4[0]*x[0] - x4[1]*x[1] - x4[2]*x[2])/x4[3];
    time++;
    if(time >= 3) // 设定最大递归次数
        return;
    for (int i = 0; i < 4; i++) {
        cout << x[i] << " "; // 输出x向量的最终值
    }
    cout<<endl;
    diedai(x[0], x[1], x[2], x[3], time); // 递归调用
}

int main() {
    diedai(0, 0, 0, 0, 0); // 初始值全为0
    for (int i = 0; i < 4; i++) {
        cout << x[i] << " "; // 输出x向量的最终值
    }
    cout << endl;
    
    return 0;
}