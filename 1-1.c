#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char item = 0;
	int channel = 0;
	int price = 0;
	int number = 0;
	printf("��ӭʹ���ۻ���\n");
	printf("������������ࡢ�������ڵ�ͨ����š����ﵥ���Լ��������\n");
	scanf("%c %d %d %d", &item, &channel, &price, &number);
	printf("����ɹ�\n");
	printf("%d: ", channel);
	for (int i = 0; i < number; i++)
	{
		printf("%c", item);
	}
	printf(" %d\n", price);
	system("pause");
	return 0;
}
