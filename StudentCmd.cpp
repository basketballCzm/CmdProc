#include <stdio.h>
#include "StudentCmd.h"

BEGIN_ITEM_CMD(Student)
ITEM_CMD("Create","Create List",StudentCreate)
ITEM_CMD("Delete","Delete Node",StudentDelete)
ITEM_CMD("Add"   ,"Add Node"   ,StudentAdd)
ITEM_CMD("Modify","Modify Node",StudentModify)
ITEM_CMD("Find"  ,"Find Node"  ,StudentFind)
ITEM_CMD("Clear" ,"Clear List" ,StudentClear)
ITEM_CMD("Save"  ,"Save List"  ,Save)
ITEM_CMD("Load"  ,"Load List"  ,Load)
ITEM_CMD("Help"  ,"Help"       ,Help)
ITEM_CMD("Exit"  ,"Exit"       ,Exit)
END_ITEM_CMD()

bool StudentCreate()
{
	return true;
}

bool StudentDelete()
{
	return true;
}

bool StudentAdd()
{
	return true;
}

bool StudentFind()
{
	return true;
}

bool StudentClear()
{
	return true;
}

bool StudentModify()
{
	return true;
}