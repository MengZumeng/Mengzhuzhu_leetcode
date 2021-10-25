class Solution {
public:
    string convert(string s, int numRows) {                                                                                                   
        string ret;
        std::unordered_map <int,string> strMap;
        int indexRet,rows=0,flag =1;
        if(numRows==1 or s.size()<=numRows){
            return s;
        }

        for(int index = 0 ;index <numRows;index++){
            strMap.insert(pair<int,string>(index,"\0"));
        }

        for(int index = 0;index < s.size();index++){
            if (flag){
                auto temp = strMap.find(rows);
                temp->second.push_back(s[index]);
                ++rows;
                if(rows == (numRows-1)){
                    flag = 0;
                }
            }
            else{
                auto temp = strMap.find(rows);
                temp->second.push_back(s[index]);
                --rows;
                if(rows == 0){
                    flag = 1;
                }
            }
        }
        for(int index = 0 ;index <numRows;index++){
            ret=ret+strMap.find(index)->second;
        }
        return ret;

    }
};