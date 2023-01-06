using System;
using System.Collections.Generic;

public class Program
{
    private static void Main(string[] args)
    {
        string[] strs = { "euro" , "europa", "eurici", "eurelova", "abera"};
        Console.WriteLine(LongestCommonPrefix(strs));
    }
    public static string LongestCommonPrefix(string[] strs)
    {
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
        }while (true);
        return prefix;
    }
}