class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0)return false;
        int arr[32];
        
        arr[0]= 1;
        for(int i=1; i<31; i++){
            arr[i]=arr[i-1]*2;
            
        }
      
        for(int i=0; i<32; i++){
            if(n==arr[i])return true;
        }
        return false;
    }
};