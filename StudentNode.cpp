#include "StudentNode.h"
#include "CzmString.h"
#include <stdlib.h>
#include <stdio.h>

void InputStudentNode(LINKER *pNode)
{
	if(NULL != pNode)
	{
		StudentNode *pTemp = (StudentNode*)pNode;
		printf("student name:");
		scanf("%s",pTemp->m_szName);
		printf("student sex:");
		scanf("%s",pTemp->m_szSex);
		printf("student id:");
		scanf("%s",pTemp->m_szId);
	}
}

void OutPutStudentNode(LINKER *pNode)
{
	if(NULL != pNode)
	{
		StudentNode *pTemp = (StudentNode*)pNode;
		printf("student name:%s\nstudent sex:%s\nstudent id:%s\n",pTemp->m_szName,pTemp->m_szSex,pTemp->m_szId);
	}
}

LINKER* FindStudentNode(LINKER *pHead, LINKER **pLast)
{
	if(NULL != pHead)
	{
		char szBuf[255] = "";
		printf("Input the name that you want to find:");
		scanf("%s",szBuf);
		FIND_NODE_BY_NAME(StudentNode,pHead,szBuf,pLast)
	}
}

bool WriteStudentNode(LINKER *pNode)
{
	if(NULL != pNode)
	{
	}
	return true;
}

TYPE GetStudentType()
{
	return student;
}


DEFINE_CREATE_NODE(StudentNode,InputStudentNode,OutPutStudentNode,FindStudentNode,WriteStudentNode,GetStudentType)