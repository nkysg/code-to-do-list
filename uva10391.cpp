#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

using std::cin;
using std::vector;
using std::string;

typedef struct dict
{
    dict* ch[26];
    int cnt;
} dict;

dict *root;

dict* newdict()
{
    dict* u = (dict*)malloc(sizeof(dict));
    for (int i = 0; i < 26; ++i)
        u->ch[i] = NULL;
    u->cnt = 0;
    return u;
}

void insertdict(const char* str)
{
    char* buf = const_cast<char*>(str);
    dict* node = root;

    for ( ; *buf; ++buf)
    {
        if (node->ch[*buf-'a'] == NULL)
            node->ch[*buf-'a'] = newdict();
        node = node->ch[*buf-'a'];
    }
    node->cnt = 1;
}

bool search(const char* beg, const char* end)
{
    char* buf = const_cast<char*>(beg);
    dict* node = root;

    for (; buf < end; buf++)
    {
        if (node->ch[*buf-'a'] == NULL) return false;
        node = node->ch[*buf-'a'];
    }
    return node->cnt == 1;
}

int main()
{
    vector<string> svec;
    string str;
    char buf[500];


    root = newdict();
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    while (scanf("%s",buf)!= EOF)
    {
        str=buf;
        svec.push_back(str);
        insertdict(str.c_str());
    }

    int i,j;
    for (i = 0; i < svec.size(); ++i)
    {
        const char* cstr = svec[i].c_str();
        size_t len = svec[i].size();

        for (j = 1; j < len-1;++j)
        {
            if (search(cstr,cstr+j) && search(cstr+j,cstr+len)) { printf("%s\n",cstr); break; }
        }
    }
    return 0;
}
