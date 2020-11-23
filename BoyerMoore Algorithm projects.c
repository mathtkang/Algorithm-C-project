#define _CRT_SECURE_NO_WARNINGS //SDL 관련 경고를 제거//
#include <stdio.h>

int table[500];
void countingTable(char pattern[], int table[]) 
{
	int length = 0;
	int i, j; 
	while (pattern[length] != '\0') 
	{
		length++; 
	} 
	
	for (i = 0; i < 500; i++) 
	{
		table[i] = length; 
	} 

	for (j = 0; j < length - 1; j++) 
	{
		table[pattern[j]] = length - 1 - j; 
	}
}

void BoyerMoore(char text[], char pattern[])
{
	countingTable(pattern, table); 
	int n = 0, m = 0, i = 0;
	int	j, k; 

	while (text[n] != '\0')
	{
		n++; 
	}

	while (pattern[m] != '\0') 
	{
		m++; 
	}

	while (i <= n - m) 
	{
		j = m - 1;  4
		k = i + m - 1; 4
		
		while (j >= 0 && pattern[j] == text[k])
		{
			j--; 
			k--; 
		}

		if (j == -1) 
		{
			printf("%d 위치에서 매칭이 되었습니다.\n", i);
		}

		i = i + table[text[k]]; 
	}
}

int main(void)
{
	char text[1000];
	char pattern[500];

	printf("텍스트를 입력하세요 : ");
	scanf("%s", text);

	printf("찾을 단어를 입력하세요 : ");
	scanf("%s", pattern);

	BoyerMoore(text, pattern);
	return 0;
}