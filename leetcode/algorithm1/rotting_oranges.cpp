//https://leetcode.com/problems/rotting-oranges
class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        int fresh = 0, time = 0;
        // Push rotten to queue
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        // Special case
        if (fresh==0){
            return 0;
        }
        // size_q = num of rotten added to q each step (each layer of BFS)
        while(!q.empty()){
            int size_q = q.size();
            int queue_add=0;
            while(size_q){
                pair<int, int> curr = q.front();
                q.pop();
                int x = curr.first, y = curr.second;
                int dx[4] = {-1, 1, 0 ,0};
                int dy[4] = {0, 0, -1, 1};
                for(int i=0; i<4; i++){
                    int new_x = x + dx[i];
                    int new_y = y + dy[i];
                    if(new_x>=0 && new_y>=0 && new_x<m && new_y<n && grid[new_x][new_y]==1){
                        queue_add ++;
                        grid[new_x][new_y] = 2;
                        q.push({new_x, new_y});
                    }
                }
                size_q--;
            }
            if (queue_add) time++; 
        }
        
        // Check any orange still fresh
        fresh = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        return fresh>0?-1:time;
	}
};
