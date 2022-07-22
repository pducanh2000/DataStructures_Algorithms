//https://leetcode.com/problems/letter-case-permutation/
class Solution {
public:
    void update_string_list(vector<string>& ans, vector<int> alphabet_pos, string s, int curr_pos){
        if(curr_pos == alphabet_pos.size()){
            ans.push_back(s);
        }
        else{
            update_string_list(ans, alphabet_pos, s, curr_pos+1);
            s[alphabet_pos[curr_pos]] = toupper(s[alphabet_pos[curr_pos]]);
            update_string_list(ans, alphabet_pos, s, curr_pos+1);
        }
        
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<int> alphabet_pos;
        vector<string> ans;
        for(int i=0; i<s.length(); i++){
            s[i] = tolower(s[i]);
            int ascii_code = (int)s[i];
            if(ascii_code<90 || ascii_code>122){
                continue;
            }
            alphabet_pos.push_back(i);
        }
        // for(int i=0; i<alphabet_pos.size(); i++){
        //     cout << alphabet_pos[i] << endl; 
        // }
        update_string_list(ans, alphabet_pos, s, 0);
        return ans;
    }
};
