#include <iostream>
#include<vector>
using namespace std;

void gusfield_z(string pat, string txt){
    int p_len=pat.size();
    int t_len=txt.size();
    string new_str=pat+"#"+txt;
    vector<int> z;
    int i=0;
    while(i<new_str.size()){
        if(i<=p_len) z.push_back(0);
        else{
            int left=0,right=0;
            if(new_str[left]==new_str[i]){
                right=i;
                while(new_str[left]==new_str[right] && right<new_str.size()){
                    left++;
                    right++;
                }
            }
            z.push_back(left);
        }
        i++;
    }
    for(int i=0;i<new_str.size();++i){
        if(z[i]==p_len) 
            cout<<"Pattern found at index: "<<i-p_len-1<<"\n";
    }
}

int main()
{
    string p="aaa";
    string txt="baaabaaaba";
    
    gusfield_z(p,txt);
    // for(auto &i:vec){
    //     cout<<i<<" ";
    // }
    return 0;
}
