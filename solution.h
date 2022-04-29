
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;
namespace sol842
{

  class Solution
  {
  private:
    bool _split(int pos, string &s, vector<int> &nums);

  public:
    vector<int> split(string s);
  };
}
#endif