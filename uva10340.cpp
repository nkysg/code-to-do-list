#include <cstdio>

bool search(char* strbuf,char* subbuf)
{
    char* str, *substr;
    str = strbuf;

    for (substr = subbuf; *substr; substr++)
    {
        for (; *str;str++)
            if (*str == *substr) break;

         if (*str == '\0') return false;
         str++;
    }
    return true;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif

    char subbuf[1024],buf[1024];
    while (scanf("%s %s",subbuf,buf) != EOF)
    {
        if (search(buf,subbuf)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
