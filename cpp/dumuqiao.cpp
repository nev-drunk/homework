#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, N;
    cin >> L >> N;
    vector<int> loc(N);
    for (int i = 0; i < N; i++) {
        cin >> loc[i];
    }
    int minTime = 0, maxTime = 0;
    for (int i = 0; i < N; i++) {
        minTime = max(minTime, min(loc[i], L + 1 - loc[i]));
        maxTime = max(maxTime, max(loc[i], L + 1 - loc[i]));
    }
    cout << minTime << " " << maxTime << endl;
    return 0;
}

//总的来说，并没有正确理解题目含义，逻辑上不够严谨，说白了就是没找到解决方案，然后就是求最小值，太复杂，直接min就结束了。