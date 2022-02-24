class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t bit=0;
        for(int i=0; i<32; i++){
            
            bit=(bit<<1) | (1&n);
            n>>=1;
        }
        return bit;
    }
};