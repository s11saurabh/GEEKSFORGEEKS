class Solution {
    public:
  
      void matchPairs(int n, char nuts[], char bolts[]) {
           unordered_map<char, int> order = {{'!', 0}, {'#', 1}, {'$', 2}, {'%', 3}, {'&', 4}, {'*', 5}, {'?', 6}, {'@', 7}, {'^', 8}};
  
          sort(nuts, nuts + n, [&](char a, char b)
               { return order[a] < order[b]; });
  
          sort(bolts, bolts + n, [&](char a, char b)
               { return order[a] < order[b]; });
      }
  };