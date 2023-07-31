#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

class Solution 
{
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        if (words.empty()) return {}; // 如果words为空，直接返回空数组
        unordered_map<string, int> word_count;
        for (const auto& word : words) 
        {
            ++word_count[word]; // 统计出现次数
        }
        
        int word_len = words[0].size(); // 单词的长度，假设words中所有单词长度相同
        int num_words = words.size(); // 单词的个数
        int window_len = word_len * num_words; // 子串的长度，等于单词长度乘以单词个数
        vector<int> result; // 结果数组，存储符合条件的子串的起始位置
    
        for (int i = 0; i < word_len; i++) // 遍历s中所有可能的子串，每次移动一个单词的长度
        {
            int left = i, count = 0; // left是子串的左边界，count是有效单词的个数
            unordered_map<string, int> str_count; // 哈希表，记录子串中每个单词出现的次数
            for (int j = i; j <= (int)s.size() - word_len; j+= word_len) // 遍历子串中的每个单词
            {
                string word = s.substr(j, word_len); // 截取一个单词
                if (word_count.find(word) != word_count.end()) // 如果这个单词在words中存在
                {
                    ++str_count[word]; // 增加子串中这个单词的次数
                    if (str_count[word] <= word_count[word]) // 如果子串中这个单词的次数不超过words中对应的次数
                    {
                        ++count; // 增加有效单词的个数
                    } else // 如果子串中这个单词的次数超过了words中对应的次数
                    {
                        while (str_count[word] > word_count[word]) // 需要从左边开始删除多余的单词，直到恢复平衡
                        {
                            string start_word = s.substr(left, word_len); // 获取子串的第一个单词
                            --str_count[start_word]; // 减少子串中这个单词的次数
                            if (str_count[start_word] < word_count[start_word]) // 如果子串中这个单词的次数小于words中  对应的次数
                            {
                                --count; // 减少有效单词的个数
                            }
                            left += word_len; // 左边界向右移动一个单词的长度
                        }
                    }
                    if (count == num_words) // 如果有效单词的个数等于words中单词的个数，说明找到了一个符合条件的子串
                    {
                        result.push_back(left); // 将其起始位置加入结果数组
                        --str_count[s.substr(left, word_len)]; // 减少子串中第一个单词的次数
                        --count; // 减少有效单词的个数
                        left += word_len; // 左边界向右移动一个单词的长度
                    } 
                } 
                else // 如果这个单词不在words中存在，说明这个子串无效，需要重新开始检查
                {
                    str_count.clear(); // 清空子串中所有单词的次数
                    count = 0; // 清空有效单词的个数
                    left = j + word_len; // 左边界跳过这个无效的单词，从下一个开始检查
                }
            }
        }
        return result;
    }
};

int main()
{
    freopen("WRXInYue.in", "r", stdin);
    freopen("WRXInYue.out", "w", stdout);

    int n;
    scanf("%d", &n); // word list
    string a;
    cin >> a;
    vector<string> word;
    for(int i = 0; i < n; i++)
    {
        cin>>word[i];
    }
    
    Solution solve;
    vector<int> result = solve.findSubstring(a, word);
}