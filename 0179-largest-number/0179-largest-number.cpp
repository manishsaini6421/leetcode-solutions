class Solution {
public:
    static bool custom(string x, string y){
        return x+y > y+x;
    }
    string largestNumber(vector<int>& nums) {
        int count=0;
        for(auto itr:nums){
           if(itr==0)
           count++;
        }
        if(count==nums.size())
        return "0";
        vector<string> nums1;
        
        for(auto itr:nums){
          nums1.push_back(to_string(itr));
        }
        sort(nums1.begin(),nums1.end(),custom);

        string result="";

        for(auto itr:nums1){
            result=result+itr;
        }
        return result;
    }
};