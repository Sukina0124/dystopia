#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int sum = 0, need, change, input;
	printf("�������ܼ�\n");
	scanf("%d", &need);
	printf("������Ͷ�ҽ�ֻ����1Ԫ��2Ԫ��5Ԫ��\n");
	while(sum < need)
	{
		scanf("%d", &input);
		if(input != 1 && input != 2 && input != 5)
		{
			printf("��������Ч���\n");
			continue;
		}
		sum += input;
	}
	printf("��Ͷ��%dԪ\n", sum);
	printf("����%dԪ\n", sum - need);
	system("pause");
	return 0;
}