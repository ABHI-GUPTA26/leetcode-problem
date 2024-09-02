class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt1=0;
    int cnt2=0;
    int cnt3=0;
        int n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                cnt1++;
            }else if(bills[i]==10){
                   cnt2++;
                int remain=bills[i]-5;
                  if(cnt1<1){
                     return false;
                  }
                  cnt1--;
            }else{
                cnt3++;
                if(cnt2>=1 &&cnt1>=1){
                      cnt2--;
                      cnt1--;
                } else if(cnt1>=3){
                     cnt1=cnt1-3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};