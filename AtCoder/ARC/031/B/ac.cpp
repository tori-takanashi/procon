// include
#include <iostream>

// typedef
typedef unsigned long long ull;
typedef unsigned int uint;

// macro
#define REP(index, num) for (auto index = 0; index < num; index++)

#define HEIGHT 10
#define WIDTH 10

// using namespace 
using namespace std;

const bool CanMergeAllIslands(const int inWId, const int inHId, int &inCount, bool inVisitedCells[WIDTH][HEIGHT]);

// global
char a[WIDTH][HEIGHT];
int glCount = 0;

int main()
{
  REP(hId, HEIGHT)
    REP(wId, WIDTH)
  {
    cin >> a[wId][hId];  
    if (a[wId][hId] == 'o')
      glCount++;
  }

  bool flag = false;
  REP(hId, HEIGHT)
    REP(wId, WIDTH)
  {
    if (a[wId][hId] == 'o')
      continue;

    bool visitedCells[WIDTH][HEIGHT] = { false };
    int count = 0;
    a[wId][hId] = 'o';
    flag = CanMergeAllIslands(wId, hId, count, visitedCells);
    a[wId][hId] = 'x';
    
    if (flag)
    {
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";

}

const bool CanMergeAllIslands(const int inWId, const int inHId, int &inCount, bool inVisitedCells[WIDTH][HEIGHT])
{
  // 参照できなければ終了
  if (inHId < 0 || HEIGHT <= inHId)
    return false;
  if (inWId < 0 || WIDTH <= inWId)
    return false;

  if (inVisitedCells[inHId][inWId] == true)
    return false; // 訪問済みなら終了

  inVisitedCells[inHId][inWId] = true;

  if (a[inWId][inHId] == 'o')
    inCount++;
  else
    return false;

  // 上下左右に移動
  bool flag = false;
  flag = CanMergeAllIslands(inWId + 1, inHId, inCount, inVisitedCells);
  flag = CanMergeAllIslands(inWId - 1, inHId, inCount, inVisitedCells);
  flag = CanMergeAllIslands(inWId, inHId + 1, inCount, inVisitedCells);
  flag = CanMergeAllIslands(inWId, inHId - 1, inCount, inVisitedCells);

  if (glCount + 1 == inCount)
    return true;
  else
    return false;
}

