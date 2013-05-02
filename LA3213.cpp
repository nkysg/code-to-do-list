#include <cstdio>
#include <cstring>
#include <algorithm>

int main()
{
    char buf[105];

#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    while (scanf("%s",buf) != EOF)
    {
        char raw[26] = {0};
        char enc[26] = {0};
        char* str = buf;

        for (;*str;str++) raw[*str-'A']++;
        scanf("%s",buf);
        for (str=buf;*str;str++) enc[*str-'A']++;

        std::sort(raw,raw+26);
        std::sort(enc,enc+26);
        if (memcmp(raw,enc,sizeof(enc))) printf("NO\n");
        else printf("YES\n");

    }
    return 0;
}
