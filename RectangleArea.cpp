class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C-A)*(D-B)+(G-E)*(H-F);
        int width = length(A,C,E,G);
        int heigth = length(B,D,F,H);
        return area-width*heigth;
    }

    int length(int x,int y,int z,int k)
    {
    	if (z>=y||x>=k)
    	{
    		return 0;
    	}
    	int vars[4] = {x,y,z,k};
    	sort(begin(vars), end(vars));
    	return vars[2] - vars[1];
    }
};