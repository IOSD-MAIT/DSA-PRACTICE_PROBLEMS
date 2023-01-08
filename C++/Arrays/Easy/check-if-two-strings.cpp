/*                    LEETCODE PROBLEM: 1662
                       Check If Two String Arrays are Equivalent
                   
https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
  
Given two string arrays word1 and word2, r]eturn true if the two  arrays represent the same string, and false otherwise.
A string is represented by an array if the array elements concatenated in order forms the string.
Example 1:
  Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
  Output: true
  Explanation:
  word1 represents string "ab" + "c" -> "abc"
  word2 represents string "a" + "bc" -> "abc"
  The strings are the same, so return true.
*/
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string a="";
        string b="";
        
        for(int i=0;i<word1.size();i++)
        {
            a+=word1[i];
        }
        for(int j=0;j<word2.size();j++)
        {
            b+=word2[j];
        }
        
        if(a==b)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};
