// include
#include <iostream>
#include <vector>
#include <algorithm>

// typedef
typedef unsigned long long ull;
typedef unsigned int uint;

// macro
#define REP(index, num) for (auto index = 0; index < num; index++)

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  
  vector<uint> h(N);
  REP(index, N) 
    cin >> h[index];

  sort(h.begin(), h.end());

  uint minVal = 1e10;
  REP(index, N - (K - 1))
  {
    uint diff = h[index + (K - 1)] - h[index];
    if (minVal > diff)
      minVal = diff;
  }

  cout << minVal << endl;

}

