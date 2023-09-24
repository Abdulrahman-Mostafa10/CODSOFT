#pragma once
class task_node
{
public:					// A node class capsulate the task's name and state
	string name;
	string state;
	task_node* next;
	task_node* previous;
};
