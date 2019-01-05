// include
#include <iostream>
#include <utility>  // pair用
#include <list>  // 頂点リスト pairリスト

// typedef
  
// macro
#define REP(index, num) for (auto index = 0; index < num; index++)

using namespace std;

const int CountPaths(const int currentNode, list<pair<int, int>> nodesPairsFromPath, list<int> inNodesList);
const bool IsVisited(const int node, list<int> inNodesList);

int main()
{
  int N, M;
  list<pair<int, int>> nodesPairsFromPath;
  list<int> nodesList;

  cin >> N >> M;

  REP(mId, M)
  {
    int a, b;
    cin >> a >> b;
    nodesPairsFromPath.push_back(make_pair(a, b));
    nodesList.push_back(a);
    nodesList.push_back(b);
  }

  // 重複要素消す
  nodesList.sort();
  nodesList.unique();

  // 深さ優先探索
  nodesList.remove(1);
  cout << CountPaths(1, nodesPairsFromPath, nodesList) << endl;

}

const int CountPaths(const int currentNode, list<pair<int, int>> inNodesPairsFromPath, list<int> inNodesList)
{
  int count = 0;

  // 全頂点訪問済みなら1を返す
  if (inNodesList.size() == 0)
    return 1;

  // 頂点リスト分探索する
  for (auto nItr = inNodesList.begin(); nItr != inNodesList.end(); ++nItr)
  {
    // 現在の頂点に対応する頂点を探す
    for (auto npItr = inNodesPairsFromPath.begin(); npItr != inNodesPairsFromPath.end(); ++npItr)
    {
      int a = (*npItr).first;
      int b = (*npItr).second;
      if (a == currentNode)
      {
        // bが訪問済みの頂点なら飛ばす
        if (IsVisited(b, inNodesList))
          continue;

        auto cpInNodesList = inNodesList;
        cpInNodesList.remove(b);
        *npItr = make_pair(-1, -1);  // 使い終わった辺は捨てる
        count += CountPaths(b, inNodesPairsFromPath, cpInNodesList);
      }
      else if (b == currentNode)
      { 
        // aが訪問済みの頂点なら飛ばす
        if (IsVisited(a, inNodesList))
          continue;

        auto cpInNodesList = inNodesList;
        cpInNodesList.remove(a);
        *npItr = make_pair(-1, -1); // 使い終わった辺は捨てる
        count += CountPaths(a, inNodesPairsFromPath, cpInNodesList);
      }
    }

  }

  return count;
}

const bool IsVisited(const int node, list<int> inNodesList)
{
  for (auto nItr = inNodesList.begin(); nItr != inNodesList.end(); ++nItr)
  {
    if ((*nItr) == node) return false;
  }

  return true;  // リストになければ訪問済み
}

