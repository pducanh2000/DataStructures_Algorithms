//https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start , end;
        int length, max_length=0;
        int dict[128];
        for (start=0; start<s.length(); start++){
            for (int i=0; i<128; i++){
                dict[i] = 0;
            }
            length = 0;
            for (end=start; end<s.length(); end++){
                if(dict[(int)s[end]] == 0){
                    length++;
                    dict[(int)s[end]]++;
                }
                else{
                    break;
                }
            }
            max_length = max_length>length?max_length:length;
        }
        return max_length;
    }
};

// Another solution which is better than my solution 
// https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/2280909/Striver-Solution
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        vector<int> mp(256,-1);
        int left=0,right=0;
        int len=0;
        while(right<str.size()){
            if(mp[str[right]]!=-1) left = max(mp[str[right]]+1,left);
            mp[str[right]] = right;
            len=max(right-left+1,len);
            right++;
        }
        return len;
    }
};
