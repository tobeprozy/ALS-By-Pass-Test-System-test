#include<stdio.h>

int main()
{
	const char* aa = "2019/08/01";
	char cc[7];
	int i = 0;
	int count = 0;
	while (aa[i] != '\0')
	{
		i++;
		cc[i] = aa[i];
		if (aa[i] == '/')
		{
			count++;
		}
		if (count == 2)
			break;
	}
}