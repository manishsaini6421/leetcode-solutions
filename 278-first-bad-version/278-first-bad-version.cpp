// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int temp,f=1,r=n;
        while(r>=f){
            temp=(f+r)/2;
            if(isBadVersion(temp)){
                r=temp-1;
                }
              else 
            {
                f=temp+1;
            }
            
            
            
        }
  return f;
    }
};