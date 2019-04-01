#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

//�������
Node* BuyNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

//��ԭ�����Ͻ��в���
Node* reverse2(Node* head) {
	Node* cur = head;
	Node* pre = NULL;
	Node* next = cur->next;
	while (cur != NULL) {
		cur->next = pre;
		pre = cur;
		cur = next;
		if (next != NULL) {
			next = next->next;
		}
	}
	return pre;
}

void NodePrint(Node* head) {
	Node* cur = head;
	//�Ƚ����п�
	if (cur == NULL) {
		printf("����Ϊ�գ�����\n");
		return;
	}
	while (cur != NULL) {
		printf("%d -->", cur->data);
		cur = cur->next;
	}
	return;
}


int main() {
	//�������
	Node* n1 = BuyNode(10);
	Node* n2 = BuyNode(20);
	Node* n3 = BuyNode(30);
	Node* n4 = BuyNode(40);
	//��������
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	NodePrint(n1);
	printf("\n\n���ú������\n\n");
	//��������
	Node* result = reverse2(n1);
	NodePrint(result);
	system("pause");
	return 0;
}



//�ô���������ķ�ʽ����������
Node* reverse(Node* head) {
	Node* cur = head;
	Node* result = NULL;
	//����һ����������ԭ���������еĽ��ͷ�嵽��������
	//�Ƚ����п�
	if (cur == NULL) {
		return NULL;
	}
	while (cur != NULL) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = cur->data;
		node->next = result;
		result = node;
		cur = cur->next;
	}
	return result;
}





