class Solution {
public:
    bool canTransform(string start, string result) {
        int n=start.size();
        int i=0,l=0,r=0;
        while(i<n){
            if(start[i]=='R'){
                if(l>0)return false;
                r++;
            }
            if(result[i]=='L'){
                if(r>0)return false;
                l++;
            }
            if(start[i]=='L'){
                if(l==0)return false;
                l--;
            }
            
            if(result[i]=='R'){
                if(r==0)return false;
                r--;
            }
            i++;
        }
        return l==0 && r==0;
    }
};