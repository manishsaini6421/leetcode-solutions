class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        
        int n=nums.size();
        int ans=0;
       
        unordered_map<int,int> map; 
        for(int i=0; i<n; i++){   
            for(int j=i+1; j<n; j++){
                map[nums[i]*nums[j]]++;
            }         
            
        }
        for(auto frequency:map){
            if(frequency.second>=2){
                int x=frequency.second;
                int y=x*(x-1)/2; //choose two pairs (nc2) which will give 8 such combinations.
                ans+=(y*8);
            }
        }
        return ans;

    }
};