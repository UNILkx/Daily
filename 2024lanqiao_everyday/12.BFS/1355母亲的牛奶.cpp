#include <bits/stdc++.h>

using namespace std;

const int N = 21, M = N * N * N;

int A, B, C;
struct node
{
    int a, b, c;
} q[M];
bool st[N][N][N];
int hh = 0, tt = 0;

void insert(int a, int b, int c)
{
    // 当前没被选过
    if (!st[a][b][c])
    {
        q[++tt] = {a, b, c};
        st[a][b][c] = true;
    }
}
void bfs()
{

    q[0] = {0, 0, C};
    st[0][0][C] = true;
    while (hh <= tt)
    {
        // 头部出来
        auto t = q[hh++];
        int a = t.a, b = t.b, c = t.c;
        // a->b,a->c
        insert(a - min(B - b, a), b + min(B - b, a), c);
        insert(a - min(C - c, a), b, c + min(C - c, a));
        // b->a,b->c
        insert(a + min(A - a, b), b - min(A - a, b), c);
        insert(a, b - min(C - c, b), c + min(C - c, b));
        // c->a,c->b
        insert(a + min(A - a, c), b, c - min(A - a, c));
        insert(a, b + min(B - b, c), c - min(B - b, c));
    }
}
int main()
{
    cin >> A >> B >> C;

    bfs();
    for (int c = 0; c <= C; c++)
        for (int b = 0; b <= B; b++)
        {
            if (st[0][b][c])
                cout << c << ' ';
        }
    return 0;
}