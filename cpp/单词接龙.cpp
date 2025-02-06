#include<bits/stdc++.h>
using namespace std;
const int N=30;
int chu[N];
string t[N],str;
int n,m,maxx;
int gao(string x,string q)//找是否可以相连 
{
	for(int i=x.size()-1;i>=0;i--)//倒的找找到一个就退出这样肯定是最优的 
	{
		if(x[i]==q[0])//如果和匹配开头一样就开始找是否合法 
		{
			int l=i;//当前开始的位置 
			for(int j=0;j<q.size();j++){if(x[l]==q[j])l++;else break;}//如果一样的话就一直找否则就退出来 
			if(l==x.size())return l-i;//如果找完了就算出有多少个是匹配的这个就是重复的值 
		}
	}
	return 0;//没有就返回0回去；
}
void dfs(int fu,string x)
{
	maxx=max(maxx,(int)x.size()-fu);//用字符的长度减去重复的长度 
	for(int i=1;i<=n;i++)
	{
		int duan=0;
		if(chu[i]==2)continue;//如果用过两次就直接跳 
		duan=gao(x,t[i]);//duan为他们重叠的长度 
		if(!duan)continue;//如果为0没重叠就直接跳过 
		chu[i]++;//这个位置标记一下表示用过
		dfs(fu+duan,x+t[i]);//重叠的部分相加字符串更新 
		chu[i]--;//回溯
	}
	return ;//没找有一个匹配就返回
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>t[i];//把每个都存起来 
	cin>>str;
	dfs(0,str);
	cout<<maxx;//最大长度 
	return 0;
}