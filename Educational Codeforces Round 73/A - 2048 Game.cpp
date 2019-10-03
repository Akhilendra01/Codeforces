#include <bits/stdc++.h> 
 
using namespace std;
 
int t,n,m;
 
bool fnd(int num,multiset<int>& nums,int target)
{
	if(num <= 1)return nums.count(num) >= target;
	if(nums.count(num) >= target)return true;
	target -= nums.count(num);
	return fnd(num/2,nums,target<<1);
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//---------------------------
	cin >> t;
	while(t--)
	{
		cin >> n;
		multiset<int> nums;
		while(n--)
		{
			cin >> m;
			nums.insert(m);
		}
		cout << (fnd(2048,nums,1)?"YES":"NO") << endl; 
	}
 
	return 0;
}
