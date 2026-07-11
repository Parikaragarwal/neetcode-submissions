class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        for(int i=0;i<size-1;i++){
            for(int j=i+1;j<size;j++){
                if(numbers[i]+numbers[j]==target){
                    return {i+1,j+1};
                }
            }
        }
        return {-1,-1};
    }
};
