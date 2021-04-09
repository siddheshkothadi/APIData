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


// https://www.geeksforgeeks.org/longest-repeating-and-non-overlapping-substring/

// C++ program to find the longest repeated
// non-overlapping substring
#include<bits/stdc++.h>
using namespace std;

// Returns the longest repeating non-overlapping
// substring in str
string longestRepeatedSubstring(string str)
{
	int n = str.length();
	int LCSRe[n+1][n+1];

	// Setting all to 0
	memset(LCSRe, 0, sizeof(LCSRe));

	string res; // To store result
	int res_length = 0; // To store length of result

	// building table in bottom-up manner
	int i, index = 0;
	for (i=1; i<=n; i++)
	{
		for (int j=i+1; j<=n; j++)
		{
			// (j-i) > LCSRe[i-1][j-1] to remove
			// overlapping
			if (str[i-1] == str[j-1] &&
				LCSRe[i-1][j-1] < (j - i))
			{
				LCSRe[i][j] = LCSRe[i-1][j-1] + 1;
        cout << "\n";
        for(int x=0; x<=n; ++x) {
          cout << "\n";
          for(int y=0; y<=n; ++y) {
            cout << LCSRe[x][y] << "\t";
          }
        }

				// updating maximum length of the
				// substring and updating the finishing
				// index of the suffix
				if (LCSRe[i][j] > res_length)
				{
          cout << "\n\nLCSe[" << i << "][" << j << "] > (res_length)" << res_length;
					res_length = LCSRe[i][j];
					index = max(i, index);

          cout << "\nIndex = " << index;
				}
			}
			else
				LCSRe[i][j] = 0;
        cout << "\n\nLCSe[" << i << "][" << j << "] = 0";

        cout << "\n";
        for(int x=0; x<=n; ++x) {
          cout << "\n";
          for(int y=0; y<=n; ++y) {
            cout << LCSRe[x][y] << "\t";
          }
        }
		}
	}

	// If we have non-empty result, then insert all
	// characters from first character to last
	// character of string
	if (res_length > 0)
		for (i = index - res_length + 1; i <= index; i++)
			res.push_back(str[i-1]);

	return res;
}

int calculate(string str, int& num) {
  string repeatingSubstr = longestRepeatedSubstring(str);

  cout << "\nRepeating string : " << repeatingSubstr;

  if(repeatingSubstr.length()) {
    // Find
    auto i = str.find(repeatingSubstr);

    // Remove
    if(i != std::string::npos) {
      str.erase(i, repeatingSubstr.length());
    }

    cout << "\nRepeating substring removed... current value of string = " << str;

    ++num;

    cout << "\nNum = " << num;

    return calculate(str, num);
  }

  cout << "\nNum = " << num;
  return num;
}

int main()
{
	int cases;
  cin >> cases;

  while(cases--) {
    string str;
    cin >> str;
    
    int numberOfStrings = 1;
    int ans = calculate(str, numberOfStrings);

    cout << "\n\nFinal answer : " << ans;
  }

	return 0;
}
