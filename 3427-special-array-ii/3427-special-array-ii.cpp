class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> v;
        int x=0;
        for(int i=1; i<nums.size(); i++){
            if((nums[i]%2==0 &nums[i-1]%2==0) || (nums[i]%2!=0 &nums[i-1]%2!=0)) {
                v.push_back({x,i-1});
                x=i;
            }
        }
        v.push_back({x,(int) nums.size()-1});
        for(int i=0; i<v.size(); i++){
            cout<<v[i][0]<<" "<<v[i][1]<<endl;
        }
        vector<bool>result;
        for(int i=0; i<queries.size(); i++){
            int first=queries[i][0];
            int l=0,h=v.size()-1;
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