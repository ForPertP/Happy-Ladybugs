using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'happyLadybugs' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING b as parameter.
     */

    public static string happyLadybugs(string b)
    {
        //List<int> x = new List<int>(new int[26]);
        List<int> x = Enumerable.Repeat(0, 26).ToList();

        bool sp = false;
        int count = 0;
        char d = '!';

        foreach (char c in b)
        {
            if (c == '_')
            {
                sp = true;
                continue;
            }

            if (++x[c - 'A'] == 1)
            {
                count++;
            }

            if (d != c)
            {
                count--;
            }

            d = c;
        }

        if (!sp && count != 0)
        {
            return "NO";
        }

        foreach (int i in x)
        {
            if (i == 1)
            {
                return "NO";
            }
        }

        return "YES";
    }
}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int g = Convert.ToInt32(Console.ReadLine().Trim());

        for (int gItr = 0; gItr < g; gItr++)
        {
            int n = Convert.ToInt32(Console.ReadLine().Trim());

            string b = Console.ReadLine();

            string result = Result.happyLadybugs(b);

            textWriter.WriteLine(result);
        }

        textWriter.Flush();
        textWriter.Close();
    }
}
