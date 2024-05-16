/*Divisibility tree

Given a tree with n nodes where n is even. The tree is numbered from 1 to n, has n - 1 edges and is rooted at node 1. Your task is to eliminate the maximum number of edges resulting in a set of disjoint trees where the number of nodes in each tree is divisible by 2.

Your Task:
You don't need to read or print anyhting. Your task is to complete the function minimumEdgeRemove() which takes n and edges as input parameters and returns the maximum number of edges that need to be removed from the given tree.

Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraints:
1 <= n <= 105
edges.length == n - 1
1 <= edges[i][0], edges[i][1] <= n

*/



int dfs(int parent ,int node ,vector<int>adj[] , int &ans){
    int count =0 ;
    for(auto it:adj[node]){
        if(it!=parent){
            //counting the nodes in the subtree of that node 
            count += dfs(node , it,adj,ans) ;
        }
    }
    count ++ ;// for counting the self node
    if(count%2==0 and node!=1){ 
    // increment the cutting value(ans) but if that is for root node then dont increment it 
        ans++ ;
        count=0;//make the count of subtree for that node 0 , as it is cut from its parent
    }
    // cout << node << " " << count << endl ;
    return count ;
}
    int minimumEdgeRemove(int n, vector<vector<int>>edges){
        // Code here
        vector<int>adj[n+1] ;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]) ;
            adj[it[1]].push_back(it[0]) ;
        }
        int ans=0 ;
        dfs(-1 ,1, adj,ans) ;
        return ans ;
    }

