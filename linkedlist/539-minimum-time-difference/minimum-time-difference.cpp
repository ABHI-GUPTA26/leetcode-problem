class Solution {
public: 
    int mindiffernce(string str1,string str2){
        int pos1=str1.find(':');
        int hour1=stoi(str1.substr(0,pos1));
        int min1=stoi(str1.substr(pos1+1));

        int pos2=str2.find(':');
        int hour2=stoi(str2.substr(0,pos2));
        int min2=stoi(str2.substr(pos2+1));
         int mindiff= abs((60*hour2+min2)-(60*hour1+min1));
         return min(mindiff,1440-mindiff);
    }
    int findMinDifference(vector<string>& timePoints) {
       sort(timePoints.begin(),timePoints.end());
         int n=timePoints.size();
       int mindiff=INT_MAX;
        for(int i=1;i<n;i++){
            int temp=mindiffernce(timePoints[i],timePoints[i-1]);
            mindiff=min(mindiff,temp);
        }
      int  temp=mindiffernce(timePoints[0],timePoints[n-1]);

        return min(mindiff,temp);
    }
};