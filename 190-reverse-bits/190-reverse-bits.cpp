class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t cpy=0;
        int t=32;
        while(t--){
            cpy=cpy<<1;
            cpy=cpy|n&1;
            n>>=1;
        }return cpy;
    }
};