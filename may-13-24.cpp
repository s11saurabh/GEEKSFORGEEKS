//Number of Good Component

//Given an undirected graph with v vertices(numbered from 1 to v) and e edges. Find the number of good components in the graph.
//A component of the graph is good if and only if the component is fully connected.
//Note: A fully connected component is a subgraph of a given graph such that there's an edge between every pair of vertices in the component, the given graph can be a disconnected graph.

//Constraints:
//1 <= edges[i][0], edges[i][1] <= v
//1 ≤ v, e ≤ 104
//All edges are unique


class Solution {
    private:
    void dfs(vector<vector<int>> &adj, int i, vector<int> &isVisited, vector<int> &temp){
        temp.push_back(i);
        isVisited[i]++;
        for(auto &it : adj[i]){
            if(isVisited[it] == 0)
                dfs(adj, it, isVisited, temp);
        }
        return;
    }
    public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(v + 1, vector<int> {});
        for(auto &e: edges){
            int a = e[0];
            int b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int numberOfGoodComponents = 0;
        vector<int> isVisited (v + 1, 0);
        for(int i = 1; i <= v; i++){
            if(isVisited[i] == 0){
                vector<int> temp;
                dfs(adj, i, isVisited, temp);
                bool flag = true;
                for(auto &it : temp){
                    if(adj[it].size() != temp.size() - 1){
                        flag = false;
                        break;
                    }
                }
                if (flag){
                    numberOfGoodComponents++;
                }
            }
        }
        return numberOfGoodComponents;
    }
};