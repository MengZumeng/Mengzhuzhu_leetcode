class Solution {
public:
    int myAtoi(string s) {
        int ret =0,flag=0,temp =0;
        for(int index= 0;index < s.size();index++){
            temp = s[index] - '0';
            if( temp<0 or temp>9){
                if (s[index] == ' '  && flag ==0) continue;
                else if(s[index] == '-' and flag ==0){
                   flag = 2;
                   continue;
                }
                else if(s[index] == '+'  && flag ==0){
                   flag = 1;
                   continue;
                }
                else break;
            }
            if ((ret>214748364 || (ret==214748364 && temp>7)) && flag !=2) {
                return INT_MAX;
            }
            //判断是否 小于 最小32位整数
            if ((ret > 214748364 || (ret==214748364 && temp>=8)) && flag==2) {
                return INT_MIN;
            }
            ret = ret*10+temp;
            flag = flag == 0 ? 1:flag;
        }
        if(flag == 2 ) ret = -1*ret;

        return ret;
    }
};