class Solution {
public:
    int smallestNumber(int n, int t) {
        auto getDigitProduct = [](int num){
            int product = 1;
            while(num>0){
                product *= (num % 10);
                num /= 10;
            }
            return product;
        };
        while (true){
            if (getDigitProduct(n)%t==0){
                return n;
            }
            n++;
        }
        
    }
};