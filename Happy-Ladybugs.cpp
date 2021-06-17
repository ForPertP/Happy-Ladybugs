string happyLadybugs(string b)
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
