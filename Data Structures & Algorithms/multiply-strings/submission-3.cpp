class Solution {
public:
    string singlemultiply(string &a,char ch){
        int carry=0;
        int d = ch-'0';
        string ans="";
        int n = a.size();
        for(int i=n-1;i>=0;i--){
            int val = (a[i]-'0')*d+carry;
            int curr = val%10;
            carry = val/10;
            ans.push_back((char)(curr+'0'));
        }
        if(carry!=0){
            ans.push_back((char)(carry+'0'));
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string add(string &a,string b){
        if(a.size()<b.size()) swap(a,b);
        int n = a.size();
        int m = b.size();

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ans;

        int i=0;
        int j=0;
        int carry=0;
        while(i<n || j<m || carry){
            int val =0;
            if(i<n) val+=a[i]-'0';
            if(j<m) val+=b[j]-'0';
            val+=carry;
            
            ans.push_back((char)((val%10)+'0'));
            carry=val/10;
            i++;
            j++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string multiply(string a, string b) {
        if(a=="0" || b=="0") return "0";
        if(a=="1") return b;
        if(b=="1") return a;

        // if(a.size()>b.size()) swap(a,b);
        int n = a.size();
        int m = b.size();
        vector<int> ans(n+m,0);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val = (a[i]-'0')*(b[j]-'0');
                ans[i+j]+=(val);
                ans[i+j+1]+=ans[i+j]/10;
                ans[i+j]%=10;
            }
        }
        string res = "";
        for(int i=0;i<n+m;i++){
            res.push_back((char)(ans[i]+'0'));
        }
        while(res.back()=='0'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        return res;
         
        // string ans = "";

        // for(int i=m-1;i>=0;i--){
        //     ans=add(ans,singlemultiply(a,b[i]));
        //     a.push_back('0');
        // }
        // return ans;
    }
};
