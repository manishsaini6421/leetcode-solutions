class Solution {
public:
    bool canChange(string start, string target) {
        int i=0,n=start.size();
        int l=0,r=0;
        while(i<n){
              
            if(start[i]=='R'){
                if(l>0)return false;
                r++;
            }
            if(target[i]=='R'){
                if(r==0)return false;
                r--;
            }
            if(target[i]=='L'){
                if(r>0)return false;
                l++;
            }
            if(start[i]=='L'){
                if(l==0)return false;
                l--;
            }
            
            i++;
        }
        
        return l==0 && r==0;
    }
};