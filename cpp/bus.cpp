#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    int a = 0, b = 1, sum = 1; // f(0) + f(1)
    for (int i = 3; i <= n-1; i++) {
        int c = a + b;
        sum += c;
        a = b;
        b = c;
    }
    return sum;
}

int main() {
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    vector<int> dp(n+1);
    dp[1] = 1;dp[2] = 0;
    int max = 1;
    int max_x = 1;
    
    for (int i = 3; i <= n-1; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
        max += dp[i];
        if (i<=x)
        {
            max_x += dp[i];
        } 
    }
    int cha = m - max*a; // 上车人数减去下车人数的总数
    int sum = fibonacci(n-2); //第一次上传人数的次数
    int ans = cha / sum; // 第一次上车的人数
    int sum_m = max_x*a + fibonacci(x-1) * ans; // 计算第 m 站的人数
    cout << sum_m << endl;

    return 0;
}