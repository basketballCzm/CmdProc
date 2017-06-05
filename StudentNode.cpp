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
	if(NULL != pHead && NULL != pLast)
	{
		char szBuf[255] = "";
		printf("Input the name that you want to find:");
		scanf("%s",szBuf);
		//if donot use GETNAME . in this hong change type will make trouble.because you should change every node for this list 
		FIND_NODE_BY_NAME(student,pHead,szBuf,pLast)
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

char* GetStudentNodeName(LINKER *pNode)
{
	return ((StudentNode*)pNode)->m_szName;
}


DEFINE_CREATE_NODE(StudentNode,InputStudentNode,OutPutStudentNode,FindStudentNode,WriteStudentNode,GetStudentNodeName,GetStudentType)