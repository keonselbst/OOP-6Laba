#include <iostream>
#include "list.h"
#include<Windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	int choice;
	do
	{
		cout << "0.Завершить работу\n1.Групповое добавление\n2.Групповое удаление\n3.Групповая замена\n4.Найти элемент\n5.Найти группу элементов\n";
		cin >> choice;
		LIST<int> q;
		ifstream file("list.txt");
		if (!file.is_open()) 
		{
	       std::cout << "Files not open";
	       return 0;
	    }
		q.create_by_queue(file);
		file.close();
		cout << "Список: ";
		q.print();
		switch (choice)
		{
		case 1:
		{
			int a;
			cout << "Вставить после: ";
			cin >> a;
			NODE<int>* ptr = q.get_head();
			for (int i = 0; i < a; ++i)
			{
				ptr = ptr->next;
			}
			cout << "Вставить элементы от: ";
			cin >> a;
			NODE<int>* ptr2 = q.get_head();
			for (int i = 0; i < a; ++i)
			{
				ptr2 = ptr2->next;
			}
			cout << "Вставить элементы до: ";
			cin >> a;
			NODE<int>* ptr3 = q.get_head();
			for (int i = 0; i < a; ++i)
			{
				ptr3 = ptr3->next;
			}
			q.group_add(ptr, ptr2, ptr3);
			q.print();
			break;
		}
		case 2:
		{
			int a;
			NODE<int>* ptr = q.get_head();
			NODE<int>* ptr2 = q.get_head();
			cout << "Удалить после: ";
			cin >> a;
			for (int i = 0; i < a; ++i)
			{
				ptr = ptr->next;
			}
			cout << "Удалить до: ";
			cin >> a;
			for (int i = 0; i < a; ++i)
			{
				ptr2 = ptr2->next;
			}
			q.group_delete(ptr, ptr2);
			q.print();
			break;
		}
		case 3:
		{
			LIST<int> p;
			file.open("list.txt");
			p.create_by_queue(file);
			file.close();
			int a;
			cout << "Диапазон первой группы после: ";
			cin >> a;
			NODE<int>* ptr = q.get_head();
			for (int i = 0; i < a; ++i)
			{
				ptr = ptr->next;
			}
			cout << "до: ";
			cin >> a;
			NODE<int>* ptr2 = q.get_head();
			for (int i = 0; i < a; ++i)
			{
				ptr2 = ptr2->next;
			}
			cout << "Заменить на группу от: ";
			cin >> a;
			NODE<int>* k = q.get_head();
			for (int i = 0; i < a; ++i)
			{
				k = k->next;
			}
			cout << "до: ";
			cin >> a;
			NODE<int>* k2 = q.get_head();
			for (int i = 0; i < a; ++i)
			{
				k2 = k2->next;
			}
			q.group_switch(ptr, ptr2, k, k2);
			q.print();
			break;
		}
		case 4:
		{
			cout << "Найти элемент: ";
			int a;
			cin >> a;
			NODE<int>* ptr = q.get_head();
			if (q.searchS(ptr, a)) cout << "Такой элемент есть.\n";
			else cout << "Такого элемента нет\n";
			break;
		}
		case 5:
		{
			cout << "Найти элементы от: ";
			int a;
			cin >> a;
			NODE<int>* ptr = q.get_head();
			NODE<int>* ptr1 = q.get_head();
			for (int i = 0; i < a; ++i)
			{
				ptr1 = ptr1->next;
			}
			cout << "До: ";
			cin >> a;
			NODE<int>* ptr2 = q.get_head();
			for (int i = 0; i < a; ++i)
			{
				ptr2 = ptr2->next;
			}
			if (q.searchG(ptr, ptr1, ptr2)) cout << "Такие элементы есть.\n";
			else cout << "Таких элементов нет\n";
			cout << "Начало подстроки: " << ptr->info << "\n";
			break;
		}
		}
	} while (choice != 0);
	cin.get();
}