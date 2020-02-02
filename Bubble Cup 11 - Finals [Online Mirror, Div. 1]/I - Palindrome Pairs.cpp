#include <bits/stdc++.h>
using namespace std;
 
int tc=1,n,pow_2[30];
map<int,int> cnt;
string str;
 
int getHash(){
    int freq[30] = {0};
    for(char c:str)freq[c-'a']++;
    int hash = 0;
    for(int i=0;i<26;i++)
        hash += (freq[i]%2) * pow_2[i];
    return hash;
}
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pow_2[0] = 1;
    for(int i=1;i<30;i++)pow_2[i] = pow_2[i-1] << 1;
}
 
void input()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> str;
        cnt[getHash()]++;
    }
}
 
void solve()
{
    long long int ans = 0;
    for(auto it=cnt.begin();it!=cnt.end();it++)
    {
        ans += (long long int)it->second * (it->second-1)/2;
        for(int i=0;i<26;i++)
        {
            if(it->first & pow_2[i])
            {
                auto temp = cnt.find( it->first - pow_2[i] );
                if(temp != cnt.end())
                    ans += (long long int)temp->second * it->second;
            }
        }
    }
    cout << ans << endl;
}
 
int main()
{
    preprocess();
    while(tc--){
        input();
        solve();
    }
    return 0;
}
