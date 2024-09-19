class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<int>result;
      int n=s.size();
      for(int i=0;i<n;i++){
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'){
        vector<int>left_result=diffWaysToCompute(s.substr(0,i));
        vector<int>right_result=diffWaysToCompute(s.substr(i+1));
            for(auto it1:left_result){
                for(auto it2:right_result){
                    if(s[i]=='+'){
                        result.push_back(it1+it2);
                    }else if(s[i]=='-'){
                        result.push_back(it1-it2);
                    }else{
                        result.push_back(it1*it2);
                    }
                }
            }

      }}
      if(result.size()==0){
        result.push_back(stoi(s));
      }
      return result;
    }
};