class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int index = nums.size()-1;
        vector<int> vecRet(nums.size(),0);

        for(int i =0 ,j = nums.size()-1;i <= j;){
            if(nums[i]*nums[i] <= nums[j]*nums[j]){
                vecRet[index--] = nums[j]*nums[j];
                j--;
            }
            else{
                vecRet[index--] =  nums[i]*nums[i];
                i++;
            }
        }
        return vecRet;
    }
};