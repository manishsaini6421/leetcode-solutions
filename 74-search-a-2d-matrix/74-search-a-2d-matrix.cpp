class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(),c=matrix[0].size();
        
        int low=0,high=r*c-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(target==matrix[mid/c][mid%c]){
                return true;
            }
            else if(target>matrix[mid/c][mid%c]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
};