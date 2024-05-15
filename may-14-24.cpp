//Path With Minimum Effort
//You are a hiker preparing for an upcoming hike. You are given heights[][], a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find the route with minimum effort.

//Note: A route's effort is the maximum absolute difference in heights between two consecutive cells of the route

//Your Task:You don't need to read input or print anything. Your task is to complete the function MinimumEffort() which takes intergers rows, columns, and the 2D array heights[][]  and returns the minimum effort required to travel from the top-left cell to the bottom-right cell.

//Expected Time Complexity: O(rowsxcolumns)
//Expected Space Complexity: O(rowsxcolumns)

//Constraints:
//1 <= rows, columns <= 100
//rows == heights.length
//columns == heights[i].length
//0 <= heights[i][j] <= 106








class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>> pq;
        int r = heights.size();
        int c= heights[0].size();
        vector<vector<int>>dist(r,vector<int>(c,INT_MAX));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int diff = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;
            if(row == r-1 and col == c-1) return diff;
            if(row>0){
                int newEffort = max(abs(heights[row][col] - heights[row-1][col] ), diff);
                if(newEffort<dist[row-1][col]){
                    dist[row-1][col] = newEffort;
                    pq.push({newEffort,{row-1,col}});
                }
            }
            if(col>0){
                int newEffort = max(abs(heights[row][col] - heights[row][col-1] ), diff);
                if(newEffort<dist[row][col-1]){
                    dist[row][col-1] = newEffort;
                    pq.push({newEffort,{row,col-1}});
                }
            }
            if(row<r-1){
                int newEffort = max(abs(heights[row][col] - heights[row+1][col] ), diff);
                if(newEffort<dist[row+1][col]){
                    dist[row+1][col] = newEffort;
                    pq.push({newEffort,{row+1,col}});
                }
            }
            if(col<c-1){
                int newEffort = max(abs(heights[row][col] - heights[row][col+1] ), diff);
                if(newEffort<dist[row][col+1]){
                    dist[row][col+1] = newEffort;
                    pq.push({newEffort,{row,col+1}});
                }
            }
        }
        return 0;
    }
};