class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        sum.push_back(nums[0]);
        for(int i=1; i<n; i++){
            sum.push_back(sum[i-1]+nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return sum[right];
        return sum[right]-sum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */