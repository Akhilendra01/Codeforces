#include<iostream> 
using namespace std; 
 
int main() 
{ 
    int tc;
    cin >> tc;
    while(tc--)
    {
        int a,b;
        cin >> a >> b;
        if(a == b)cout << 0 << endl;
        else if(a%2 == b%2)
        {
            if(b > a)cout << 2 << endl;
            else cout << 1 << endl;
        }else{
            if(b > a)cout << 1 << endl;
            else cout << 2 << endl;
        }
    }
    return 0; 
}
