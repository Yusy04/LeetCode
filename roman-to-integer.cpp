class Solution {
public:
    int indexString;

    int getThousand(string &s) {
        int cnt = 0;
        while (indexString < s.size() && s[indexString] == 'M') {
            cnt++;
            indexString++;
        }
        return cnt * 1000;
    }

    int getGeneralizedLayer(string &s, char chOne, char chFive, char chBiggerOne, int multiply) {
        int ans, cnt;
        ans = 0;
        if (s[indexString] == chFive) {
            indexString++;
            ans = 5;
            while (indexString < s.size() && s[indexString] == chOne) {
                indexString++;
                ans++;
            }
        }
        else if (s[indexString] == chOne) {
            indexString++;
            if (indexString < s.size() && s[indexString] == chBiggerOne) {
                ans = 9;
                indexString++;
            }
            else if (indexString < s.size() && s[indexString] == chFive) {
                ans = 4;
                indexString++;
            }
            else {
                ans = 1;
                while (indexString < s.size() && s[indexString] == chOne) {
                    indexString++;
                    ans++;
                }
            }
        }

        return multiply * ans;
    }

    int romanToInt(string s) {
        int ans;

        indexString = 0;
        ans = getThousand(s);
        ans += getGeneralizedLayer(s, 'C', 'D', 'M', 100);
        ans += getGeneralizedLayer(s, 'X', 'L', 'C', 10);
        ans += getGeneralizedLayer(s, 'I', 'V', 'X', 1);

        return ans;
    }
};
