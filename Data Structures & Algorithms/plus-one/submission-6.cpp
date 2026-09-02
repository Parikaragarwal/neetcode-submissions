class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i=n-1;
        while(i>=0){
            digits[i]=++digits[i]%10;
            if(digits[i]) return digits;
            i--;
        }
       
        digits.push_back(0);
        digits[0]=1;
        return digits;
    }
};
