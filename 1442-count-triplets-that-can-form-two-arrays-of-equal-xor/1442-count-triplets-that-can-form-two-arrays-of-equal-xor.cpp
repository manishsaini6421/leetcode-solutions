class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        for(int i=0; i<n; i++){
           
            int temp1=0;
           
            for(int j=i; j<n; j++){
                 temp1^=arr[j];
                 int temp2=0;
                for(int k=j+1; k<n; k++){
                    temp2^=arr[k];
                    if(temp1==temp2)ans++;
                }
            }
            
        }
        return ans;
    }
};