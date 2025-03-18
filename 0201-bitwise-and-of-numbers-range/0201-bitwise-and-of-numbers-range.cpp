class Solution {
public:
    int find(int left,int right){
        int ans=0;
        int i=0,j=30;
        while(i<=j){
             int mid=i+(j-i)/2;
            if(pow(2,mid)<right){
            ans=mid;
            i=mid+1;

             }
             else{
            j=mid-1;
          }
        }
       
        
        return (ans<left)?left: pow(2,ans);
    }
    int rangeBitwiseAnd(int left, int right) {
        if(left==right)return left;
        int ans=left;
        
        for(long i=find(left,right); i<=right; i++){
            ans&=i;
            if(!ans)break;
        }
        return ans;
    }
};