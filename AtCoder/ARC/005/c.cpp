// include
#include <iostream>
#include <queue>
#include <vector>
//#include <utility>
#include <tuple>

// using namespace 
using namespace std;

// typedef
typedef unsigned long long ull;
typedef unsigned int uint;
//typedef pair<int, int> PII;
typedef tuple<int, int, int> TIII;

// macro
#define REP(index, num) for (auto index = 0; index < num; index++)
#define FOR(index, num) for (auto index = 1; index <= num; index++)

#define MAX_HEIGHT 510
#define MAX_WIDTH 510
#define INF (int)1e9

const bool IsVisited(int inSW, int inSH, int inGW, int inGH);

// global
int H, W;
char c[MAX_WIDTH][MAX_HEIGHT];
bool visitedBlock[MAX_WIDTH][MAX_HEIGHT][3];  // 0:どのマスを訪れたか, 1:どのマスを壊したか, 2:どのマスを2回目に壊したか
//int breakCount[MAX_WIDTH][MAX_HEIGHT];
int sw, sh;
int gw, gh;
int numObstruct = 0;

int main()
{
  cin >> H >> W;
  FOR(hId, H)
  {
    //string str;
    //cin >> str;
    FOR(wId, W)
    {
      cin >> c[wId][hId];// = str[H - wId];
      if (c[wId][hId] == 's')
      {
        sw = wId;
        sh = hId;
      }
      else if (c[wId][hId] == 'g')
      {
        gw = wId;
        gh = hId;
      }
      //else if (c[wId][hId] == '#')
      //{
      //  numObstruct++;
      //}
    }
  }

  // 幅優先探索で最短の移動コストを調べる

  // comment 壊した塀を次のスタート地点にすればよい？
  // 塀の座標すべて登録
  // １回目：sをスタートとして、gまたは壁にぶつかるまで探索
  // ２回目：ある地点で壁が壊されたら、それ以外の壁に対してゴールを設定して再度探索
  // ３回目：gをゴールに設定して再度探索

  bool flag = IsVisited(sw, sh, gw, gh);
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

}

const bool IsVisited(int inSW, int inSH, int inGW, int inGH)
{
  FOR(hId, H)
    FOR(wId, W)
  {
    visitedBlock[wId][hId][0] = false;
    visitedBlock[wId][hId][1] = false;
    visitedBlock[wId][hId][2] = false;
  }

  //breakCount[sw][sh] = 0;

  queue<TIII> que;
  que.push(make_tuple(inSW, inSH, 0));
  visitedBlock[inSW][inSH][0] = true;

  while (que.size())
  {
    TIII curTuple = que.front();
    int curX = get<0>(curTuple);
    int curY = get<1>(curTuple);
    int curBreakCount = get<2>(curTuple);
    que.pop();

    if (curX == inGW && curY == inGH)
      break;

    // 上下左右に移動
    const int addNextX[4] = { 1, 0, -1, 0 };
    const int addNextY[4] = { 0, 1, 0, -1 };
    for (int pId = 0; pId < 4; pId++)
    {
      int nextX = curX + addNextX[pId];
      int nextY = curY + addNextY[pId];
      int nextBreakCount = curBreakCount;
      if ((nextX < 1 || W < nextX) || (nextY < 1 || H < nextY))
        continue;

      // 塀を壊すとき実行
      if (c[nextX][nextY] == '#')
      {
        if (curBreakCount >= 2)
          continue;
        else
        {
          nextBreakCount++;
          visitedBlock[nextX][nextY][nextBreakCount] = true;
        }
      }

      // 訪問済みか
      if (visitedBlock[nextX][nextY][curBreakCount] == true)
        continue;

      visitedBlock[nextX][nextY][nextBreakCount] = true;
      TIII nextTuple = make_tuple(nextX, nextY, nextBreakCount);
      que.push(nextTuple);

    }

  }

  REP(vId, 3)
  {
    if (visitedBlock[inGW][inGH][vId])
      return true;
  }

  return false;

}

