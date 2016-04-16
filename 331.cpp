class Solution {
public:
	bool isValidSerialization(string preorder) {
		stack<char> st;
		for (int i=preorder.size()-1;i>=0;--i)
		{
			if (preorder[i]=='#')
			{
				st.push('#');
			}
			else if (preorder[i]==',')
			{
				continue;
			}
			else
			{
				while (i>0&&preorder[i-1]>='0'&&preorder[i-1]<='9')
				{
					i--;
				}
				if (st.size()>=2)
				{
					st.pop();
				}
				else
				{
					return false;
				}
			}
		}
		return st.size()==1?true:false;
	}
};