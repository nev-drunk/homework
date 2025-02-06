#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n; //输入想要找的数
    int re = 0,loc = n;
    for (int i = 0; ; i++)
    {
        int count = i*(i+1)/2;
        if(count>=n) {
            re = i; //找到对角线位置
            loc = n - (i*(i-1)/2); //找到是第几个数
            break;
        }
    }
    int s = loc, m = re - loc + 1;//分子分母
    if(re%2==0)
        cout<<s<<"/"<<m<<endl;
    else
        cout<<m<<"/"<<s<<endl;
    return 0;
}