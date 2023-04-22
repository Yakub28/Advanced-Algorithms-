#include <iostream>


void search(std::string &pat, std::string  &txt)
{
    for (int i = 0; i <= txt.size()-pat.size(); i++) {
        int j;
        for (j = 0; j < pat.size(); j++)
            if (txt[i + j] != pat[j])
                break;
 
        if (j== pat.size())
            std::cout << "Pattern found at index " << i << std::endl;
    }
}

int main(){
    std::string text="shdjdkjskabcjaikdaajdkjabckaslkdossabc";
    std::string pattern="abc";
    
    search(pattern,text);
    return 0;
}
