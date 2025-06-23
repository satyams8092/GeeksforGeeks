class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        vector <int> freq(10, 0);
        for(int i : arr) freq[i]++;
        
        string s;
        int i = 9;
        int carry = 0;
        while(i >= 0){
            int num1 = 0;
            int num2 = 0;
            
            while(i >= 0 && freq[i] == 0) i--;
            if(i >= 0 && freq[i] != 0) num1 = i, freq[i]--;
            while(i >= 0 && freq[i] == 0) i--;
            if(i >= 0 && freq[i] != 0) num2 = i, freq[i]--;
            
            int sum = num1 + num2 + carry;
            int digit = sum % 10;
            s.push_back(char('0' + digit));
            carry = sum / 10;
        }
        
        while(s.back() == '0') s.pop_back();
        reverse(s.begin(), s.end());
        return s;
    }
};