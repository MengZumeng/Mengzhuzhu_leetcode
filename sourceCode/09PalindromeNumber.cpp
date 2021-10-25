class Solution {
public:
    bool isPalindrome(int x) {
        string intList;
        int flag = 0;
        intList = to_string(x);
        for(int i = 0 ,j =intList.size()-1;i<=j;i++,j--){
            if(intList[i] != intList[j]){
                flag = 1;
                break;
            }
        }
        if(flag) return false;
        else return true;
    }
};