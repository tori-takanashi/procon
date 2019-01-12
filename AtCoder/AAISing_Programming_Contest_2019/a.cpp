// include
#include <iostream>

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

// global
int N;
int H, W;

int main()
{
  cin >> N >> H >> W;

  cout << (N - H + 1) * (N - W + 1) << endl;

}

