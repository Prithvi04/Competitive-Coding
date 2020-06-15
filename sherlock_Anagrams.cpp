#include <bits/stdc++.h>

using namespace std;
#define MAX_CHAR 26

// Complete the sherlockAndAnagrams function below.
int toNum(char c) 
{ 
    return (c - 'a'); 
} 

int sherlockAndAnagrams(string s) {
     int N = s.length(); 
  
    // To store counts of substrings with given 
    // set of frequencies. 
    map<vector<int>, int> mp; 
  
    // loop for starting index of substring 
    for (int i=0; i<N; i++) 
    { 
        vector<int> freq(MAX_CHAR, 0); 
  
        // loop for length of substring 
        for (int j=i; j<N; j++) 
        { 
            // update freq array of current 
            // substring 
            freq[toNum(s[j])]++; 
  
            // increase count corresponding 
            // to this freq array 
            mp[freq]++; 
        } 
    } 
  
    // loop over all different freq array and 
    // aggregate substring count 
    int result = 0; 
    for (auto it=mp.begin(); it!=mp.end(); it++) 
    { 
        int freq = it->second; 
        result += ((freq) * (freq-1))/2; 
    } 
    return result; 


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
