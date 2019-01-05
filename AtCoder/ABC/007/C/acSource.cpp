// include
#include <iostream>
#include <queue>
#include <utility>

// typedef
typedef unsigned long long ull;
typedef unsigned int uint;

// macro
#define REP(index, num) for (auto index = 0; index < num; index++)
#define REP1(index, num) for (auto index = 1; index <= num; index++)

#define ROW 60
#define COLUMN 60
#define INF (int)1e9

// using namespace 
using namespace std;

// global
char c[COLUMN][ROW];

int main()
{
  int R, C;
  cin >> R >> C;
  int sy, sx;
  cin >> sy >> sx;
  int gy, gx;
  cin >> gy >> gx;

  int distance[COLUMN][ROW];

  REP1(rId, R)
    REP1(cId, C)
  {
    cin >> c[cId][rId];
    distance[cId][rId] = INF;
  }
  queue<pair<int, int>> que;
  que.push(make_pair(sx, sy));
  distance[sx][sy] = 0;

  // queueがなくなるまで
  while (que.size())
  {
    pair<int, int> p = que.front(); 
    que.pop();

    // ゴールに達したらloop脱出
    if (p.first == gx && p.second == gy)
      break;

    // 現在地の周辺の座標
    pair<int, int> ps[4];
    ps[0] = make_pair(p.first + 1, p.second);   // right
    ps[1] = make_pair(p.first - 1, p.second);   // left
    ps[2] = make_pair(p.first, p.second + 1);   // top
    ps[3] = make_pair(p.first, p.second - 1);   // bottom

    // 周辺への移動
    for (int pId = 0; pId < 4; pId++)
    {
      int x = ps[pId].first;
      int y = ps[pId].second;
      if (x < 1 || C < x) continue;
      if (y < 1 || R < y) continue;
      if (c[x][y] == '#') continue;
      if (distance[x][y] != INF) continue;

      distance[x][y] = distance[p.first][p.second] + 1; // 一つ前の距離 + 1
      que.push(ps[pId]);  // queueに詰める
    }

  }

  cout << distance[gx][gy] << endl;

}

