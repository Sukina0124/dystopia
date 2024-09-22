#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char goods_type;
    int price;
    int quantity;
} Item;

Item inventory[5][50];
int total_cost = 0;
int current_state = 1;  // ��ǰ״̬

void place(char goods_type, int channel, int price, int quantity) {
    if (channel < 1 || channel > 5) {
        printf("ͨ�������Ч�������� 1 �� 5 ֮�䡣\n");
        return;
    }
    
    if (price < 0 || quantity < 0) {
        printf("�۸����������Ϊ�Ǹ�ֵ��\n");
        return;
    }

    for (int i = 0; i < 50; i++) {
        if (inventory[channel - 1][i].quantity == 0) {
            inventory[channel - 1][i].goods_type = goods_type;
            inventory[channel - 1][i].price = price;
            inventory[channel - 1][i].quantity = quantity;
            printf("�ڷŻ���: %c ��ͨ�� %d������ %d������ %d\n", goods_type, channel, price, quantity);
            break;
        }
    }
}

void select(char goods_type, int channel, int quantity) {
    if (channel < 1 || channel > 5) {
        printf("ͨ�������Ч�������� 1 �� 5 ֮�䡣\n");
        return;
    }
    
    for (int i = 0; i < 50; i++) {
        if (inventory[channel - 1][i].goods_type == goods_type && inventory[channel - 1][i].quantity >= quantity) {
            total_cost += inventory[channel - 1][i].price * quantity;
            inventory[channel - 1][i].quantity -= quantity;
            printf("ѡ����: %c ��ͨ�� %d���������� %d\n", goods_type, channel, quantity);
            return;
        }
    }
    printf("ͨ�� %d �е� %c ���ﲻ��򲻴��ڡ�\n", channel, goods_type);
}

void pay(int payment) {
    static int total_payment = 0;  // ��¼��Ͷ�ҽ��
    total_payment += payment;
    printf("Ͷ�� %d Ԫ����ǰ�ܽ�� %d Ԫ�������� %d Ԫ\n", payment, total_payment, total_cost);
    if (total_payment >= total_cost) {
        int change = total_payment - total_cost;
        printf("���� %d Ԫ\n", change);
        total_payment = 0;  // ����Ͷ�ҽ��
        total_cost = 0;     // �����ܻ���
        current_state = 2;
        printf("�ɼ���ѡ����Ʒ\n");
    }
}

int main() {
    char input[100];
    printf("��ڷ���Ʒ��һ��ͨ��ֻ�ɰڷ�һ����Ʒ��һ��ͨ����֧��һ�ΰڷţ�\n");
    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  // �Ƴ����з�
        
        if (strcmp(input, "END") == 0) {
            if (current_state == 1) {
                current_state = 2;  // ��ɰڻ�������ѡ��״̬
                printf("��ѡ����Ʒ\n");
            }
            else if (current_state == 2) {
                current_state = 3;  // ���ѡ�񣬽���Ͷ��״̬
                printf("�ܼ� %d\n", total_cost);
                printf("��Ͷ��\n");
            }
            continue;
        }

        if (current_state == 1) {
            // �ڻ�
            char goods_type;
            int channel, price, quantity;
            if (sscanf(input, "%c %d %d %d", &goods_type, &channel, &price, &quantity) == 4) {
                sscanf(input, "%c %d %d %d", &goods_type, &channel, &price, &quantity);
                place(goods_type, channel, price, quantity);
            }
            else {
                printf("��������ȷ�ĸ�ʽ\n");
                continue;
            }
        }
        else if (current_state == 2) {
            // ѡ����Ʒ
            char goods_type;
            int channel, quantity;
            if (sscanf(input, "%c %d %d", &goods_type, &channel, &quantity) == 3) {
                sscanf(input, "%c %d %d", &goods_type, &channel, &quantity);
                select(goods_type, channel, quantity);
            }
            else {
                printf("��������ȷ�ĸ�ʽ\n");
                continue;
            }
        }
        else if (current_state == 3) {
            // Ͷ��
            int payment;
            sscanf(input, "%d", &payment);
            if (payment == 1 || payment == 2 || payment == 5) {
                pay(payment);
            }
            else{
                printf("��������ЧӲ��\n");
                continue;
            }
                
        }
    }
   
    return 0;
}