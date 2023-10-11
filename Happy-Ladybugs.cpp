#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'happyLadybugs' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING b as parameter.
 */


string happyLadybugs(string b)
{
    int c = std::count(b.begin(), b.end(), '_');
    int check = 0;
    int n = b.size() - c;

    if (c != 0)
    {
        std::sort(b.begin(), b.end());
    }

    for (int i = 0; i < n; ++i)
    {
        if (b[i] == b[i-1] || b[i] == b[i+1])
        {
            check++;
        }
    }

    if (check == n)
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}


string happyLadybugs1(string b)
{
    int n = b.size();
    int c = std::count(b.begin(), b.end(), '_');
    int check = 0;

    if (c == 0)
    {
        for (int i = 0; i < n; ++i)
        {
            if (b[i] == b[i - 1] || b[i] == b[i + 1])
            {
                check++;
            }
        }

        if (check == n)
        {
            return "YES";
        }
        else
        {
            return "NO";
        }
    }
    else
    {
        std::sort(b.begin(), b.end());

        for (int i = 0; i < n - c; ++i)
        {
            if (b[i] == b[i - 1] || b[i] == b[i + 1])
            {
                check++;
            }
        }

        if (check == n - c)
        {
            return "YES";
        }
        else
        {
            return "NO";
        }
    }
}
