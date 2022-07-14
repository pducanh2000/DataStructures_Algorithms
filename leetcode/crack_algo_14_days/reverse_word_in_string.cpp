class Solution {
public:
    void reverse_string(string& s, int begin, int end){
        while (end>begin){
            swap(s[begin++], s[end--]);
        }
    }
    string reverseWords(string s) {
        int begin=0, end=-2;
        for (int i=0; i<s.length(); i++){
            if (s[i+1]==' ' || i==s.length()-1){
                begin = end+2;
                end = i;
                reverse_string(s, begin, end);
            }
        }
        return s;
    }
};
