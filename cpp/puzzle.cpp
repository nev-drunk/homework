#include<bits/stdc++.h>

using namespace std;

//用一下结构表示坐标和向量
struct Point
{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};
typedef Point Vector;

const int GSize = 5;
vector<string> grid;
Point epos;
map<char, Vector> DIRS;

//重载+运算符
Point operator+(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}

//作为一个判断条件，判断是否越界
bool valid(const Point &p) {
    return (p.x >= 0 && p.x < GSize && p.y >= 0 && p.y < GSize);
}

void printGrid() {
    for (int i = 0; i < GSize; i++) {
        for (int j = 0; j < GSize; j++) {
            if (j) cout << ' ';
            cout << grid[i][j];
        }
        cout << endl;
    }
}

bool tryMove(char cmd) {
    if (!DIRS.count(cmd)) return false;
    Point p = epos + DIRS[cmd];
    if (!valid(p)) return false;
    swap(grid[p.x][p.y], grid[epos.x][epos.y]);
    epos = p;
    return true;
}

int main() {
    int t = 1;
    string line;
    DIRS['A'] = Vector(-1, 0); // 上
    DIRS['B'] = Vector(1, 0);  // 下
    DIRS['L'] = Vector(0, -1); // 左
    DIRS['R'] = Vector(0, 1);  // 右
    
    while (true) {
        grid.clear();
        epos.x = -1;
        epos.y = -1;

        for (int i = 0; i < GSize; i++) {
            getline(cin, line);//读取一行文本
            if (line == "Z") return 0; // 输入 Z 终止程序
            assert(line.size() == GSize); // 每行必须有 GSize 个字符，就是一种调试函数
            for (int j = 0; j < GSize; j++) {
                if (line[j] == ' ') {
                    assert(epos.x == -1 && epos.y == -1); // 确保只有一个空格
                    epos.x = i;
                    epos.y = j;
                }
            }
            grid.push_back(line); // 保存每行的输入
        }

        string moves;
        while (true) {
            getline(cin, line);
            assert(!line.empty()); // 确保输入不为空
            bool end = *(line.rbegin()) == '0'; // 判断最后是否是 '0'
            if (!end) moves.append(line);//在最后面添加
            else moves.append(line, 0, line.size() - 1); // 不包括最后的 '0'
            if (end) break; // 结束指令输入
        }

        bool legal = true;
        for (int i = 0; i < moves.size(); i++) {
            if (!tryMove(moves[i])) { 
                legal = false;
                break; // 如果移动不合法，停止操作
            }
        }

        if (t > 1) cout << endl; // 输出拼图之间加换行
        cout << "Puzzle #" << t++ << ":" << endl;
        if (legal) printGrid();
        else cout << "This puzzle has no final configuration." << endl;
    }

    return 0;
}