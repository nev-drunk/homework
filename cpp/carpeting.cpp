#include <bits/stdc++.h>
using namespace std;

struct Carpet {
    int x;    // 左下角的 x 坐标
    int y;    // 左下角的 y 坐标
    int x1;   // 右上角的 x 坐标
    int y1;   // 右上角的 y 坐标

    // 构造函数，确保 x1 和 y1 正确表示右上角
    Carpet(int x, int y, int width, int height) 
        : x(x), y(y), x1(x + width), y1(y + height) {}
    
    Carpet() {}
};

int main() {
    int n; // 地毯数量
    cin >> n; // 读取地毯数量
    Carpet c[n];

    // 读取地毯的信息
    for (int i = 0; i < n; i++) {
        int width, height;
        cin >> c[i].x >> c[i].y >> width >> height;
        c[i] = Carpet(c[i].x, c[i].y, width, height);
    }
    
    int a, b; // 查询的点坐标
    cin >> a >> b; // 所要求点的位置

    // 从下到上遍历地毯，找到覆盖的地毯
    for (int i = n - 1; i >= 0; i--) {
        // 检查点 (a, b) 是否在当前地毯内
        if ((a >= c[i].x && a <= c[i].x1) && (b >= c[i].y && b <= c[i].y1)) {
            cout << i + 1; // 输出第 i + 1 个地毯
            return 0; // 找到后直接返回
        }
    }
    
    cout << -1; // 如果没有找到，输出 -1
    return 0;
}