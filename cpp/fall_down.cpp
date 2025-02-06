#include <iostream>
#include <cmath>

// 检查小球是否进入车子的计数
int count_balls(double h, double s, double v, double l, double k, int n) {
    int count = 0;   // 小车内小球的计数
    double g = 10.0; // 重力加速度

    // 遍历每个小球
    for (int i = 0; i <= n; ++i) {
        double left = s - i + 1;       // 当前小球的左边界
        double right = s + l - i + 1; // 当前小球的右边界

        // 计算到达车子边界的时间
        double t_left = left / v;
        double t_right = right / v;

        // 计算高度
        double h_left = h - 0.5 * g * t_left * t_left;
        double h_right = h - 0.5 * g * t_right * t_right;

        // 如果任意边界的高度落在车子范围内，计数加一
        if (h_left >= 0 && h_right <= k) {
            count++;
        }
    }

    return count;
}

int main() {
    double h, s, v, k, l;
    int n;

    // 输入小球与地面的高度，初始位置，每次下落高度，前进速度，小车高度，小球数量
    std::cin >> h >> s >> v >> l >> k >> n;

    // 调用函数并输出结果
    int result = count_balls(h, s, v, l, k, n);
    std::cout << result << std::endl;

    return 0;
}
