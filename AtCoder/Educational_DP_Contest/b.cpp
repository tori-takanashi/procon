#include <iostream>
#include <algorithm>

#define REP(id, num) for (auto id = 0; id < num; id++) 
#define FOR(id, num) for (auto id = 1; id <= num; id++) 

#define MAX_NUM (int)1e5 + 10
#define INF (int)1e9

using namespace std;

int dp[MAX_NUM];
int h[MAX_NUM];

void chmin(int &a, int b);

int main()
{
  REP(id, MAX_NUM)
    dp[id] = INF;

  int N, K;
  cin >> N >> K;

  REP(id, N)
    cin >> h[id];

  //cin >> h[0];
  dp[0] = 0;

  // 配るDP
  REP(id, N)
  {
    FOR(kId, K)
      chmin(dp[id + kId], dp[id] + abs(h[id + kId] - h[id]));
  }

  cout << dp[N - 1] << endl;
}

void chmin(int &a, int b)
{
  if (a > b)
    a = b;
}

