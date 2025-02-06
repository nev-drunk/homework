#include<bits/stdc++.h>

struct Point
{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
};
typedef Point Vector;
Vector operator+ (const Vector& A,const Vector& B){return Vector(A.x+B.x,A.y+B.y);}

#define _for(i,a,b) for(int i=(a);i<(b);i++)

int R,C;
const int MAXC = 16;
char grid[MAXC][MAXC];

inline bool valid(const Point &p){return p.x >= 0 && p.x<R && p.y>0 && p.y<C;} //内联函数

int main()
{
    char buf[MAXC];
    int buflen;
    const Vector dLeft(0,-1),dUp(-1,0),dRight(0,1),dDown(1,0);
    for(int t=1; scanf("%d%d",&R,&C) == 2 && R;t++){
        std::vector<Point> eligible;
        std::vector<int> down,across; //定义横竖满足要求的向量
        if (t>1) puts(""); // 当换行符使用
        printf("puzzle #%d:\n",t);
        _for(i,0,R){
            scanf("%s",grid[i]);
            _for(j,0,C){
                if (grid[i][j] == '*') continue;
                Point p(i,j),left = p+dLeft,up = p+dUp; //表示位置
                bool isCross = !valid(left) || grid[left.x][left.y] == '*'; //判断是否出界或者在左边界是*
                bool isDown  = !valid(up) || grid[up.x][up.y] == '*';
                if(isCross) across.push_back(eligible.size());
                if(isDown) down.push_back(eligible.size()); //表示第几个点，将其存入
                if(isDown || isCross) eligible.push_back(p);
            }
        }
        puts("Across");
        for(auto n: across)
        {
            buflen = 0, memset(buf,0,sizeof(buf));//对数组及逆行初始化
            Point p = eligible[n];
            while (valid(p) && grid[p.x][p.y] != '*')
            {
                buf[buflen++] = grid[p.x][p.y];
                p = p + dRight;
            }
            printf("%3d.%s\n",n+1,buf);
        }
        puts("Down");
        for(auto n: down){
            buflen = 0, memset(buf,0,sizeof(buf));
            Point p = eligible[n];
            while (valid(p)&&grid[p.x][p.y] != '*')
            {
                buf[buflen++] = grid[p.x][p.y];
                p= p + dDown;
            }
            printf("%3d.%s\n",n+1,buf);
        }
    }

    return 0;
}