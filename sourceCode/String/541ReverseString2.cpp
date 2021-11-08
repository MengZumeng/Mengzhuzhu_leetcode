class Solution {
public:
    string reverseStr(string s, int k) {
        int iLeft,iRight;
        int nums = s.size()/k;
        int remain = s.size()%k;
        for(int index = 0;index <nums;index++){
            if(index%2 !=1){
                iLeft=k*index;
                iRight=k*index+k-1;
                while(iLeft < iRight){
                    swap(s[iLeft],s[iRight]);
                    iLeft++;
                    iRight--;
                }
            }
        }
        if(nums%2 == 0 && remain>0){
            iLeft=nums*k;
            iRight=nums*k+remain-1; 
            while(iLeft < iRight){
                swap(s[iLeft],s[iRight]);
                iLeft++;
                iRight--;
            }  
        }
        return s;

    }
};