// Note: 这个题是hard的原因在于题干要求每次转换中，想要转换成的char不能在str1中已经出现。
// 所以coding part并不难，难的地方在于list out all the cases and show how you gonna deal with them.
/*
case 1:
str1: a a
str2: c b
The anwser is false, so we need a map to make sure every char in str1 only map to one char in str2.

case 2:
str1: a b
str2: b c
In this case we know 'a' should not be transformed to b before we do something to 'b'. 
Well, we could do topological sort here but it's not necessary (and also when str2 is 'b a' it forms
a loop then topo-sort won't work), because when this happen we can just change all 'b' to a unused char in str1,
like 'd', and then we can change 'a' to 'b'. Thus， at least one char is not used in str1, the answer should be yes.

case 3:
str1: a b c d e f .... z (all 26 chars)
str2: x a a a c d ... x
In this case, because b, c, d all map to a, so we first make these three to same char, e.g 'd'. So things
become easy (also a, z to z).
str1: z d d d e f .... z (some char is not used now)
str2: x a a a c d ... x
okay, now it's same with case two, the answer is yes.

Now, the only case left is both str1 ans str2 have different 26 chars. 
Well, if str1 equals to str2 that's fine. When not, it must forms transform loop(s),
we can do nothing to it, then answer is false.
*/
class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(str1.length() != str2.length()) return false;
        if(str1 == str2) return true;
        unordered_map<char, char> m;
        for(int i = 0; i < str1.length(); i++) {
            if(m.find(str1[i]) == m.end()) {
                m[str1[i]] = str2[i];
            } else {
                if(m[str1[i]] != str2[i]) {
                    return false;
                }
            }
        }
        return set(str2.begin(), str2.end()).size() < 26;
    }
};
