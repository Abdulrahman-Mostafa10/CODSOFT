#include"To-Do-List.h"
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
