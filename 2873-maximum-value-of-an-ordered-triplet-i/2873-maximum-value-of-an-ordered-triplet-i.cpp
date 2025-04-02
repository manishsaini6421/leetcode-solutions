class Solution {
public:
    int ans=0;
    long long solve(vector<int>& nums,int index,vector<long long> &v){
        if(v.size()==3){
            return (v[0]-v[1])*v[2];
        }
        if(index>=nums.size())return 0;
        
       

        v.push_back(nums[index]);
        cout<<index<<" "<<v.size()<<endl;
        long long include=solve(nums,index+1,v);
        v.pop_back();

        long long exclude=solve(nums,index+1,v);

        return max(include,exclude);
    }
    long long maximumTripletValue(vector<int>& nums) {
        vector<long long> v;
        return solve(nums,0,v);
    }
};