class Solution {
public:
    string longestPalindrome(string s) {
        std::string ret;
        int left=0,right=0;
        int numbers;
        int maxlength = 0;
        if(s.size()<=1){
            return s;
        }
        else{
            ret = s[0];
            for(int index = 0 ; index < s.size();index++){
                // left = index - 1;
                // right = index + 1;
                // int maxlength = 0;
                // if(s[index] == s[index+1]){
                //     left = index;
                //     right = index + 1; 
                //     if(index - 1 >= 0 and  s[index] == s[index-1]){
                //         left = index - 1;
                //         right = index + 1;
                //     }
                // } 
                numbers = 1;
                while(1){
                    if(s[index] == s[index+numbers]){
                        ++numbers;
                    }
                    else break;
                }
                if(numbers >=2 and (numbers % 2)==0){
                    index=left = index+(numbers/2 -1);
                    right = left + 1; 
                }
                else{
                    index=index + (numbers/2);
                    left = index -1;
                    right = index + 1;    
                }
                while(1){
                    if(left < 0 or right > s.size()-1){
                        break;
                    }

                    if(s[left]==s[right]){
                        maxlength = right - left+1;
                        -- left;
                        ++ right;
                    }
                    else{
                        break;
                    }
                }
                if(maxlength > ret.size()){
                    ret = s.substr(++left,maxlength);
                }
                
            }
        }
        return ret;

    }
};