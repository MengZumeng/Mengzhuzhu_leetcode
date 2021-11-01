class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int left,right;
        vector<vector<int>> result;

        sort(nums.begin(),nums.end());
        for(int index = 0; index < nums.size();index++){
            if(index >0 && nums[index]==nums[index-1]) continue;


            int temp=0;
            left = index +1;
            right=nums.size()-1;
            while(left < right){
                //while(left <right && nums[left]==nums[left+1]) left++;
                //while(left <right && nums[right]==nums[right-1]) right--;
                temp = nums[index] + nums[left] + nums[right];
                if(temp == 0){
                    result.push_back(vector<int>{nums[index],nums[left],nums[right]});
                    while(left <right && nums[left]==nums[left+1]) left++;
                    while(left <right && nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                } 
                else if(temp < 0) left++;
                else right--;
            }
        }
        return result;
    }
};