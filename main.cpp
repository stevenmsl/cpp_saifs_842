#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol842;

/*
Input: "123456579"
Output: [123,456,579]
*/
tuple<string, vector<int>>
testFixture1()
{
  return make_tuple("123456579",
                    vector<int>{123, 456, 579});
}
/*
Input: "11235813"
Output: [1,1,2,3,5,8,13]
*/
tuple<string, vector<int>>
testFixture2()
{
  return make_tuple("11235813",
                    vector<int>{1, 1, 2, 3, 5, 8, 13});
}

/*
Input: "112358130"
Output: []
Explanation: The task is impossible.
*/

tuple<string, vector<int>>
testFixture3()
{
  return make_tuple("112358130",
                    vector<int>{});
}

/*
Input: "0123"
Output: []
Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
*/

tuple<string, vector<int>>
testFixture4()
{
  return make_tuple("0123",
                    vector<int>{});
}

/*
Input: "1101111"
Output: [110, 1, 111]
Explanation: The output [11, 0, 11, 11] would also be accepted.
*/

tuple<string, vector<int>>
testFixture5()
{
  return make_tuple("1101111",
                    vector<int>{110, 1, 111});
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.split(get<0>(f))) << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Expect to see " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.split(get<0>(f))) << endl;
}
void test3()
{
  auto f = testFixture3();
  cout << "Expect to see " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.split(get<0>(f))) << endl;
}
void test4()
{
  auto f = testFixture4();
  cout << "Expect to see " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.split(get<0>(f))) << endl;
}
void test5()
{
  auto f = testFixture5();
  cout << "Expect to see " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.split(get<0>(f))) << endl;
}

main()
{
  test1();
  test2();
  test3();
  test4();
  test5();
  return 0;
}