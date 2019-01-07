// include
#include <iostream>

// typedef

// macro
#define REP(index, num) for (auto index = 0; index < num; index++)
#define REP1(index, num) for (auto index = 1; index <= num; index++)

#define MAX_NUM 60

// using namespace 
using namespace std;

// global
int A, B, C, X;

int main()
{
  cin >> A >> B >> C >> X;

  int count = 0;

  REP(aId, A + 1)
  {
    REP(bId, B + 1)
    {
      REP(cId, C + 1)
      {
        if (500 * aId + 100 * bId + 50 * cId == X)
          count++;
      }
    }
  }

  cout << count << endl;
}

