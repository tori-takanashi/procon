// include
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// typedef
typedef unsigned int uint;

using namespace std;

void Set753Numbers(uint inNum, uint inNumSize, vector<uint> &inAll753Numbers);

int main()
{
  int N;
  cin >> N;

  vector<uint> all753Numbers;
  for (auto index = 0; index <= 9; index++)
    Set753Numbers(0, index, all753Numbers);  //753数をセット

  sort(all753Numbers.begin(), all753Numbers.end());

  // 要素がNを超えるまでカウント
  int count = 0;
  for (auto &&val : all753Numbers)
  {
    if (val <= N)
      count++;
    else
      break;
  }
  cout << count << endl;
}

void Set753Numbers(uint inNum, uint inNumSize, vector<uint> &inAll753Numbers)
{
  uint num = inNum * 10;  //一桁ずらす

  if (inNumSize)
  {
    Set753Numbers(num + 3, inNumSize - 1, inAll753Numbers);
    Set753Numbers(num + 5, inNumSize - 1, inAll753Numbers);
    Set753Numbers(num + 7, inNumSize - 1, inAll753Numbers);
  }
  else
  {
    bool flag3 = false;
    bool flag5 = false;
    bool flag7 = false;

    uint cpInNum = inNum;
    while (cpInNum)
    {
      switch (cpInNum % 10)
      {
      case 3:
        flag3 = true;
        break;
      case 5:
        flag5 = true;
        break;
      case 7:
        flag7 = true;
        break;
      default:
        break;
      }
      cpInNum /= 10;
    }

    // 753数になっていれば追加
    if (flag3 * flag5 * flag7)
      inAll753Numbers.push_back(inNum);
  }
}

