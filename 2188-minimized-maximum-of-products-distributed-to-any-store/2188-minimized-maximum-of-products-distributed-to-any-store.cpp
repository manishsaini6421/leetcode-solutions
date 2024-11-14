class Solution {
public:
    bool canDistribute(int n,vector<int>&quantities,int x){
        int j=0;
        int remaining=quantities[j];
        int m=quantities.size();
        for(int i=0; i<n; i++){
            if(remaining<=x){
                j++;
               if(j==m) return true;
               else remaining=quantities[j];
            }
            else remaining-=x;

            
        }
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long sum=0,maxNum=INT_MIN;
        int m=quantities.size();
        for(int i=0; i<m; i++){
            sum+=quantities[i];
            maxNum=(maxNum<quantities[i])?quantities[i]:maxNum;
        }
        long long i=(sum%n==0)?sum/n:sum/n+1,j=maxNum;

       while(i<j){
        long long mid=(i+j)/2;
        if(canDistribute(n,quantities,mid)){
            j=mid;
        }
        else i=mid+1;
       }

        return j;
    }
};