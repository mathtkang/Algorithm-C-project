#define _CRT_SECURE_NO_WARNINGS //SDL 관련 경고를 제거//
#include <stdio.h>
//예를 들어 TRUSTHARDTOOTHBRUSHES라 하고 패턴은 TOOTH라 하자.

int table[500]; //즉 table은 pattern과 text가 불일치 되었을 경우 
// 경로를 이동할 때 얼마만큼 이동해야 되는지 알려줌.

void countingTable(char pattern[], int table[]) 
{
	int length = 0;
	int i, j; 

	while (pattern[length] != '\0') 
	{
		length++; 
	} // 패턴의 테이블 전체길이를 파악한다. 총 길이는 5. 이유는 \0까지 포함시 5가 된다.
	// length = 5
	for (i = 0; i < 500; i++) 
	{
		table[i] = length; 
	} // table 배열에 pattern의 인덱스를 넣는다.

	for (j = 0; j < length - 1; j++) 
	{
		table[pattern[j]] = length - 1 - j; 
	} // 최종적으로 점프 정보 "전체길이(length) -index(인덱스) -1" 구성
	// ex. table[pattern[0]](pattern[0]은 T) => table[T] = 4(5 -0 -1) 에 배정.
	// ex. table[pattern[1]](pattern[0]은 O) => table[O] = 3(5 -1 -1) 에 배정.
	// ex. table[pattern[2]](pattern[0]은 O) => table[O] = 2(5 -2 -1) 에 배정.
	// ex. table[pattern[3]](pattern[0]은 T) => table[T] = 1(5 -3 -1) 에 배정.
	// ex. table[pattern[4]](pattern[0]은 H) => table[H] = 0(5 -4 -1) 에 배정.
}
// pattern = [TOOTH\0], table = [HTOOT]

void BoyerMoore(char text[], char pattern[])
{
	countingTable(pattern, table); 
	int n = 0, m = 0, i = 0;
	int	j, k; 

	while (text[n] != '\0')
	{
		n++; 
	}// text[n]길이 구하기(22)

	while (pattern[m] != '\0') 
	{
		m++; 
	}// pattern[m]길이 구하기(5)

	while (i <= n - m) //(n - m은 22 - 5 = 17)
	{
		j = m - 1;  4
		k = i + m - 1; 4
		
		// -1을 빼는 이유는 \0까지 배열에 포함시켰기에 -1을 해준다.

		while (j >= 0 && pattern[j] == text[k]) // pattern[]과 text[]가 불일치할 때까지 반복한다.
		{
			j--; 
			k--; 
		}
		//pattern[]은 이미 k의 값으로 인해 TOOTH에서 H부터 오른쪽으로 읽어들여진다.

		if (j == -1) // pattern[]과 text[]가 일치가 되었을 때
		{
			printf("%d 위치에서 매칭이 되었습니다.\n", i);
		}
		i = i + table[text[k]]; // 위에서 만든 table배열에서 불일치한 문자의 위치값만큼 이동한다.
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