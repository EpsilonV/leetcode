#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> smap;
        map<char, char> tmap;
       	for (int i = 0; i < s.size(); ++i)
       	{
       		char cs = s[i];
       		char ct = t[i];
       		if (smap.count(cs) && smap[cs] != ct)
       			return false;
       		else if (tmap.count(ct) && tmap[ct] != cs)
       			return false;	
       		else {
       			smap[cs] = ct;
       			tmap[ct] = cs;
       		}
       	}

       	return true;
    }
};

int main()
{
	Solution s = Solution();
	cout << s.isIsomorphic("ab", "aa") << endl;
	cout << s.isIsomorphic("abccba", "uvwuvw") << endl;
	cout << s.isIsomorphic("paper", "title") << endl;

	return 0;
}