class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int myTable[26]={0};
        bool bResult = true;
        for(int index = 0 ; index < magazine.size();index++){
            int temp1 = magazine[index] - 'a';
            myTable[temp1] += 1;
        }

        for(int index = 0 ; index < ransomNote.size();index++){
            int temp2 = ransomNote[index] - 'a';
            if(myTable[temp2] > 0){
                myTable[temp2] -= 1;
            }
            else return false;
        }
        return bResult;
    }
};