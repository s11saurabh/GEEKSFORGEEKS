#include <iostream>
#include <algorithm>

using namespace std;

class Solution {

 

  public:

    int findSwapValues(int a[], int n, int b[], int m) {

    int sumA = 0, sumB = 0;

    for (int i = 0; i < n; ++i) sumA += a[i];

    for (int i = 0; i < m; ++i) sumB += b[i];

    

    int diff = sumA - sumB;

    if (diff % 2 != 0) return -1;

 

    int target = diff / 2;

    unordered_set<int> setA(a, a + n);

    

    for (int i = 0; i < m; ++i)

        if (setA.count(b[i] + target)) return 1;

 

    return -1;

}

 

 

};
june-6-24.__cpp_aggregate_nsdmi