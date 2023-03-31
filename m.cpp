void    check(string &s, int i, set<int, greater<int> > &se, int b)
{
    int idx = *se.begin();

    if (i - idx - (b * 3) == 2 && i + 1 < s.size() && s[idx] == 'A' && s[idx+1] == 'W' && s[i] == 'S')
    {
        b++;
        s[idx] = '+';
        s[idx+1] = '+';
        s[i] = '+';
        if (se.size() > 0)
            se.erase(se.begin());
        if (se.size() > 0)
            check(s, i+1, se, b);
    }
    else if (i - idx - (b * 3) == 1 && i + 1 < s.size() && s[idx] == 'A' && s[i] == 'W' && s[i+1] == 'S')
    {
        b++;
        s[idx] = '+';
        s[i] = '+';
        s[i+1] = '+';
        if (se.size() > 0)
            se.erase(se.begin());
        if (se.size() > 0)
            check(s, i+2, se, b);
    }
    return ;
}

string getFinalString(string s) {
    string ret;
    int b = 0;
    cin >> s;
    set<int, greater<int> > se;
    for(int i = 0; s[i]; i++)
    {
        if (i + 2 < s.size() && s[i] == 'A' && s[i + 1] == 'W' && s[i + 2] == 'S')
        {
            b++;
            s[i] = '+';
            s[i+1] = '+';
            s[i+2] = '+';
            if (se.size() > 0)
                check(s, i+3, se, b);
        }
        else if (s[i] == 'A')
        {
            b = 0;
            se.insert(i);
        }
    }
    for(int i = 0; s[i]; i++)
    {
        if (s[i] != '+')
            ret += s[i];
    }
    if (ret.length() == 0)
        return "-1";
    return ret;
}