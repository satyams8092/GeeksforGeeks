class Solution {
  public:
    string caseSort(string& s) {
        // code here
        string upper="";
        string lower="";
        for(char &ch:s){
            if(ch>='a' && ch<='z'){
                lower+=ch;
            }else upper+=ch;
        }
        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());
        int i=0, j=0;
        
        for(char &ch:s){
            if(ch>='a' && ch<='z'){
                ch=lower[i++];
            }else ch=upper[j++];
        }
        return s;
    }
};