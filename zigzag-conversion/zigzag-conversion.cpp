class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        int n=s.size();
        int gap = numRows - 1 + numRows -2;
        string ans="";
        int gap1 = gap;
        int gap2 = -1;
        for(int i=0;i<numRows;i++){
            int g = i;
            int j = 0;
            while(g<n){
                ans+=s[g];
                if(j==0){
                    g = g + (gap1==-1?gap2:gap1) + 1;j=1;
                }else{
                    g = g + (gap2==-1?gap1:gap2) + 1;j=0;
                }
            }
            gap1-=2;
            gap2+=2;
        }
        return ans;
    }
};