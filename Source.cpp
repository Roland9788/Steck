#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define NMAX 100
using namespace std;

struct Mystack
{
	float elem[NMAX];
	int top;
};

void init(struct Mystack *stk)
{
	stk->top = 0;
}

void push(struct Mystack* stk, float f) //���������� �������� � ����
{
	if (stk->top < NMAX)
	{
		stk->elem[stk->top] = f;
		stk->top++;
	}
	else
	{
		cout << "������������ ����� \n";
	}
}

float pop(struct Mystack* stk) //���������� ��������
{
	float elem;
	if ((stk->top) > 0)
	{
		stk->top--;
		elem = stk->elem[stk->top];
		return elem;
	}
	else
	{
		cout << "���� ����\n";
		return 0;
	}

}

float stkTop(struct Mystack* stk)
{
	if ((stk->top) > 0)
	{
		return stk->elem[stk->top - 1];
	}
	else
	{
		cout << "���� ����";
	}
	return 0;
}

int getcount(struct Mystack* stk)
{
	return  stk->top;
}

int isempty(struct Mystack* stk)
{
	if (stk->top == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void stkPrint(Mystack* stk)
{
	int i = 0;
	i = stk->top;
	if (isempty(stk) == 1)
	{
		return;
	}
	do
	{
		i--;
		cout << " " << i + 1 << " �������: " << stk->elem[i] << "\n";
	} while (i > 0);
}

int main()
{
	setlocale(LC_ALL, "Rus");

	Mystack* stk;
	int i, n;
	float elem;
	stk = (Mystack*)malloc(sizeof(Mystack));
	init(stk);
	printf("������� ���������� ��������� � �����: "); //��� �� cout
	scanf("%d", &n); // ���� ������ = cin

	for (i = 0; i < n; i++)
	{
		printf("������� ������� %d: ", i + 1);
		scanf("%f", &elem);
		push(stk, elem);
	}

	cout << "\n";
	printf("� ����� %d ���������: \n", getcount(stk));
	stkPrint(stk);
	cout << "\n";
	printf("������� ������� %f\n",stkTop(stk));
	cout << "\n";
	do
	{
		printf("��������� ������� %f, ", pop(stk));
		printf("� ����� �������� %d ��������� \n", getcount(stk) + 1);

	} while (isempty(stk) == 0);
	getchar();getchar();

	return 0;
}