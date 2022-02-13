class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int f=0,r=numbers.size()-1;
        vector<int> result;
        while(f<r){
            if(numbers[f]+numbers[r]==target){
                result.push_back(f+1);
                result.push_back(r+1);
                return result;
            }
            else if(numbers[f]+numbers[r]>target){
                r--;
            }
            else{
                f++;
            }
        }
        return result;
    }
};