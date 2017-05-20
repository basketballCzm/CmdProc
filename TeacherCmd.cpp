#include <stdio.h>
#include "TeacherCmd.h"

BEGIN_ITEM_CMD(Teacher)
ITEM_CMD("Create","Create List",TeacherCreate)
ITEM_CMD("Delete","Delete Node",TeacherDelete)
ITEM_CMD("Add"   ,"Add Node"   ,TeacherAdd)
ITEM_CMD("Modify","Modify Node",TeacherModify)
ITEM_CMD("Find"  ,"Find Node"  ,TeacherFind)
ITEM_CMD("Clear" ,"Clear List" ,TeacherClear)
ITEM_CMD("Save"  ,"Save List"  ,Save)
ITEM_CMD("Load"  ,"Load List"  ,Load)
ITEM_CMD("Help"  ,"Help"       ,Help)
ITEM_CMD("Exit"  ,"Exit"       ,Exit)
END_ITEM_CMD()

bool TeacherCreate()
{
	return true;
}

bool TeacherDelete()
{
	return true;
}

bool TeacherAdd()
{
	return true;
}

bool TeacherFind()
{
	return true;
}

bool TeacherClear()
{
	return true;
}

bool TeacherModify()
{
	return true;
}