class Solution {
public:  static bool comp(int a,int b){
    string str1=to_string(a);
    string str2=to_string(b);
    if(str1+str2>str2+str1){
        return true;
    }else{
        return false;
    }
}
    string largestNumber(vector<int>& nums) {
        
        sort (nums.begin(),nums.end(),comp);
        if(nums[0]==0) return "0";
        string str="";
        for(int it:nums){
            str+=to_string(it);
        }
        return str;
    }
};