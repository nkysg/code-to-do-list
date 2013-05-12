#include <cstdio>

int main()
{
  int T;
	
	#ifdef TEST
	freopen("1.txt","r",stdin);
	#endif
	scanf("%d\n",&T);
	int cnt = 0;
	for (cnt = 1; cnt <= T; cnt++)
	{
		char buf[1024] = {0};
		int a[3] = {0};
		char* sbuf;
		
		scanf("%s",buf);
		for (sbuf=buf;*sbuf; sbuf++)
			a[*sbuf%3]++;
		
		int sum = a[1] * 1 + a[2] * 2 + a[0] * 3;
		printf("Case %d: ",cnt);
		char win[] = "TS";
		if (sum % 3 == 0)
		{
			printf("%c\n",win[a[0]&1]);
		}
		else if (sum % 3 == 1)
		{
			if (!a[1]) printf("T\n"); //322,311122
			else printf("%c\n",win[(a[0]+1)&1]);
		}
		else if (sum % 3 == 2) //311,311222
		{
			if (!a[2]) printf("T\n");
			else printf("%c\n",win[(a[0]+1)&1]);
		}
	}
	return 0;
}
