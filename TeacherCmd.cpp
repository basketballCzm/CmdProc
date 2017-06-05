#include <stdio.h>
#include "ListProc.h"
#include "TeacherCmd.h"
#include "TeacherNode.h"

BEGIN_ITEM_CMD(Teacher)
ITEM_CMD("Create","Create List",TeacherCreate)
ITEM_CMD("Delete","Delete Node",TeacherDelete)
ITEM_CMD("Add"   ,"Add Node"   ,TeacherAdd)
ITEM_CMD("Modify","Modify Node",TeacherModify)
ITEM_CMD("Find"  ,"Find Node"  ,TeacherFind)
ITEM_CMD("Clear" ,"Clear List" ,TeacherClear)
ITEM_CMD("Insert","Insert Node",TeacherInsert)
ITEM_CMD("Show"  ,"Show Teacher",TeacherShow)
ITEM_CMD("Save"  ,"Save List"  ,Save)
ITEM_CMD("Load"  ,"Load List"  ,Load)
ITEM_CMD("Help"  ,"Help"       ,Help)
ITEM_CMD("Exit"  ,"Exit"       ,Exit)
ITEM_CMD("Back"  ,"Back Main"  ,Back)
ITEM_CMD("ShowAll","Show all node",ShowAllNode)
END_ITEM_CMD()

bool TeacherCreate()
{
	CreateList(&g_pHead,CreateTeacherNode);
	return true;
}

bool TeacherShow()
{
	LINKER *pTemp = g_pHead;
	while(NULL != pTemp)
	{
		if(teacher == pTemp->GETTYPE())
		{
			pTemp->OUTPUTNODE(pTemp);
		}
		pTemp = pTemp->pNext;
	}
	return true;
}

bool TeacherDelete()
{
	//this header is the first one of TeacherNode
	LINKER *pTemp = g_pHead;
	while(NULL != pTemp)
	{
		if(teacher == pTemp->GETTYPE())
		{
			DeleteNode(&pTemp);
			break;
		}
		pTemp = pTemp->pNext;
	}
	return true;
}

bool TeacherInsert()
{
	//this header is the first one of TeacherNode
	printf("you want to insert behind or front! 0---front  1---behind:");
	int nflag = 0;
	scanf("%d",&nflag);
	LINKER *pTemp = g_pHead;
	while(NULL != pTemp)
	{
		if(teacher == pTemp->GETTYPE())
		{
			if(1 == nflag)
			{
				InsertNodeBehind(pTemp,CreateTeacherNode);
			}
			else if(0 == nflag)
			{
				//front insert the ListHead == TeacherHead 
				if(pTemp == g_pHead)
				{
					TBSYS_LOG(DEBUG,"1.g_pHead = 0x%x" , g_pHead);
					//这里不能取pTemp的地址进行参数传进去,pTemp是一个局部变量,要取&g_pHead
					InsertNodeFront(&g_pHead,CreateTeacherNode);
					TBSYS_LOG(DEBUG,"2.g_pHead = 0x%x" , g_pHead);
				}
				//front insert the ListHead != TeacherHead 
				else
				{
					//this doesnot change really ListHead
					InsertNodeFront_another(g_pHead,pTemp,CreateTeacherNode);
				}
			}
			break;
		}
		pTemp = pTemp->pNext;
	}
	return true;
}


bool TeacherAdd()
{
	AddNode(g_pHead,CreateTeacherNode);
	return true;
}

bool TeacherFind()
{
	LINKER *pTemp = g_pHead;
	LINKER *pLast = NULL;
	while(NULL != pTemp)
	{
		if(teacher == pTemp->GETTYPE())
		{
			pTemp = ListFindNode(pTemp,&pLast);
			break;
		}
		pTemp = pTemp->pNext;
	}
	if(NULL != pTemp)
	{
		pTemp->OUTPUTNODE(pTemp);
	}
	return true;
}

bool TeacherClear()
{
	ClearList(&g_pHead);
	return true;
}

bool TeacherModify()
{
	LINKER *pTemp = g_pHead;
	while(NULL != pTemp)
	{
		if(teacher == pTemp->GETTYPE())
		{
			ModifyNode(pTemp);
			break;
		}
		pTemp = pTemp->pNext;
	}
	return true;
}