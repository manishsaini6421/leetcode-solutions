class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ans=0;
        int a=amount[0],b=amount[1],c=amount[2];
        while(a>0 || b>0 || c>0){
            if(a>=c && b>=c){
                a--;
                b--;
                ans++;
            }
            else if(b>=a && c>=a){
                b--;
                c--;
                ans++;
            }
            else{
                a--;
                c--;
                ans++;
            }
        }
        return ans;
    }
};