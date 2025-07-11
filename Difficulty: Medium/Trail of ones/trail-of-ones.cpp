class Solution {
  public:
    int countConsec(int n) {
        // code here
        if(n == 1) return 0;
        if(n == 2) return 1;
        int first = 0,second = 1;
        for(int i = 3;i<=n;i++){
            int t = i-2;
            int value = 1<<t;
            int current = first+second+value;
            first = second;
            second = current;
        }
        return second;
    }
};