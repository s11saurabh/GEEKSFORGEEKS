#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> constructList(int q, std::vector<std::vector<int>>& queries) {
        std::vector<int> s = {0};  // Initial list with only 0
        int xorValue = 0;  // Variable to store the cumulative XOR value

        for (const auto& query : queries) {
            if (query[0] == 0) {
                s.push_back(query[1] ^ xorValue);
            } else {
                xorValue ^= query[1];
            }
        }

        for (auto& num : s) {
            num ^= xorValue;
        }

        std::sort(s.begin(), s.end());

        return s;
    }
};