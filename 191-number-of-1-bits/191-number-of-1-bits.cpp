class Solution {
public:
    bool setBit(int n,int pos){
        return (n&(1<<pos));
    }
    int hammingWeight(uint32_t n) {
        int count=0;
        for(int i=0; i<32; i++){
            if(setBit(n,i)){
                count++;
            }
        }
        return count;
    }
};