int single(const vector<int> &vec)
{
	int num[32];
	for (int i = 0; i < 32; ++i)
	{
		num[i] = 0;
		for (std::vector<int>::const_iterator it = vec.cbegin(); it != vec.end(); ++it)
		{
			num[i] = (num[i]+(((*it)>>i)&1))%3;
		}
	}
	int result = 0;
	for(int i=0;i<32;++i)
	{
		result += num[i]*pow(2,i);
	}
	return result;
}