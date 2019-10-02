class Solution:
    def isIsomorphic1(self, s: str, t: str) -> bool:
        dkey = {}
        dvalue = {}
        for (x, y) in zip(s, t):
            cx = dkey.get(x, "")
            cy = dvalue.get(y, "")
            if cx == "" and cy == "":
                dkey[x] = y
                dvalue[y] = True
            elif cx != "" and cy == False:
                return False
            elif cx != y:
                return False

        return True

    def isIsomorphic2(self, s: str, t: str) -> bool:
        hash_map = {}
        for (x, y) in zip(s, t):
            if x in hash_map and y != hash_map[x]:
                return False
            if x  not in hash_map and y in hash_map.values():
                return False
            hash_map[x] = y

        return True


if __name__ == '__main__':
    s = Solution()
    assert(s.isIsomorphic1("ab", "aa")==False)
    assert(s.isIsomorphic1("egg", "add")==True)
    assert(s.isIsomorphic1("aba", "baa")==False)
    assert(s.isIsomorphic1("paper", "title")==True)
    assert(s.isIsomorphic2("ab", "aa")==False)
    assert(s.isIsomorphic2("egg", "add")==True)
    assert(s.isIsomorphic2("aba", "baa")==False)
    assert(s.isIsomorphic2("paper", "title")==True)