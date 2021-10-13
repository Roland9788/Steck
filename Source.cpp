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

void push(struct Mystack* stk, float f) //Дополнение элемента в стек
{
	if (stk->top < NMAX)
	{
		stk->elem[stk->top] = f;
		stk->top++;
	}
	else
	{
		cout << "Переполнение стека \n";
	}
}

float pop(struct Mystack* stk) //извлечение элемента
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
		cout << "Стак пуст\n";
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
		cout << "Стак пуст";
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
		cout << " " << i + 1 << " Элемент: " << stk->elem[i] << "\n";
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
	printf("Введите количество элементов в стеке: "); //тот же cout
	scanf("%d", &n); // ввод данных = cin

	for (i = 0; i < n; i++)
	{
		printf("Введите элемент %d: ", i + 1);
		scanf("%f", &elem);
		push(stk, elem);
	}

	cout << "\n";
	printf("В стеке %d элементов: \n", getcount(stk));
	stkPrint(stk);
	cout << "\n";
	printf("Верхний элемент %f\n",stkTop(stk));
	cout << "\n";
	do
	{
		printf("Извлекаем элемент %f, ", pop(stk));
		printf("В стеке осталось %d элементов \n", getcount(stk) + 1);

	} while (isempty(stk) == 0);
	getchar();getchar();

	return 0;
}