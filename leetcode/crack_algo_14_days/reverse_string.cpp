class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0, right=s.size()-1;
        while(right>left){
            swap(s[left++], s[right--]);
        }
    }
};
