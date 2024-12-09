class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> v;
        int x=0;
        int n=nums.size();
        for(int i=1; i<n; i++){
            if((nums[i]%2==0 &nums[i-1]%2==0) || (nums[i]%2!=0 &nums[i-1]%2!=0)) {
                v.push_back({x,i-1});
                x=i;
            }
        }
        v.push_back({x,n-1});
       
        vector<bool>result;
        int m=queries.size();
        int vsize=v.size();
        for(int i=0; i<m; i++){
            int first=queries[i][0];
            int l=0,h=vsize-1;
             while(l<=h){
                int mid=(l+h)/2;
                if(v[mid][0]<=first && first<=v[mid][1]){
                    if(queries[i][1]<=v[mid][1])result.push_back(true);
                    else result.push_back(false);
                }
                if(first<v[mid][0])h=mid-1;
                else l=mid+1;

            }
        }
        
        return result;
    }
};