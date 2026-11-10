#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
Node *head=nullptr;
void insertHead(int x)
{
	Node *p=new Node;
	p->data =x;
	p->next =head;
	head=p;
}
void insertTail(int x)
{
	Node *p=new Node;
	p->data = x;
	p->next = nullptr;
	if(head == nullptr)
	{
		head = p;
		return ;
	}
	Node* cur =head;
	while(cur ->next != nullptr)
	{
		cur=cur->next;
	}
	cur->next=p;
}

void print()
{
	Node* cur =head;
	while(cur != nullptr)
	{
		cout << cur->data << " ";
		cur=cur->next;
	}
	cout <<"\n";
}
void remove(int x)
{
	if(head==nullptr)return;
	
	if(head->data==x)
	{
		Node*tmp =head;
		head=head->next;
		delete tmp;
		return ;
	}
	Node*cur=head;
	while(cur->next !=nullptr)
	{
		if(cur->next->data == x)
		{
			Node*tmp=cur->next;
			cur->next=cur->next->next;
			delete tmp;
//			cur->next = cur->next->next;
//			delete cur->next;   // 错！这时 cur->next 已经变成下下个了
			return ;
		}
		cur=cur->next;
	}
}
int main()
{
	insertTail(1);
	insertTail(2);
	insertTail(3);
	insertHead(0);
	print();  // 0 1 2 3
	
	remove(2);
	print();   // 0 1 3
	
	remove(0);     // 删头节点
	print();   // 1 3
	return 0;
}

