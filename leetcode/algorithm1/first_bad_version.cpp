// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long last=n, first=1;;
        long mid = (last+first)/2;
        long output = 0;
        while (last - first > 1){
            if (isBadVersion(mid)){
                output = mid;
                last = mid - 1;
            }
            else{
                first = mid;
            }
            mid = (last+first)/2;
        }
        if (isBadVersion(first)){
            return first;
        }
        else if (isBadVersion(last)){
            return last;
        }
        return output;
    }
};
