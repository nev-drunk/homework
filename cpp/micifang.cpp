#include <bits/stdc++.h>

void micifang(int n)
{
    if (n == 0) return; // 边界情况处理
    if (n == 1) {
        std::cout << "2(0)";
        return;
    }
    bool first = true;
    for (int i = 14; i >= 0; i--) {
        int power_of_two = 1 << i; // 等价于 2 的 i 次方
        if (n >= power_of_two) {
            if (!first) std::cout << "+";
            first = false;//作为是否+的信号
            if (i == 1) std::cout << "2";
            else if (i == 0) std::cout << "2(0)";
            else {
                std::cout << "2(";
                micifang(i);  // 递归处理幂次
                std::cout << ")";
            }
            n -= power_of_two;
        }
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    micifang(n);
    return 0;
}
