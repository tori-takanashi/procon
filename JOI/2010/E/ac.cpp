#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> PII;

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n) for (int i = 1; i <= n; i++)

#define MAX_HEIGHT 1010
#define MAX_WIDTH 1010
#define INF (int)1e9

int H, W, N;
char blocks[MAX_WIDTH][MAX_HEIGHT];
int transitTime[MAX_WIDTH][MAX_HEIGHT];
int sw[15], sh[15];

const int CountTransitTimeToReachCheese(int inSW, int inSH, int inGW, int inGH);

int main()
{
  cin >> H >> W >> N;

  FOR(hId, H)
    FOR(wId, W)
  {
    cin >> blocks[wId][hId];

    int hardness = blocks[wId][hId] - '0';
    if (blocks[wId][hId] == 'S')
    {
      sw[0] = wId;
      sh[0] = hId;
    }
    else if (1 <= hardness && hardness <= 9)
    {
      sw[hardness] = wId;
      sh[hardness] = hId;
    }

  }

  int totaltransitTime = 0;
  REP(startId, 9)
  {
    totaltransitTime += CountTransitTimeToReachCheese(sw[startId], sh[startId], sw[startId+1], sh[startId+1]);
  }

  cout << totaltransitTime << endl;
}

const int CountTransitTimeToReachCheese(int inSW, int inSH, int inGW, int inGH)
{
  int curW = inSW;
  int curH = inSH;

  FOR(hId, H)
    FOR(wId, W)
    transitTime[wId][hId] = INF;

  queue<PII> que;
  que.push(make_pair(curW, curH));

  transitTime[curW][curH] = 0;

  while (que.size())
  {
    PII p = que.front();
    curW = p.first;
    curH = p.second;
    que.pop();

    int directionNextW[4] = {1, 0, -1, 0};
    int directionNextH[4] = {0, 1, 0, -1};
    for (int id = 0; id < 4; id++)
    {
      int nextW = curW + directionNextW[id];
      int nextH = curH + directionNextH[id];
      if (nextW < 1 || W < nextW) continue;
      if (nextH < 1 || H < nextH) continue;
      if (transitTime[nextW][nextH] != INF) continue;
      if (blocks[nextW][nextH] == 'X') continue;

      que.push(make_pair(nextW, nextH));

      transitTime[nextW][nextH] = transitTime[curW][curH] + 1;

    }

  }

  return transitTime[inGW][inGH];

}

