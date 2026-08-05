class Solution {
public:
    vector<string> cleanup(vector<string> &cand){
        int n = cand.size();
        int m = cand[0].size();

        string blank="";
        for(int i=0;i<n;i++){
            blank.push_back('.');
        }
        vector<string> ans(n,blank);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(cand[i][j]=='Q'){
                    ans[i][j]='Q';
                }
            }
        }
        return ans;
    }

    void attack(int id,int jd,vector<string> &cand){
        int n=cand.size();
        int m=cand[0].size();
        for(int j=0;j<m;j++){
            if(j==jd){
                continue;
            }
            if(cand[id][j]=='.'){
                cand[id][j]='1';
            }else{
                int attacks = cand[id][j]-'0';
                attacks++;
                cand[id][j] = (char)(attacks+'0');
            }
        }

        for(int i=0;i<n;i++){
            if(i==id){
                continue;
            }
            if(cand[i][jd]=='.'){
                cand[i][jd]='1';
            }else{
                int attacks = cand[i][jd]-'0';
                attacks++;
                cand[i][jd] = (char)(attacks+'0');
            }
        }
        //left corner
        int ilc=id;
        int jlc=jd;

        //right corner
        int irc=id;
        int jrc=jd;

        //going to left corner
        while(ilc!=0 && jlc!=0){
            ilc--;
            jlc--;
        }

        //going to right corner
        while(irc!=0 && jrc<m-1){
            irc--;
            jrc++;
        }

        //modifying left to right diagonal
        while(ilc<n && jlc<m){
            if(ilc==id && jlc==jd){
                ilc++;
                jlc++;
                continue;
            }
            if(cand[ilc][jlc]=='.'){
                cand[ilc][jlc]='1';
            }else{
                int attacks = cand[ilc][jlc]-'0';
                attacks++;
                cand[ilc][jlc] = (char)(attacks+'0');
            }
            ilc++;
            jlc++;
        }

        //modifying right to left diagonal
        while(irc<n && jrc>=0){
            if(irc==id && jrc==jd){
                irc++;
                jrc--;
                continue;
            }
            if(cand[irc][jrc]=='.'){
                cand[irc][jrc]='1';
            }else{
                int attacks = cand[irc][jrc]-'0';
                attacks++;
                cand[irc][jrc] = (char)(attacks+'0');
            }
            irc++;
            jrc--;
        }
    }

    void unattack(int id,int jd,vector<string> &cand){
        int n=cand.size();
        int m=cand[0].size();
        for(int j=0;j<m;j++){
            if(j==jd){
                continue;
            }
            int attacks = cand[id][j]-'0';
            attacks--;
            cand[id][j] = (char)(attacks+'0');
            if(cand[id][j]=='0'){
                cand[id][j]='.';
            }
        }

        for(int i=0;i<n;i++){
            if(i==id){
                continue;
            }
            int attacks = cand[i][jd]-'0';
            attacks--;
            cand[i][jd] = (char)(attacks+'0');
            if(cand[i][jd]=='0'){
                cand[i][jd]='.';
            }
        }

        int ilc=id;
        int jlc=jd;
        int irc=id;
        int jrc=jd;

        while(ilc!=0 && jlc!=0){
            ilc--;
            jlc--;
        }

        while(irc!=0 && jrc<m-1){
            irc--;
            jrc++;
        }

        while(ilc<n && jlc<m){
            if(ilc==id && jlc==jd){
                ilc++;
                jlc++;
                continue;
            }
            int attacks = cand[ilc][jlc]-'0';
            attacks--;
            cand[ilc][jlc] = (char)(attacks+'0');
            if(cand[ilc][jlc]=='0'){
                cand[ilc][jlc]='.';
            }
            ilc++;
            jlc++;
        }

        while(irc<n && jrc>=0){
            if(irc==id && jrc==jd){
                irc++;
                jrc--;
                continue;
            }
            
            int attacks = cand[irc][jrc]-'0';
            attacks--;
            cand[irc][jrc] = (char)(attacks+'0');
            if(cand[irc][jrc]=='0'){
                cand[irc][jrc]='.';
            }

            irc++;
            jrc--;
        }
    }
    void backtrack(
        vector<vector<string>> &ans,
        vector<string> &cand,
        int id,
        int n
    ){
        if(id==n){
            ans.push_back(cleanup(cand));
            return;
        }

        string &row=cand[id];
        for(int i=0;i<row.size();i++){
            if(row[i]!='.'){
                continue;
            }

            row[i]='Q';
            attack(id,i,cand);
            //Maybe in attack I also need to keep a count of how many attacks are
            backtrack(ans,cand,id+1,n);
            row[i]='.';
            unattack(id,i,cand);
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string blank="";
        for(int i=0;i<n;i++){
            blank.push_back('.');
        }
        vector<string> cand(n,blank);
        int id=0;
        backtrack(ans,cand,id,n);
        return ans;
    }
};
