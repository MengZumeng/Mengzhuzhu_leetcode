class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        int denominator = 10;
        while(x){
            int temp = x % denominator;
            if (ret>214748364 || (ret==214748364 && temp>7)) {
                return 0;
            }
            //判断是否 小于 最小32位整数
            if (ret<-214748364 || (ret==-214748364 && temp<-8)) {
                return 0;
            }
            ret = ret*10 + temp;
            x = x / denominator;
        }
        return ret;
    }
};