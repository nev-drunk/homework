#include<bits/stdc++.h>

using namespace std;

int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int fibonaqici(int x){
    vector<int> n;
    n.push_back(0);
    n.push_back(1);
    for (int i = 0; i < x-2; i++)
    {
        n.push_back(n[i]+n[i+1]);//加上前面两个数就是斐波那契数列
    }
    return n.back(); //返回循环次数后所得的值
}

int main(){
    int n;
    cin>>n;
    cout<<fibonaqici(n)<<endl;
    return 0;
}