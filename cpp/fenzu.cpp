#include <bits/stdc++.h>
using namespace std;

int key;
int group[100005] = {0}; // 初始化数组为0

void cal(int m) {
    int g = 0;
    int c=0;
    for (int i = 0; i < 100005; i++) {
        if (group[i] > 0) {
            c++;
            if (group[i] > group[g]) {
                g = i;
            }
        }
    }
    if (c < m) {
        if (group[g] % 2 == 0) {
            group[g] /= 2;
        } else {
            group[g] = group[g] / 2 + 1; // 使用整数除法时确保向上取整
        }
        cal(m-1); // 递归调用
    } else if(c==m){
        cout << group[g];
    }else if(c>m){
        cout<<-1;
    }
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
            group[key]++;
    }
    if(n>=m)
        cal(m);
    else
        cout<<-1;
        return 0;
}
