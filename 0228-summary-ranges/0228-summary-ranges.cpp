class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;

        int n = nums.size();
        if(n==0)return ans;
        string s = to_string(nums[0]);
        string temp="";
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                    if(temp.length()!=0)
                    s = s + "->" + temp;
                    
                    ans.push_back(s);
                
                s = to_string(nums[i]);
                temp="";
            } else
                temp = to_string(nums[i]);
        }
        if(temp.length()!=0)s=s+"->"+temp;
        ans.push_back(s);
        return ans;
    }
};