class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor){
            return 1;
        }
        bool sign=false;
        if(dividend>=0 && divisor<0){
            sign=true;
        }
        if(dividend<0 && divisor>0){
            sign=true;
        }
        long long  a=abs(dividend);
        long long  b=abs(divisor);
        long long int ans=0;
        while(a>=b){
            long long int cnt=0;
            while(a>=(b<<(1+cnt))){
                cnt++;
            }
            a=a-(b<<cnt);
            ans+=(1<<cnt);
        }
        if(ans==(1<<31) && sign){
            return INT_MIN;
        }
        if(ans==(1<<31) && !sign){
            return INT_MAX;
        }

        return sign?-ans:ans;
    }
};