#include<bits/stdc++.h>

/*给定n个整数，从中选出k个数相加，然后求这些和中有多少个是素数。*/

int n = 0, k = 0;
int count = 0;//表示sum为素数的个数

bool isPrime(int a){
    if(a < 2){
        return false;
    }
    for(int i = 2; i < a; i++){
        if(a % i == 0){
            return false;
        }
    }
    return true;
}

int dfs(int a[], int index, int sum, int num){
   for(int i = index; i < n; i++){
    if(num == k){
        if(isPrime(sum + a[i])){
            count++;
        }
    }
    if (num < k)
    {
        dfs(a, i + 1, sum+a[i], num + 1);//递归算出所有k个数相加的结果
    }
    }
    return sum;
}

int main(){
    std::cin >> n >> k;//表示输入n个数，并从中选出k个数
    int a[n];
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    int sum = 0;
    int num = 1;
    dfs(a, 0, sum, num);
    std::cout << count << std::endl;
    return 0;
}

/* 在所给代码 仍有很多开源优化的地方*/