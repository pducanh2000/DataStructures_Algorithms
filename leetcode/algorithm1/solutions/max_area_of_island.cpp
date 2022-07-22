class Solution {
public:
    int cal_area(vector<vector<int>> grid, vector<vector<int>>& visited, int i, int j){
        int area=0;
        int dx[4] = {0, 0, 1, -1}, dy[4] = {-1, 1, 0, 0};
        
        stack<pair<int, int>> stk;
        stk.push({i, j});
        
        while(!stk.empty()){
            int x=stk.top().first;
	        int y= stk.top().second;
            stk.pop();
            if (visited[x][y]){
                continue;
            }
            area += 1;
            visited[x][y] = 1;
            
            for(int k=0; k<4; k++){
                if(x+dx[k]<0 || y+dy[k]<0 || x+dx[k]>=grid.size() || y+dy[k]>=grid[0].size()){
                    continue;
                }
                if(!visited[x+dx[k]][y+dy[k]] && grid[x+dx[k]][y+dy[k]]){
                    stk.push({x+dx[k], y+dy[k]});
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited (grid.size(), vector<int> (grid[0].size(), 0));
        int max_area=0;
        for (int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(!visited[i][j] && grid[i][j]==1){
                    int tmp_area = cal_area(grid, visited, i, j);
                    max_area = max_area>tmp_area?max_area:tmp_area;
                }
            }
        }
        return max_area;
    }

};

// Simple solution from vian1608
// https://leetcode.com/problems/max-area-of-island/discuss/2283529/
class Solution {
public:
    
    int utility(vector<vector<int>>& grid, int i, int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
            return 0;
        if(grid[i][j]==0)
            return 0;
       
        grid[i][j]=0;
         
            
        return (1+ utility(grid, i+1, j) + utility(grid, i, j+1) + utility(grid, i-1, j) + utility(grid, i, j-1));
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0, x =0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                    x = utility(grid, i, j);
                
                ans = max(ans, x);
            }
        return ans;
    }
};
