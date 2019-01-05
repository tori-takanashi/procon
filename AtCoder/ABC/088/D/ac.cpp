// include
#include <iostream>
#include <queue>
#include <utility>

// using namespace 
using namespace std;

// typedef
typedef unsigned long long ull;
typedef unsigned int uint; 
typedef pair<int, int> PII;

// macro
#define REP(index, num) for (auto index = 0; index < num; index++)
#define FOR(index, num) for (auto index = 1; index <= num; index++)

#define MAX_HEIGHT 60
#define MAX_WIDTH 60
#define INF (int)1e9

const int CountShortestDistance();

// global
int H, W;
char s[MAX_WIDTH][MAX_HEIGHT];
int whiteCount = 0;

int main()
{
  cin >> H >> W;
  
	FOR(hId, H)
    FOR(wId, W)
  {
    cin >> s[wId][hId];
    if (s[wId][hId] == '.')
      whiteCount++;
  }

  // 幅優先探索で最短の移動コストを調べる
  int cost = CountShortestDistance();
  if (cost != INF)
    cout << whiteCount - (CountShortestDistance() + 1) << endl;
  else
    cout << -1 << endl;

}

const int CountShortestDistance()
{
  int distance[MAX_WIDTH][MAX_HEIGHT];

  FOR(hId, H)
    FOR(wId, W)
    distance[wId][hId] = INF;

  int sw = 1, sh = 1;
  int gw = W, gh = H;

  distance[sw][sh] = 0;

  queue<PII> que;
  que.push(make_pair(sw, sh));

  while (que.size())
  {
    PII curPair = que.front();
    int curX = curPair.first;
    int curY = curPair.second;
    que.pop();

    // 上下左右に移動
    const int addNextX[4] = {1, 0, -1, 0};
    const int addNextY[4] = {0, 1, 0, -1};
    for (int pId = 0; pId < 4; pId++)
    {
      int nextX = curX + addNextX[pId];
      int nextY = curY + addNextY[pId];
      PII nextPair = make_pair(nextX, nextY);
      if ((nextX < 1 || W < nextX) || (nextY < 1 || H < nextY) 
        || s[nextX][nextY] == '#' || distance[nextX][nextY] != INF)
        continue;
      que.push(nextPair);
      distance[nextX][nextY] = distance[curX][curY] + 1;
    }

  }

  return distance[gw][gh];

}

