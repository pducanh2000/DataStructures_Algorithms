//https://leetcode.com/problems/flood-fill
class Solution {
public:
    vector<vector<int>> recursiveFill(vector<vector<int>>& image, int sr, int sc, int old_color, int new_color){
         if (sr >= image.size() || sc >= image[0].size() || sr < 0 || sc <0 || image[sr][sc]==new_color || image[sr][sc]!= old_color){
            return image;
        }
        
        image[sr][sc] = new_color;    
        
        recursiveFill(image, sr, sc-1, old_color, new_color);
        recursiveFill(image, sr, sc+1, old_color, new_color);
        recursiveFill(image, sr+1, sc, old_color, new_color);
        recursiveFill(image, sr-1, sc, old_color, new_color);
        return image;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        image = recursiveFill(image, sr, sc, image[sr][sc], color);
        return image;
    }
};
