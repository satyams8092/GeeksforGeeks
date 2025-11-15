class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<int>st1;
        stack<int>st2;
        
        st1.push(color[0]);
        st2.push(radius[0]);
        for(int i=1;i<color.size();i++){
            if(!st1.empty() && !st2.empty() && color[i] == st1.top() && radius[i]== st2.top()){
                st1.pop();
                st2.pop();
            }
            else{
                st1.push(color[i]);
                st2.push(radius[i]);
            }
        }
        
        return st1.size();
    }
};