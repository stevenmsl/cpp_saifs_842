#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <stack>
#include <string>
using namespace sol842;
using namespace std;

/*takeaways
  - use backtracking
  - For the Fibonacci sequence, once the first two numbers
    are determined, the rest are determined as well
    - use 123456579 as an example
      - if F[0] = 1, F[1] = 2
      - F[2] has to be 3, which will work as we can pick
        3 from the remaining digits "xx3456579"
      - F[4] has to be 5, which can't be done
        picking from "xxx456579"
        - pick 1 digit you got 4
        - pick 2 digits you got 45
      - we have to abandon this route
  - so in a nutshell you are picking different pair of F[1] & F[2]
    to start with and see if the remaining digits can still
    form a Fibonacci seqeucne

*/

bool Solution::_split(int pos, string &s, vector<int> &nums)
{
  const int N = s.size();
  if (pos == s.size())
    return nums.size() >= 3;

  /* per the question
     - 0 <= F[i] <= 2^31 - 1 -> 10 digits
     - no leading 0 unless it's just 0 by itself
  */
  auto digits = s[pos] == '0' ? 1 : 10;

  /* why long? it might be bigger than INT_MAX
     while you scanning in the very last digit
  */
  long num = 0;
  /* try all possible combination number of digits */
  for (auto i = pos; i < min(digits, N); i++)
  {
    num = num * 10 + s[i] - '0';
    if (num > INT_MAX)
      break;
    /* add up the very last two numbers F[i] & F[i+1]
       to verify F[i+2]
    */
    int size = nums.size();
    if (size >= 2)
    {
      long sum = nums[size - 1] + nums[size - 2];
      /* num  is too big to serve as F[i+2]
         - F[i+2] > F[i+1] + F [i]
         - stop scanning in more digits
      */
      if (sum < num)
        break;
      /* might still have a chance
         - scan in more digits
      */
      else if (sum > num)
        continue;
    }

    /* adopt num for now
       - we do achieve F[i+1] + F [i] = F[i+2]
         at this point
       - but we don't for the reaming digits
         if they can hold up building
         the Fibonacci sequence
    */
    nums.push_back(num);
    /* if all check out - keep the num
       - we only need to find a valid solution
         not list all of them. so return
         right away once everything
         checks out
    */
    if (_split(i + 1, s, nums))
      return true;
    /* num is no good; take it out  */
    nums.pop_back();
  }
  /* can't split s  */
  return false;
}

vector<int> Solution::split(string s)
{
  auto nums = vector<int>();

  _split(0, s, nums);

  return nums;
}