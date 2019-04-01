#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

//创建结点
Node* BuyNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

//在原链表上进行操作
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
	//先进行判空
	if (cur == NULL) {
		printf("链表为空！！！\n");
		return;
	}
	while (cur != NULL) {
		printf("%d -->", cur->data);
		cur = cur->next;
	}
	return;
}


int main() {
	//创建结点
	Node* n1 = BuyNode(10);
	Node* n2 = BuyNode(20);
	Node* n3 = BuyNode(30);
	Node* n4 = BuyNode(40);
	//连接链表
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	NodePrint(n1);
	printf("\n\n逆置后的链表：\n\n");
	//进行逆置
	Node* result = reverse2(n1);
	NodePrint(result);
	system("pause");
	return 0;
}



//用创建新链表的方式来进行逆置
Node* reverse(Node* head) {
	Node* cur = head;
	Node* result = NULL;
	//创建一个新链表，将原来的链表中的结点头插到新链表中
	//先进行判空
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





