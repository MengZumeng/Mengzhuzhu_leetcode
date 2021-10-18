
//暴力解法
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ret;
        std::multiset<int> myset;
        std::vector<int> mytable;
        for(vector<int>::iterator it1 = nums1.begin();it1 != nums1.end();it1++){
            myset.insert(*it1);
        }
        for(vector<int>::iterator it2 = nums2.begin();it2 != nums2.end();it2++){
            myset.insert(*it2);
        }


        for(auto it = myset.begin();it != myset.end();it ++){
            mytable.push_back(*it);
        }
        int numbers = mytable.size();
        int flag = numbers% 2;
        if(numbers == 1){
           ret = mytable[0];
        }
        else if(numbers == 0){
            ret = 0 ;
        }
        else if(numbers>=2 and flag == 0){
            int index1 = numbers / 2 ;
            int index2 = index1 + 1;
            ret  =  (mytable[index1-1]+mytable[index2-1])/2.0;
        }
        else{
            int index = numbers / 2 +1;
            ret = mytable[index-1];
        }
        return ret;
    }
};

//通过二分查找剔除元素
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ret;
        int n = nums1.size();
        int m = nums2.size();

        int left = (n+m+1)/2;
        int right = (n+m+2)/2;

        ret = (getKth(nums1,0,n-1,nums2,0,m-1,left)+getKth(nums1,0,n-1,nums2,0,m-1,right))*0.5;
        return ret;
    }

private:
    int getKth(vector<int>& nums1, int start1,int end1, vector<int>& nums2,int start2,int end2,int k){
        int ret;
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;

        if(len1 > len2){
            return  getKth(nums2,start2,end2,nums1,start1,end1,k);
        }

        if(len1 == 0){
            return nums2[start2 + k-1];
        }

        if(k == 1){
            ret = nums1[start1]>nums2[start2]?nums2[start2]:nums1[start1];
            return ret;
        }

        int i = start1 +(len1 > k/2 ?k/2 : len1) -1;
        int j = start2 +(len2 > k/2 ?k/2 : len2) -1;

        if(nums1[i] > nums2[j]){
            return  getKth(nums1,start1,end1,nums2,j+1,end2,k-(j - start2 + 1));
        }
        else{
            return getKth(nums1,i + 1 ,end1,nums2,start2,end2,k-(i - start1 + 1));
        }
    }
};

