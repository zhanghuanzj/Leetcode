#include<iostream>
#include<string>
using namespace std;
int countZero(string s)
{
	s = s+"1";
	int maxi = 0;
	int count = 0;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]=='0')
		{
			++count;
		}
		else
		{
			maxi = max(maxi,count);
			count = 0;
		}
	}
	return maxi;
}
string turn(string s,int index,int k)
{
	for(int i=0;i<k;++i){
		if(s[index+i]=='1')
		{
			s[index+i] = '0';
		}
		else
		{
			s[index+i] = '1';
		}
	}
	return s;
}
int main()
{
	int n;
	while(cin>>n)
	{
		while(n--)
		{
			string s;
			int k,count = 0;
			cin>>k>>s;
			for(int i=0;i<=s.size()-k;++i)
			{
				count = max(count,countZero(turn(s,i,k)));
			}
			cout<<count<<endl;
		}
	}
	return 0;
}