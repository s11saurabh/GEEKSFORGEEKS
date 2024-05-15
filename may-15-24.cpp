//Account Merge



//Given a list of accounts of size n where each element accounts [ i ] is a list of strings, where the first element account [ i ][ 0 ]  is a name, and the rest of the elements are emails representing emails of the account.
//Geek wants you to merge these accounts. Two accounts belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts have the same name.
//After merging the accounts, return the accounts in the following format: The first element of each account is the name, and the rest of the elements are emails in sorted order.

//Note: Accounts themselves can be returned in any order

//Constraints:
//1 <= n <= 1000
//2 <= accounts[ i ].size <= 10
//1 <= accounts[ i ][ j ].size <= 30
//accounts[i][0] consists of English letters.

class DisjointSet{
  public:
  DisjointSet() = delete;
  DisjointSet(int n){
      rank.resize(n+1, 0); //N+1 because graph might be 1 based indexing
      parent.resize(n+1);
      size.resize(n+1, 1);
      std::iota(begin(parent), end(parent), 0);
  }
  
  int getUlParent(int node){ //get ultimate parent
      if(node == parent[node]){
          return node;
      }else{
          return parent[node] = getUlParent(parent[node]);
      }
  }
  
  void unionByRank(int u, int v){
      int ulp_u = getUlParent(u);
      int ulp_v = getUlParent(v);
      if(ulp_u == ulp_v){
          return;
      }
      if(rank[ulp_u] < rank[ulp_v]){
          parent[ulp_u] = ulp_v;
      }else if(rank[ulp_v] < rank[ulp_u]){
          parent[ulp_v] = ulp_u;
      }else{
          parent[ulp_u] = ulp_v;
          rank[ulp_u]++;
      }
  }
  void unionBySize(int u, int v){
      int ulp_u = getUlParent(u);
      int ulp_v = getUlParent(v);
      if(ulp_u == ulp_v){
          return;
      }
      if(rank[ulp_u] < rank[ulp_v]){
          parent[ulp_u] = ulp_v;
          size[ulp_u] += size[ulp_v];
      }else{
          parent[ulp_v] = ulp_u;
          size[ulp_v] += size[ulp_u];
      }
  }
  private:
  vector<int> rank, parent, size;
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        int n = accounts.size(), i, j;
        DisjointSet dsj(n+1);
        unordered_map<string, int> mp;
        vector<vector<string>> res;
        for(i = 0;i<n;i++){
            for(j = 1;j<accounts[i].size();j++){
                if(!mp[accounts[i][j]]){
                    mp[std::move(accounts[i][j])] = i+1;
                }else{
                    dsj.unionByRank(mp[accounts[i][j]], i+1);
                }
            }
        }
        vector<string> adj[n+1];
        for(auto itr{begin(mp)}; itr != end(mp); ++itr){
            adj[dsj.getUlParent(itr->second)].push_back(std::move(string(itr->first)));
        }
        for(i = 1;i<=n;i++){
            if(adj[i].size()){
                sort(adj[i].begin(), adj[i].end());
                adj[i].insert(adj[i].begin(), std::move(accounts[i-1][0]));
                res.push_back(std::move(adj[i]));
            }
        }
        
        return res;
    }
};