class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> matchMap;
        int iResult=0;
        for(int i =0; i < nums1.size();i++){
            for(int j = 0;j < nums2.size();j++){
                int temp1 = nums1[i]+nums2[j];
                if(matchMap.find(temp1) != matchMap.end()){
                    matchMap.find(temp1)->second += 1; 
                }
                else matchMap.insert(make_pair(temp1,1));
            }
        }
        for(int i =0; i < nums1.size();i++){
            for(int j = 0;j < nums2.size();j++){
                int temp2 = 0-nums3[i]-nums4[j];
                if(matchMap.find(temp2) != matchMap.end()){
                    iResult += matchMap.find(temp2)->second;
                }
            }
        }
        return iResult;
    }
};