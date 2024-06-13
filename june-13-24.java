class Solution {
  public:
  //int f ( int n   )
  int mod = 1e9 + 7 ;
  int f ( int n  , vector < int > &dp ){
     if ( n <= 2 ) return dp[n] ;
     for ( int i = 3 ; i <=n ; i++){
         dp[i] = ( dp[i-2] + dp[i - 3] )% mod;
     }
     return dp[n] ;
  }
    int padovanSequence(int n) {
        vector < int > dp (n+1) ;
        dp[0] = dp[1] = dp[2] = 1 ;
        return f ( n , dp ) ;
    }
};