#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        vector<pair<int, char>> smap(26, make_pair(0, 'a'));
        for (int i = 0; i < 26; i++)
            smap[i].second += i;
        for (auto c : S)
            ++smap[c - 'a'].first;
        sort(smap.begin(), smap.end(), [](auto& a, auto& b) {return a.first > b.first;});
        // for (auto a : smap)
        //     cout << a.first << ": " << a.second << endl;
        int len = S.size();
        if (smap[0].first > (len + 1) / 2)
            return "";
        string ans(len, '0');
        int pos = 0;
        for (int i = 0; i < 26; ++i) {
            while (smap[i].first > 0) {
                --smap[i].first;
                ans[pos] = smap[i].second;
                pos += 2;
                if (pos >= len)
                    pos = 1;
            }
        }
        return ans;
    }
};

int main()
{
        Solution fun;
        string s("tndsewnllhrtwsvxenkscbivijfqnysamckzoyfnapuotmdexzkkrpmppttficzerdndssuveompqkemtbwbodrhwsfpbmkafpwyedpcowruntvymxtyyejqtajkcjakghtdwmuygecjncxzcxezgecrxonnszmqmecgvqqkdagvaaucewelchsmebikscciegzoiamovdojrmmwgbxeygibxxltemfgpogjkhobmhwquizuwvhfaiavsxhiknysdghcawcrphaykyashchyomklvghkyabxatmrkmrfsppfhgrwywtlxebgzmevefcqquvhvgounldxkdzndwybxhtycmlybhaaqvodntsvfhwcuhvuccwcsxelafyzushjhfyklvghpfvknprfouevsxmcuhiiiewcluehpmzrjzffnrptwbuhnyahrbzqvirvmffbxvrmynfcnupnukayjghpusewdwrbkhvjnveuiionefmnfxao");
        cin >> s;
        cout << fun.reorganizeString(s) << endl;
}