class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans = 0;
         int n = h.size();


        // for(int el:h){
        //     ans = max(el,ans);
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int mn = INT_MAX;
        //         for(int k=i;k<=j;k++){
        //             mn = min(mn,h[k]);
        //         }
        //         ans = max(ans,(j-i+1)*mn);
        //     }
        // }



        // for(int i=0;i<n;i++){
        //     int a=i;
        //     int b=i;
        //     while(a-1>=0 && h[a-1]>=h[i]){
        //         a--;
        //     }
        //     while(b+1<n && h[b+1]>=h[i]){
        //         b++;
        //     }
        //     ans= max(ans,(b-a+1)*h[i]);
        // }

        stack<pair<int,int>> s;
        for(int i=0;i<n;i++){
            int el = h[i];
            int id=i;
            while(!s.empty() && s.top().second>el){
                pair<int,int> sel= s.top();
                s.pop();
                ans= max(ans,(sel.second*(i-sel.first)));
                id=sel.first;
            }
            s.push({id,el});
        }

        while(!s.empty()){
                pair<int,int> sel = s.top();
                s.pop();
                ans= max(ans,(sel.second*(n-sel.first)));
        }


        return ans;
    }
};
