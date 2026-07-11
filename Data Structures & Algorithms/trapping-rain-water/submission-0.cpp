class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> leftmax(size+1);
        vector<int> rightmax(size+1);
        leftmax[0]=0;
        rightmax[size]=0;
        for(int i=1;i<size+1;i++){
            leftmax[i]=max(leftmax[i-1],height[i-1]);
        }
        for(int i=size-1;i>=0;i--){
            rightmax[i]= max(rightmax[i+1],height[i]);
        }
        int ans = 0;
        for(int i=0;i<size;i++){
            int can =  min(leftmax[i],rightmax[i+1])-height[i];
            if(can>0){
                ans+=can;
            }
        }
        return ans;
    }
};
