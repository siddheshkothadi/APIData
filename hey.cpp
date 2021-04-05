#include<bits/stdc++.h>
using namespace std;

int main () {
    int cases;
    cin >> cases;
    
    vector<string> seg;
    
    seg.push_back("1111110");
    seg.push_back("0110000");
    seg.push_back("1101101");
    seg.push_back("1111001");
    seg.push_back("0110011");
    seg.push_back("1011011");
    seg.push_back("0011111");
    seg.push_back("1110000");
    seg.push_back("1111111");
    seg.push_back("1100110");
    
    while(cases--) {
        int len;
        cin >> len;
        
        string s;
        cin >> s;
        
        int inc = 0;
        string curr = "0000000";
        
        for(int i=0; i<len; ++i){
            char c = s[i];
            string t = seg[c-'0'];
            
            for(int j=0; j<7; ++j) {
                if(curr[j] != t[j]) {
                    if(curr[j] == '0') {
                        curr[j] = '1';
                    }
                    else {
                        curr[j] = '0';
                    }
                    ++inc;
                }   
            }
        }
        
        
        cout << inc << "\n";
        
    }
    

    return 0;
}
