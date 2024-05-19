// solution 1:

// class Solution
// {
// public:
//     string reverseWords(string s)
//     {
//         string word, reversed;
//         vector<string> wordlist;
//         // remove extra whitespaces
//         for (int i = 0; i < s.size(); i++)
//         {
//             word = "";
//             if (s[i] == ' ')
//             {
//                 continue;
//             }
//             while (s[i] != ' ' && i < s.size())
//             {
//                 word.push_back(s[i]);
//                 i++;
//             }
//             wordlist.push_back(word);
//         }
//         reverse(wordlist.begin(), wordlist.end());
//         for (auto &w : wordlist)
//         {
//             reversed += w;
//             reversed.push_back(' ');
//         }
//         reversed.pop_back();
//         return reversed;
//     }
// };

// solution 2:

// class Solution
// {
// public:
//     string reverseWords(string s)
//     {
//         string word, reversed;
//         stack<string> wordlist;
//         // remove extra whitespaces
//         for (int i = 0; i < s.size(); i++)
//         {
//             word = "";
//             if (s[i] == ' ')
//             {
//                 continue;
//             }
//             while (s[i] != ' ' && i < s.size())
//             {
//                 word.push_back(s[i]);
//                 i++;
//             }
//             wordlist.push(word);
//         }
//         int len = wordlist.size();
//         for (int i = 0; i < len; i++)
//         {
//             reversed += wordlist.top();
//             wordlist.pop();
//             reversed.push_back(' ');
//         }
//         reversed.pop_back();
//         return reversed;
//     }
// };
