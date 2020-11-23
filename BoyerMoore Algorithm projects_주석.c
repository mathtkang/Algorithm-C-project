#define _CRT_SECURE_NO_WARNINGS //SDL ���� ��� ����//
#include <stdio.h>
//���� ��� TRUSTHARDTOOTHBRUSHES�� �ϰ� ������ TOOTH�� ����.

int table[500]; //�� table�� pattern�� text�� ����ġ �Ǿ��� ��� 
// ��θ� �̵��� �� �󸶸�ŭ �̵��ؾ� �Ǵ��� �˷���.

void countingTable(char pattern[], int table[]) 
{
	int length = 0;
	int i, j; 

	while (pattern[length] != '\0') 
	{
		length++; 
	} // ������ ���̺� ��ü���̸� �ľ��Ѵ�. �� ���̴� 5. ������ \0���� ���Խ� 5�� �ȴ�.
	// length = 5
	for (i = 0; i < 500; i++) 
	{
		table[i] = length; 
	} // table �迭�� pattern�� �ε����� �ִ´�.

	for (j = 0; j < length - 1; j++) 
	{
		table[pattern[j]] = length - 1 - j; 
	} // ���������� ���� ���� "��ü����(length) -index(�ε���) -1" ����
	// ex. table[pattern[0]](pattern[0]�� T) => table[T] = 4(5 -0 -1) �� ����.
	// ex. table[pattern[1]](pattern[0]�� O) => table[O] = 3(5 -1 -1) �� ����.
	// ex. table[pattern[2]](pattern[0]�� O) => table[O] = 2(5 -2 -1) �� ����.
	// ex. table[pattern[3]](pattern[0]�� T) => table[T] = 1(5 -3 -1) �� ����.
	// ex. table[pattern[4]](pattern[0]�� H) => table[H] = 0(5 -4 -1) �� ����.
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
	}// text[n]���� ���ϱ�(22)

	while (pattern[m] != '\0') 
	{
		m++; 
	}// pattern[m]���� ���ϱ�(5)

	while (i <= n - m) //(n - m�� 22 - 5 = 17)
	{
		j = m - 1;  4
		k = i + m - 1; 4
		
		// -1�� ���� ������ \0���� �迭�� ���Խ��ױ⿡ -1�� ���ش�.

		while (j >= 0 && pattern[j] == text[k]) // pattern[]�� text[]�� ����ġ�� ������ �ݺ��Ѵ�.
		{
			j--; 
			k--; 
		}
		//pattern[]�� �̹� k�� ������ ���� TOOTH���� H���� ���������� �о�鿩����.

		if (j == -1) // pattern[]�� text[]�� ��ġ�� �Ǿ��� ��
		{
			printf("%d ��ġ���� ��Ī�� �Ǿ����ϴ�.\n", i);
		}
		i = i + table[text[k]]; // ������ ���� table�迭���� ����ġ�� ������ ��ġ����ŭ �̵��Ѵ�.
	}
}

int main(void)
{
	char text[1000];
	char pattern[500];

	printf("�ؽ�Ʈ�� �Է��ϼ��� : ");
	scanf("%s", text);

	printf("ã�� �ܾ �Է��ϼ��� : ");
	scanf("%s", pattern);

	BoyerMoore(text, pattern);
	return 0;
}