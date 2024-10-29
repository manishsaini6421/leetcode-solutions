class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> subsets;
        vector<int> set={1,2,3,4,5,6,7,8,9};
        for(int i=1; i<=512; i++){
            
            int temp=i;
           int count=0;
            while(temp){
                count+=temp&1;
                temp>>=1;
            }
            
            if(count==k){
                cout<<count<<endl;
                vector<int> sub;
                for(int j=0; j<9; j++){
                    if(1<<j & i)
                    {
                        sub.push_back(set[j]);
                        
                    }
                    
                }
                int sum=0;
                for(auto num:sub){
                    sum+=num;
                }
                
                if(sum==n){
                    subsets.push_back(sub);
                }
            }
            
        }
        return subsets;
    }
};