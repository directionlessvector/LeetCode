class Solution {
public:
    bool checkVowel (char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    int vowelConsonantScore(string s) {
        int v = 0, c = 0;
        for (char x : s) {
            if (checkVowel(x))
                v++;
            else if (isalpha(x)) 
                c++;
        }

        if (c != 0)
            return v / c;
        else 
            return 0;
    }   
};