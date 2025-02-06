#include<bits/stdc++.h>
using namespace std;

int readint(){
    int x;scanf("%d",&x);return x;
}
//这个函数省去了直接进行插入的行为

#define _for(i,a,b) for(int i=(a);i<(b);i++)
//这样定义方便我们直接进行循环

//利用 IO流 对数组进行输入与输出，方便我们进行书写
template<typename T>
ostream& operator<<(ostream& os,const vector<T> &v){
    for (int i = 0; i < v.size(); i++)
    {       
        os<<v[i]<<" ";
    }
    return os;
}

template<typename T>
ostream& operator<<(ostream& os,const set<T>& v){
    for (typename set<T>::iterator it = v.begin(); it!=v.end();it++)
    {
        os<<*it<<" ";
    }
    return os;
}

//可以动态分配内存
template<typename T>
struct Pool
{   
    vector<T*> buf;
    T* createNew(){
        buf.push_back(new T());
        return buf.back();
    }

    void dispose(){
        for (int i = 0; i < buf.size(); i++)
        {
            delete buf[i];
        }
        buf.clear;        
    }
};
