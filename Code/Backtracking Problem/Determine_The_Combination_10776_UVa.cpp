#include <bits/stdc++.h>
using namespace std;

int n, sz;
vector<char> ans;
bool taken[107];
char s[107];

void back()
{
    if (ans.size() == sz)
    {
        for (int i = 0; i < sz; i++)
            printf("%c", ans[i]);

        puts("");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (ans.size() > 0 && ans[ans.size() - 1] > s[i])
            continue;

        if (taken[i] == false)
        {
            taken[i] = true;
            ans.push_back(s[i]);
            back();
            taken[i] = false;
            ans.pop_back();
            while (s[i] == s[i + 1] && i + 1 < n)
                i++;
        }
    }
}

int main()
{
    while (scanf("%s %d", &s, &sz) == 2)
    {
        n = strlen(s);
        sort(s, s + n);
        ans.clear();
        memset(taken, false, sizeof taken);
        back();
    }
}

/*
    abcde 2
    abcd 3
    aba
*/