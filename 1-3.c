#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
char item;
int channel, price, number;
char nitem;
int nchannel, n, nprice, sum, input;

void buy()
{
	sum = 0;
	printf("������������ࡢͨ����š���Ҫ����������\n");
	scanf(" %c %d %d", &nitem, &nchannel, &n);
	if (nitem != item || nchannel != channel)
	{
		printf("��������ȷ�Ļ���������ͨ����ţ�\n");
		scanf(" %c %d %d", &nitem, &nchannel, &n);
	}
	if (nitem == item && nchannel == channel && n > number)
	{
		printf("��治�㣬�����������Ŀ\n");
		scanf(" %c %d %d", &nitem, &nchannel, &n);
	}
	nprice = price * n;
	printf("��ͶӲ��\n");
	while (sum < nprice)
	{
		scanf(" %d", &input);
		if (input != 1 && input != 2 && input != 5)
		{
			printf("��������ЧӲ��\n");
			continue;
		}
		sum += input;
	}
	number -= n;
	printf("���㣺%d\n", sum - nprice);
}
int main()
{
	printf("���������������ࡢͨ����š������Լ����������\n");
	scanf(" %c %d %d %d", &item, &channel, &price, &number);
	while (number != 0)
	{
		buy();
	}
	printf("���޴��\n");
	system("pause");
	return 0;
}

