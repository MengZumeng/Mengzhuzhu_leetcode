//暴力解法
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> charMap;
        int maxlength=0;
        int curlength=0;
        for(int index = 0; index <s.size();index++){
            char item = s[index];
            ++curlength;
            int newLength=0;
            auto element = charMap.find(item);
            if(element != charMap.end()){
                int oldIndex = element->second;
                newLength = index - oldIndex;
                element->second = index;
                if(newLength < curlength){
                    curlength = newLength;
                    if(newLength >= maxlength){
                        //curlength=newLength;
                        maxlength = newLength;

                    }
                }
                //else{
                    //curlength =1;
                //}
            }
            else{
                charMap.insert(make_pair(item,index));
            }

            maxlength = curlength > maxlength?curlength:maxlength;
        }
        return maxlength;
    }
};

//滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>skipWindows;
        int maxStr=0;
        int leftIndex=0;
        for(int index = 0;index < s.size();index++){
            if(s.size()==0){
                return 0;
            }
            while(skipWindows.find(s[index]) != skipWindows.end()){
                skipWindows.erase(s[leftIndex]);
                leftIndex++;
            }
            skipWindows.insert(s[index]);
            maxStr=maxStr>(index-leftIndex+1)?maxStr:(index-leftIndex+1);
        }
        return maxStr;
    }
};