using System;
using System.Collections.Generic;

public class Program
{
    private static void Main(string[] args)
    {
        string[] strs = { "abab", "aba", "" };
        Console.WriteLine(LongestCommonPrefix(strs));
    }
    public static string LongestCommonPrefix(string[] strs)
    {
        Array.Sort(strs, (x,y) => x.Length.CompareTo(y.Length));
        if (string.IsNullOrEmpty(strs[0])) { return ""; }
        string prefix = "";
        string letters;
        int currentCheckIndex = 0;
        do
        {
            letters = "";
            foreach (string s in strs)
            {
                letters += s[currentCheckIndex];
            }
            var unique = new HashSet<char>(letters);
            if (unique.Count != 1)
            {
                break;
            }
            foreach(char c in unique)
            {
                prefix += c;
            }
            currentCheckIndex++;
            if(currentCheckIndex > strs[0].Length - 1) { break; }
        }while (true);
        return prefix;
    }
}