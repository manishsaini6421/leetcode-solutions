class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<int> arr(n,0);
        int ans=0;

        for(int i=0; i<n; i++){
            int flag=0;
            for(int j=0; j<n; j++){
                if(arr[j]==0 && fruits[i]<=baskets[j]){
                    arr[j]=1;
                    flag=1;
                    break;
                }
            }
            if(!flag)ans++;
        }
        return ans;
    }
};