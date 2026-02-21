class Solution {
public:
    static int countPrimeSetBits(int left, int right) {
        constexpr int bmask=((1<<2)|(1<<3)|(1<<5)|(1<<7)|(1<<11)|(1<<13)|(1<<17)|(1<<19));
        int sum=0;
        for(unsigned i=left; i<=right; i++){
            sum+=((1<<popcount(i))&bmask)>0;
        }
        return sum;
    }
};
