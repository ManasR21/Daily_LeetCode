#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumDeletions(string s)
    {
        int countofa = 0;
        int countofb = 0;

        int n = s.length();
        int deletion = n;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
                countofa++;
        }

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                countofa--;
            }
            deletion = min(deletion, countofa + countofb);
            if (s[i] == 'b')
            {
                countofb++;
            }
        }

        return deletion;
    }
};