using System;
namespace LeetCode_Medium_3_LongestSubString
{
	public class Solution
	{
        public int LengthOfLongestSubstring(string s)
        {
            int maxLen = 0;
            int len = 0;
            int[] symbols = new int[150];
            for (int pos = 0; pos < s.Length; pos++)
            {
                int ind = pos;
                while (ind < s.Length && symbols[s[ind]] == 0)
                {
                    len++;
                    symbols[s[ind]]++;
                    ind++;
                }
                if (maxLen < len) maxLen = len;
                symbols = new int[150];
                len = 0;
            }
            return maxLen;
        }
    }
}

