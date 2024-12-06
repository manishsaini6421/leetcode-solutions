class Solution {
public:
bool find(vector<int>& banned,int x,int i,int j){
    while(i<=j){
        int mid=(i+j)/2;
        if(banned[mid]==x)return true;
        if(banned[mid]>x) j=mid-1;
        else  i=mid+1;
               
    }
 
    
 
 return false;
}
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(),banned.end());
        int ans=0,count=0;
        for(int i=1; i<=n; i++){
            if(!find(banned,i,0,banned.size()-1)){
                cout<<i<<endl;
                if(ans+i<=maxSum){
                    ans+=i; 
                    count++;
                }
                else break;
            }
        }
        return count;
    }
};