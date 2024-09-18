class Solution {
public:
    int findNumbers(vector<int>& nums) {
        vector<string> nums1;
        for(auto itr:nums){
                nums1.push_back(to_string(itr));
        }
        int result=0;
        for(auto itr:nums1){
            if(itr.size()%2==0)
            result++;
        }
        return result;
    }
};