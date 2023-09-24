#include<Windows.h>
#include<iostream>
#include<string>
using namespace std;
#define endl '\n'
void Bedo()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
}

class task_node
{
public:					// A node class capsulate the task's name and state
	string name;
	string state;
	task_node* next;
	task_node* previous;
};

class To_Do_List
{
private:
	task_node* head;
	task_node* tail;

public:
	To_Do_List();
	To_Do_List(string);
	bool add_task(string);
	bool mark(string);
	bool remove_task(string);
	void show_tasks() const;
};
To_Do_List::To_Do_List()
{
	Bedo();
	head = tail = nullptr;
}
To_Do_List::To_Do_List(string passed_name)
{
	Bedo();
	head = tail = nullptr;
	add_task(passed_name);
}
bool To_Do_List::add_task(string passed_name)
{
	task_node* new_task = new task_node;
	new_task->name = passed_name;
	new_task->state = "Pending_Task";
	new_task->next = nullptr;
	if (!head)
	{
		new_task->previous = nullptr;
		head = new_task;
	}
	else
	{
		task_node* ptr_for_last_task = head;
		while (ptr_for_last_task->next != nullptr)
			ptr_for_last_task = ptr_for_last_task->next;

		ptr_for_last_task->next = new_task;
		new_task->previous = ptr_for_last_task;
		tail = new_task;
	}
	return true;
}
bool To_Do_List::mark(string passed_name)
{
	task_node* new_task = new task_node;
	new_task = head;
	if (!new_task)
		return false;
	else
	{
		while (new_task)
		{
			if (new_task->name == passed_name)
			{
				new_task->state = "Completed_Task";
				return true;
			}
			new_task = new_task->next;
		}
		return false;
	}
}
bool To_Do_List::remove_task(string passed_name)
{
	task_node* ptr = new task_node;
	ptr = head;
	if (!ptr)
		return false;
	else
	{
		while (ptr && ptr != tail)
		{
			if (ptr->name == passed_name)
			{
				ptr->next->previous = ptr->previous;
				ptr->previous->next = ptr->next;
				ptr->next = ptr->previous = nullptr;
				delete ptr;
				return true;
			}
			ptr = ptr->next;
		}
		if (ptr == tail)
		{
			tail = tail->previous;
			tail->next = nullptr;
			ptr->next = ptr->previous = nullptr;
			delete ptr;
			return true;
		}
		return false;
	}
}

void To_Do_List::show_tasks() const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalAttributes = consoleInfo.wAttributes;
	task_node* ptr = new task_node;
	ptr = head;
	if (!ptr)
		cout << "Empty To-Do List ..." << endl;
	else
	{
		int i = 1;
		while (ptr)
		{
			cout << "Task - " << i++ << " :" << endl;
			cout << "----------" << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "Name : " << ptr->name << endl;
			SetConsoleTextAttribute(hConsole, originalAttributes);
			if (ptr->state == "Pending_Task")
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
			else
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "Name : " << ptr->state << endl;
			SetConsoleTextAttribute(hConsole, originalAttributes);
			cout << "-------------------" << endl;
			ptr = ptr->next;
		}
	}
}
int main()
{
	To_Do_List list("Work");
	list.add_task("Study");
	list.add_task("Training");
	list.add_task("Gym");
	list.remove_task("Gym");
	list.mark("Training");
	list.add_task("parents'visit");
	list.add_task("doing laundary");
	list.remove_task("Training");
	list.mark("Work");
	list.show_tasks();
	system("pause");
}
