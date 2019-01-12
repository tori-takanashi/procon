// include
#include <iostream>
#include <algorithm>

// using namespace 
using namespace std;

// typedef
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> PII;

// macro
#define REP(index, num) for (auto index = 0; index < num; index++)
#define FOR(index, num) for (auto index = 1; index <= num; index++)

#define MAX_NUM 110
#define INF (int)1e9

// global
int N;
int A, B;
int P[MAX_NUM];

int main()
{
  cin >> N;
  cin >> A >> B;

  int lowerA = 0;
  int upperAp1LowerB = 0;
  int upperBp1 = 0;

  REP(nId, N)
  {
    cin >> P[nId];

    if (P[nId] <= A)
      lowerA++;
    else if (A + 1 <= P[nId] && P[nId] <= B)
      upperAp1LowerB++;
    else if (B + 1 <= P[nId])
      upperBp1++;
  }

  int minVal = min(lowerA, min(upperAp1LowerB, upperBp1));

  cout << minVal << endl;

}

