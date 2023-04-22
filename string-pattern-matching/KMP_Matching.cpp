#include <iostream>
#include<vector>
using namespace std;

void KMP(string pat,string txt){
    vector<int> lps(pat.size(),0);
    for(int i=1;i<pat.size();i++){
        int j=lps[i-1];
        while(j>0 and pat[j]!=pat[i]){
            j=lps[j-1];
        }
        if(pat[j]==pat[i]) j++;
        lps[i]=j;
    }
    int n=txt.size(); int m=pat.size();
    int i=0;int j=0;
    vector<int> ans;
    while(i<n){
        if(pat[j]==txt[i]){
            i++;
            j++;
        }
        if(j==m){
            // ans.push_back(i-m);
            cout<<"Pattern found at position: "<<i-m<<"\n";
            j=lps[j-1];
        }else if(i<n and pat[j]!=txt[i]){
            if(j==0) i++;
            else j=lps[j-1];
        }
    }
    // return ans;
}

int main()
{
    string p="aaa";
    string txt="baaabaaaba";
    KMP(p,txt);
    
    return 0;
}
