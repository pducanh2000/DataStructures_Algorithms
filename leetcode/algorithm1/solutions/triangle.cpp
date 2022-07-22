//https://leetcode.com/problems/triangle/
class Solution {
public:
    int min_path_to_node(int i, int j, vector<vector<int>>& memo, vector<vector<int>>& triangle){
        if(i<0 || j<0){
            return 0;
        }
        if (memo[i][j] != -10001){
            return memo[i][j];
        }
        int result;
        if (i==0){
            result = triangle[0][0];
        }
        else if(i==j){
            result = triangle[i][j] + min_path_to_node(i-1, j-1, memo, triangle);
        }
        else if(j==0){
            result = triangle[i][j] +  min_path_to_node(i-1, 0, memo, triangle);
        }
        else{
            result = triangle[i][j] + min(min_path_to_node(i-1, j-1, memo, triangle), min_path_to_node(i-1, j, memo, triangle));
        }
        // cout<<"(i, j) :" << i << ", " << j <<" res: "<< result<< endl;
        memo[i][j] = result;
        return result;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int min = INT_MAX;
        vector<vector<int>> memo (triangle);
        
        int num_row = triangle.size();
        for(int i=0; i<num_row; i++){
            for(int j=0; j<triangle[i].size(); j++){
                memo[i][j] = -10001;
            }
        }
        for(int i=0; i<triangle[num_row-1].size(); i++){
            int min_node = min_path_to_node(num_row-1, i, memo, triangle);
            min = min>min_node?min_node:min;
        }
        return min;
    }
};
