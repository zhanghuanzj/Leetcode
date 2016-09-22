#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		while(n--)
		{
			int N,L;
			cin>>N>>L;
			vector<int> nums(L,0);
			vector<int> record(N,0);
			for (int i=0;i<L;++i)
			{
				cin>>nums[i];
			}
			int index = 0,pre = 0;
			for (int i=0;i<L;++i) 
			{
				if (record[nums[i]-1])
				{
					pre = record[nums[i]-1];
					index = i;
					break;
				}
				record[nums[i]-1]=i+1;
			}
			bool isB = false;
			for (int k = pre;k<=index;++k) {
				bool flag = false;
				fill(record.begin(),record.end(),0);
				int count = 0;
				for (int i=k;i<L;++i) 
				{
					if (record[nums[i]-1])
					{
						if (count<N)
						{
							flag = true;
							break;
						}
						else
						{
							count = 0;
							fill(record.begin(),record.end(),0);
						}
					}
					record[nums[i]-1]++;
					++count;
				}
				if (!flag)
				{
					isB = false;
					break;
				}
				else
				{
					isB = true;
				}
			}
			if (isB)
			{
				cout<<"B"<<endl;
			}
			else
			{
				cout<<"CAN'T DECIDE"<<endl;
			}
		}
	}
	return 0;
}