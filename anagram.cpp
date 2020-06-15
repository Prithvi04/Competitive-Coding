#include <bits/stdc++.h>

using namespace std;
int anagram(string s)
{
    if(s.size()%2==0)
    {
        string s1=s.substr(0,(s.size())/2);
        string s2=s.substr(((s.size())/2),(s.size()-1));

        int m[256]={0};
        for(int i=0;i<s1.length();i++)
        {
            m[s1[i]]++;
        }
        int count=0;
        for(int i=0;i<s2.length();i++)
        {
            if(m[s2[i]]>0)
            m[s2[i]]--;

        }
        for(int i=0;i<256;i++)
        {
            count+=m[i];
        }
        return count;
    }
}