/*
K-Palindrome


Given a string str of length n, find if the string is K-Palindrome or not. A k-palindrome string transforms into a palindrome on removing at most k characters from it.


Example 1:

Input: str = "abcdecba"
n = 8, k = 1
Output: 1
Explaination: By removing 'd' or 'e' 
we can make it a palindrome.

Example 2:

Input: str = "abcdefcba"
n = 9, k = 1
Output: 0
Explaination: By removing a single 
character we cannot make it a palindrome.

Your Task:
You do not need to read input or print anything. Your task is to complete the function kPalindrome() which takes string str, n, and k as input parameters and returns 1 if str is a K-palindrome else returns 0.


Expected Time Complexity: O(n*n)
Expected Auxiliary Space: O(n*n)


Constraints:
1 ≤ n, k ≤ 10^3







*/
class Solution{
public:
int lcs(string s1, string s2) {
    int m = s1.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    for (int ind1 = 1; ind1 <= m; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1];
            else
                cur[ind2] = max(prev[ind2], cur[ind2 - 1]); 
        }
        prev = cur; 
    }
    return prev[m]; 
        }
    int kPalindrome(string str, int n, int k)
    {
        string s = str ;
         reverse(s.begin(),s.end());
          int ans = str.size() -  lcs(s,str);
          
          return (ans<=k);
    }
};