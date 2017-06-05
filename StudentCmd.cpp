#include <stdio.h>
#include "ListProc.h"
#include "StudentCmd.h"
#include "StudentNode.h"

BEGIN_ITEM_CMD(Student)
ITEM_CMD("Create","Create List",StudentCreate)
ITEM_CMD("Delete","Delete Node",StudentDelete)
ITEM_CMD("Add"   ,"Add Node"   ,StudentAdd)
ITEM_CMD("Modify","Modify Node",StudentModify)
ITEM_CMD("Find"  ,"Find Node"  ,StudentFind)
ITEM_CMD("Clear" ,"Clear List" ,StudentClear)
ITEM_CMD("Insert","Insert Node",StudentInsert)
ITEM_CMD("Show"  ,"Show Student",StudentShow)
ITEM_CMD("Back"  ,"Back Main"  ,Back)
ITEM_CMD("ShowAll","Show all node",ShowAllNode)
ITEM_CMD("Save"  ,"Save List"  ,Save)
ITEM_CMD("Load"  ,"Load List"  ,Load)
ITEM_CMD("Help"  ,"Help"       ,Help)
ITEM_CMD("Exit"  ,"Exit"       ,Exit)
END_ITEM_CMD()

bool StudentCreate()
{
	CreateList(&g_pHead,CreateStudentNode);
	return true;
}

bool StudentShow()
{
	LINKER *pTemp = g_pHead;
	while(NULL != pTemp)
	{
		if(student == pTemp->GETTYPE())
		{
			pTemp->OUTPUTNODE(pTemp);
		}
		pTemp = pTemp->pNext;
	}
	return true;
}

bool StudentDelete()
{
	//this header is the first one of studentNode
	LINKER *pTemp = g_pHead;
	while(NULL != pTemp)
	{
		if(student == pTemp->GETTYPE())
		{
			DeleteNode(&pTemp);
			break;
		}
		pTemp = pTemp->pNext;
	}
	return true;
}

bool StudentInsert()
{
	//this header is the first one of studentNode
	printf("you want to insert behind or front! 0---front  1---behind:");
	int nflag = 0;
	scanf("%d",&nflag);
	LINKER *pTemp = g_pHead;
	while(NULL != pTemp)
	{
		if(student == pTemp->GETTYPE())
		{
			if(1 == nflag)
			{
				InsertNodeBehind(pTemp,CreateStudentNode);
			}
			else if(0 == nflag)
			{
				//front insert the ListHead == studentHead 
				if(pTemp == g_pHead)
				{
					InsertNodeFront(&pTemp,CreateStudentNode);
				}
				//front insert the ListHead != studentHead 
				else
				{
					//this doesnot change really ListHead
					InsertNodeFront_another(g_pHead,pTemp,CreateStudentNode);
				}
			}
			break;
		}
		pTemp = pTemp->pNext;
	}
	return true;
}


bool StudentAdd()
{
	AddNode(g_pHead,CreateStudentNode);
	return true;
}

bool StudentFind()
{
	LINKER *pTemp = g_pHead;
	LINKER *pLast = NULL;
	while(NULL != pTemp)
	{
		if(student == pTemp->GETTYPE())
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

bool StudentClear()
{
	ClearList(&g_pHead);
	return true;
}

bool StudentModify()
{
	LINKER *pTemp = g_pHead;
	while(NULL != pTemp)
	{
		if(student == pTemp->GETTYPE())
		{
			ModifyNode(pTemp);
			break;
		}
		pTemp = pTemp->pNext;
	}
	return true;
}