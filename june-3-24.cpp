class Solution {
  public:
   int mod = 1e9+7;
    int fun(int i, int n, int prev, int flag, vector<vector<vector<int>>> &dp) {
        if(i==n) {
            if(flag) return 1;
            return 0;
        }
        if(dp[i][prev][flag]!=-1) return dp[i][prev][flag];
        
        int pick=0, notpick=0;
        if(prev==0) {
            pick= fun(i+1, n, 1, flag, dp);
            notpick= fun(i+1, n, 0, flag, dp);
        }
        else {
            pick= fun(i+1, n, 1, 1, dp);
            notpick= fun(i+1, n, 0, flag, dp);
        }
        return dp[i][prev][flag]=(pick%mod + notpick%mod)%mod;
    }


    int numberOfConsecutiveOnes(int n) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (2,-1)));
        return fun(0, n, 0, 0, dp);
    }
};