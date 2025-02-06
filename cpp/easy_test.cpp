#include <bits/stdc++.h>

int a1 = 0;  // 表示当前加油站
double D1, C, D2, P, N;  // D1：两个城市之间距离，C：汽车油箱容量，D2：每升油能行驶的距离，P：起始油价，N：加油站数量
double ans = 0;  // 表示总共花费的油费

double solution(std::vector<std::pair<double, double>> stations, double left, double s) // s：距离终点的距离，left：剩余油量
{
    if (s == 0) {
        std::cout << std::fixed << std::setprecision(2) << ans;
        return -1;
    }

    // 如果无法找到可行路径
    if ((stations[a1 + 1].first - stations[a1].first) > C * D2) {
        std::cout << "No Solution";
        return -1;
    }

    int min = a1 + 1;  // 找到范围内最便宜的加油站
    int i = min;

    while ((stations[i].first - stations[a1].first) <= C * D2 && i <= N+1) {
        if (stations[i].second < stations[min].second) {
            min = i;
        }
        if (stations[min].second < stations[a1].second) {
            break;
        }
        i++;
    }

    // 如果找到更便宜的加油站
    if (stations[min].second < stations[a1].second) {
        double requiredFuel = (stations[min].first - stations[a1].first) / D2;

        // 检查剩余油量是否足够
        if (left >= requiredFuel) {
            left -= requiredFuel;  // 油量足够，不需要加油
        } else {
            ans += (requiredFuel - left) * stations[a1].second;  // 加到刚好到下一个加油站的油量
            left = 0;
        }
        
        a1 = min;  // 移动到找到的加油站
        s = D1 - stations[min].first;  // 更新剩余距离
        solution(stations, left, s);
    }
    // 没有更便宜的加油站，则加满油，然后前往最低价格的加油站
    else {
        ans += (C - left) * stations[a1].second;
        left = C - (stations[min].first - stations[a1].first) / D2;
        a1 = min;
        s = D1 - stations[min].first;
        solution(stations, left, s);
    }
    return ans;
}

int main() {
    std::cin >> D1 >> C >> D2 >> P >> N;
    std::vector<std::pair<double, double>> stations(N + 1);
    stations[0] = std::make_pair(0, P);  // 起点位置和初始油价
    double s = D1;

    for (int i = 1; i <= N; i++) {
        std::cin >> stations[i].first >> stations[i].second;
    }
    stations.push_back(std::make_pair(D1, 0));  // 终点
    solution(stations, 0, D1);
    return 0;
}