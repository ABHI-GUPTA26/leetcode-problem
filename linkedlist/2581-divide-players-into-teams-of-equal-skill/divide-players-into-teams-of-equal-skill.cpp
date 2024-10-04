class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        int team_cnt=n/2;
        int skill_sum=0;
        for(int i=0;i<n;i++){
           skill_sum+=skill[i];
        }
        if(skill_sum%team_cnt!=0){
            return -1;        }

            sort(skill.begin(),skill.end());
        long long  chemistry_sum=0;
        int start=0;
        int end=n-1;
        while(start<end){
            if(skill[start]+skill[end]==skill_sum/team_cnt){
                chemistry_sum+=skill[start]*skill[end];
                start++;
                end--;
            }else{
                return -1;
            }
        }
        return chemistry_sum;
    }
};