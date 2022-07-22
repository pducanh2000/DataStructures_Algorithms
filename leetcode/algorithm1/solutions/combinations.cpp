//https://leetcode.com/problems/combinations
class Solution {
public:
    void backtracking(vector<int>& used, vector<int>& combination, vector<vector<int>>& ans, int curr_i, int pos){
        if (pos==combination.size()){
            ans.push_back(combination);
        }
        else{
            for(int i=curr_i; i<used.size(); i++){
                if (!used[i] ){
                    if (pos>=1 && i<combination[pos-1]) continue;
                    combination[pos] = i+1;
                    used[i] = 1;
                    backtracking(used, combination, ans, curr_i+1, pos+1);
                    used[i] = 0;
                }
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination(k, 0);
        vector<int> used(n, 0);
        vector<vector<int>> ans;
        backtracking(used, combination, ans, 0, 0);
        return ans;
    }
};
