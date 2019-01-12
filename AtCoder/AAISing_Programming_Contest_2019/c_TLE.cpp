// include
#include <iostream>
#include <string>

// using namespace 
using namespace std;

// typedef
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> PII;

// macro
#define REP(index, num) for (auto index = 0; index < num; index++)
#define FOR(index, num) for (auto index = 1; index <= num; index++)

#define MAX_HEIGHT 500
#define MAX_WIDTH 500
#define INF (int)1e9

// global
int H, W;
char s[MAX_WIDTH][MAX_HEIGHT];
bool visited[MAX_WIDTH][MAX_HEIGHT];

inline const int CountAlternatelyWAndB(const int &wId, const int &hId, const char &preState, const char &firstState);

int main()
{
  cin >> H >> W;

  FOR(hId, H)
  {
    string str;
    cin >> str;
    FOR(wId, W)
    {
      s[wId][hId] = str[wId - 1];
    }
  }

  int sumCount = 0;
  FOR(hId, H)
    FOR(wId, W)
  {
    if (s[wId][hId] == '.')
      continue;

    FOR(hId2, H)
      FOR(wId2, W)
      visited[wId2][hId2] = false;

    sumCount += CountAlternatelyWAndB(wId + 1, hId, s[wId][hId], s[wId][hId]);
    sumCount += CountAlternatelyWAndB(wId, hId + 1, s[wId][hId], s[wId][hId]);
    sumCount += CountAlternatelyWAndB(wId - 1, hId, s[wId][hId], s[wId][hId]);
    sumCount += CountAlternatelyWAndB(wId, hId - 1, s[wId][hId], s[wId][hId]);
  }

  cout << sumCount << endl;

}

inline const int CountAlternatelyWAndB(const int &wId, const int &hId, const char &preState, const char &firstState)
{
  int count = 0;
  int currentState = s[wId][hId];

  if (wId < 1 || W < wId) return 0;
  if (hId < 1 || H < hId) return 0;
  if (visited[wId][hId]) return 0;

  visited[wId][hId] = true;

  if (currentState != preState)
  {
    if (currentState != firstState)
      count++;

    count += CountAlternatelyWAndB(wId + 1, hId, currentState, firstState);
    count += CountAlternatelyWAndB(wId, hId + 1, currentState, firstState);
    count += CountAlternatelyWAndB(wId - 1, hId, currentState, firstState);
    count += CountAlternatelyWAndB(wId, hId - 1, currentState, firstState);
  }
  else
    return 0;

  return count;
}
