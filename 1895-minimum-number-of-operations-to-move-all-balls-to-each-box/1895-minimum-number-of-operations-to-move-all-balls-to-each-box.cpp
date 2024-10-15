class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int n=boxes.size();
        vector<int> ans(n,0);
        int count=0;
        for(int i=0; i<n; i++){
            
            for(int j=0;j<n; j++){
                if(boxes[j]=='1' && i!=j)ans[i]+=abs(j-i);
            }
        }
        
        return ans;
    }
};