class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int iLow=0,flag=0;
        int sum = 0,iRet=nums.size(),iLength;

        for(int index =0;index < nums.size();index++){
            sum += nums[index];
            if(sum >= target){
                flag = 1;
                for(iLow;iLow<index;iLow++){
                    if(sum - nums[iLow] < target) break;
                    sum -= nums[iLow];
                }
                iLength = index - iLow +1;
                iRet = iLength < iRet ? iLength: iRet;
            }
        }
        iRet = flag == 0 ?0:iRet;
        return iRet;
    }
};