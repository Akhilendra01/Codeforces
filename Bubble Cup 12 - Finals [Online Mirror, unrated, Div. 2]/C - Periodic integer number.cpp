#include <bits/stdc++.h>
using namespace std;
 
int l,len;
string s;
vector<string> segments;
 
string findSum(string str1, string str2) 
{ 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n2 - n1; 
  
    // Initially take carry zero 
    int carry = 0; 
  
    // Traverse from end of both strings 
    for (int i=n1-1; i>=0; i--) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0') + 
                   (str2[i+diff]-'0') + 
                   carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining digits of str2[] 
    for (int i=n2-n1-1; i>=0; i--) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 
 
string inc(string num)
{
    return findSum(num,"1");
}
 
bool allNines(string str)
{
    for(int i=0;i<str.length();i++)
        if(str[i] != '9')return false;
    return true;
}
 
void solveFirstCase(){
    
        for(int i=0;i<len/l + 1;i++)
        {
            printf("1");
            for(int j=1;j<l;j++)printf("0");
        }
        printf("\n");   
}
 
int main(){
    cin >> l >> s;
    len = s.length();
    if(len % l)
    {
        solveFirstCase();
    }else{
        for(int i=0;i<len;i+=l)segments.push_back(s.substr(i,l));
        int m = segments.size();
        bool allEqual = 1;
        for(int i=m-1;i>0;i--)
        {
            if(segments[i] > segments[i-1])
            {
                segments[i] = inc(segments[i-1]);
                segments[i-1] = segments[i];
                allEqual = 0;
                
            }else if(segments[i] < segments[i-1])
            {
                segments[i] = segments[i-1];
                allEqual = 0;
            }
        }
        if(allEqual)
        {
            if(allNines(segments[0]))
            {
                solveFirstCase();
                return 0;
            }
            segments[0] = inc(segments[0]);
        }
        
        for(int i=0;i<m;i++)cout << segments[0];
        cout << endl;
    }
    return 0;
}
