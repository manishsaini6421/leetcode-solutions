class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int r=0,c=n-1;
        while(m>r && c>=0){
            if(target==matrix[r][c]) return true;
            else if(target>matrix[r][c]){
                r++;
                
            }
            else c--;
        }
        return false;
    }
};