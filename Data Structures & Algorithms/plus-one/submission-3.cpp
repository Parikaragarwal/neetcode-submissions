class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i=n-1;
        while(i>=0){
            if(digits[i]==9){
                digits[i]=0;
            }else{
                digits[i]++;
                break;
            }
            i--;
        }
        if(digits[0]==0){
            digits.push_back(0);
            digits[0]=1;
        }

        return digits;
    }
};
