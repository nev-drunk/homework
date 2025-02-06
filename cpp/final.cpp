#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> vec = {1,2,3};
    cout<<vec.size();
    vector<int>::iterator cit = vec.begin();
    cout<<*cit<<endl;
    auto& v2 = vec[1];  //可以自动根据右边的表达式推导出具体类型
    cout<<v2<<endl;
    for(vector<int>::iterator it=vec.begin();it != vec.end();it++)
        cout<<*it<<" ";
    cout<<'\n';
    for(const auto& p:vec){
        cout<<p<<' ';
    }
    cout<<'\n';
    double b = 0;
    int a[] = {1, 2, 3, 4, 5, 6};
    auto sum = [&a]()->double { return (a[0] + a[1] + 0.1); };
    cout<<sum();
    return 0;
}