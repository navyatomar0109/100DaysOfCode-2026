class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt = 0;
        int i = 0;
        int j = 0;

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        if(s.empty() || g.empty()){
            return 0;
        }

       

        while(j < s.size() &&  i < g.size()){
            if(s[j]>=g[i]){
                i++;
                j++;
                cnt++;
            }
            else{
                
                j++;
            }
        }
        return cnt;

    }
};