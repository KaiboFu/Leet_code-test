# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <map>
# include <cstdlib>
# include <cstdio>
# include <cstring>
using namespace std;

int lengthOfLongSubstring(string s){
    // 暴力搜索的改良版本，也对对一个字符串 从头到尾遍历查找
    int index = 0, max = 0, len = s.length();
    if (len < 2) return len;
    for (int i = 1; i < len; i++)
    {
        for (int j = i-1; j >= index; j--)
        {
            if(s[i] == s[j])
            {
                index = j + 1;
                break;
            }
            else
            {
                if (max < i - j +1)
                max = i - j + 1;
            }
        }
    }
    return max;
}

int lengthOfLongSubstring_1(string s){
    int cnt = -1, res = 0, appear[256];
    memset(appear, -1, sizeof(appear));
    //cout << appear[1] << ends << appear[2] << appear[0] << endl;
    for (int i = 0; i < s.size();i++){
        if (appear[s[i]] > cnt){
                // 更新字符串开始的位置， 一个子串不能包含两个相同字符
            cnt = appear[s[i]];
        }
        res = max(i - cnt, res);
        appear[s[i]] = i;
    }
    return res;
}

int lengthOfLongSubstring_2(string s) {
        int cnt=0,res=0,appear[256]={0};
        for(int i=0;i<s.size();i++){
            if(!appear[s[i]]){appear[s[i]]=1;cnt++;}
            else while(s[i-cnt]!=s[i]){appear[s[i-cnt]]=0; cnt--;}
            res=max(res,cnt);
        }
        return res;
}

int main(){
    string s = "tummzuxt";
    int len;
    len = lengthOfLongSubstring(s);
    cout << len << ends << lengthOfLongSubstring_2(s)<<endl;
    return 0;
}
