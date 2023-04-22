#include <iostream>

using namespace std;

void robin_karp_matcher(string &T, string &P){
    int S=127;
    int L=997;
    int n=T.size();
    int m=P.size();

    int hP=0,hT=0;
    for(int i=0;i<m;i++){
        hP=((hP*S)%L+P[i])%L;
        hT=((hT*S)%L+T[i])%L;
    }
    if(hP==hT){
        cout<<"A match at 0\n";
    }
    int spow=1;
    for(int i=1;i<m;i++){
        spow=(spow*S)%L;
    }
    bool found=false;
    for(int i=1;i<=n-m;i++){
        hT=(hT-(T[i-1]*spow%L)+L)%L;
        hT=((hT*S)%L+T[i+m-1])%L;
        if(hP==hT){
            cout<<"A match at "<<i<<"\n";
            found=true;
        }
    }
    if(!found){
        cout<<"The pattern is not found in the string\n";
    }
}

int main()
{
    string T="abcjfsdjfsjdfksjabcfsjhfasiuhfabc";
    // string T="jsdkasjfsiufhduhuhhd";
    string P="abc";
    robin_karp_matcher(T,P);
    
    return 0;
}
