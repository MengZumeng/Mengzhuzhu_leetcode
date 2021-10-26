class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int flag = nums.size();
        for(int index =nums.size()-1;index >=0;index--){
            if(val == nums[index]){
                nums[index] = nums[flag-1];
                flag--;
            }
        }
        return flag;
    }
};