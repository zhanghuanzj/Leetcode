class Solution {
public:
    string longestPalindrome(string s) {
        vector<char> str;
        init(s,str);
        vector<int> p;
        pCalculate(p,str);
        int beginIndex=0,endIndex=0, maxLength = 0;
        for (int i=1;i<p.size();++i)
        {
            if (p[i]>maxLength)
            {
                maxLength = p[i];
                if (maxLength>=2)
                {
                    beginIndex = (i-p[i]+2)/2-1;
                    endIndex = (i+p[i]-2)/2-1;
                }
            }
        }
        return s.substr(beginIndex,endIndex-beginIndex+1);
    }
    void init(string s, vector<char>& str)
    {
        str.push_back('$');
        str.push_back('#');
        for (int i=0;i<s.size();++i)
        {
            str.push_back(s.at(i));
            str.push_back('#');
        }
        str.push_back('&');
    }
    void pCalculate(vector<int>& p,vector<char>& str)
    {
        int boundary = 0;
        int currentCenter = 0;
        p.push_back(1);
        for (int i=1;i<str.size()-1;++i)
        {
            if (boundary>i) 
            {
                p.push_back(min(p[currentCenter*2-i],boundary-i));
            }
            else  
            {
                p.push_back(1);
            }
            while (str[i-p[i]]==str[i+p[i]])
            {
                p[i]++;
            }
            if (p[i]+i>boundary)
            {
                boundary = p[i]+i;
                currentCenter = i;
            }
        }
    }
};