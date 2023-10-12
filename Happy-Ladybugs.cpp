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


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
