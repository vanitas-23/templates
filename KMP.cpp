#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> computeLPS(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    
    int len = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    return lps;
}

vector<int> searchKMP(const string& s, const string& a) {
    vector<int> result;
    int n = s.length();
    int m = a.length();
    vector<int> lps = computeLPS(a);
    
    int i = 0;
    int j = 0;
    
    while (i < n) {
        if (a[j] == s[i]) {
            j++;
            i++;
        }
        
        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && a[j] != s[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return result;
}
