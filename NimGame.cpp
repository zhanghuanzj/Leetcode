class Solution {
public:
    bool canWinNim(int n) {
        if ((n%4<=3)&&(n%4>=1))
        {
        	return true;
        }
        return false;
    }
};