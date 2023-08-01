#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

int l_11, r_11;
int l_21, r_21;
vector<string> ans_11;
vector<string> ans_21;
bool same_11 = false;
bool same_21 = false;
bool END = false;

int main()
{
    string temp;
    while (cin >> temp)
    {
        if (END) continue;
        for (int i = 0; i < temp.length(); i++)
        {
            if (temp[i] == 'E') END = true;
            if (END) continue;
            if (temp[i] == 'W')
            {
                l_11++;
                l_21++;
            }
            if (temp[i] == 'L')
            {
                r_11++;
                r_21++;
            }
            if (l_11 == r_11 && l_11 == 10) same_11 = true;
            if (l_21 == r_21 && l_21 == 20) same_21 = true;
            if ((l_11 == 11 || r_11 == 11) && !same_11) { ans_11.push_back(to_string(l_11) + ":" + to_string(r_11)); l_11 = 0; r_11 = 0; }
            if ((l_21 == 21 || r_21 == 21) && !same_21) { ans_21.push_back(to_string(l_21) + ":" + to_string(r_21)); l_21 = 0; r_21 = 0; }
            if (same_11 && abs(l_11 - r_11) >= 2)
                { ans_11.push_back(to_string(l_11) + ":" + to_string(r_11)); l_11 = 0; r_11 = 0; same_11 = false; }
            if (same_21 && abs(l_21 - r_21) >= 2)
                { ans_21.push_back(to_string(l_21) + ":" + to_string(r_21)); l_21 = 0; r_21 = 0; same_21 = false; }
        }
    }
    { ans_11.push_back(to_string(l_11) + ":" + to_string(r_11)); l_11 = 0; r_11 = 0; }
    { ans_21.push_back(to_string(l_21) + ":" + to_string(r_21)); l_21 = 0; r_21 = 0; }
    for (string ans : ans_11) cout << ans << endl;
    cout << endl;
    for (string ans : ans_21) cout << ans << endl;
    return 0;
}