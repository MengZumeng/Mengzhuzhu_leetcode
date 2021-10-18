




//暴力解法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int flag = 0;
        for(vector<int>::iterator it = nums.begin();it != nums.end();it++){
            for(vector<int>::iterator sed = it + 1;sed != nums.end();sed++){
                int sum = *it + *sed;
                if(sum == target){
                    
                    ret.push_back(int(it-nums.begin()));
                    ret.push_back(int(sed-nums.begin()));
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
            {
                break;
            }
        }
        return ret;
    }
};


//以空间换事件，建立hash表查找
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> intMap;
        vector<int> ret(2);
        for(int i = 0;i<nums.size();i++){
            auto item = intMap.find(target-nums[i]);
            if(item != intMap.end()){
                ret[0] = item->second;
                ret[1] = i; 
            }
            intMap.insert(make_pair(nums[i],i));
        }
        return ret;
    }
};