#include "TeacherNode.h"
#include "CzmString.h"
#include <stdlib.h>
#include <stdio.h>

void InputTeacherNode(LINKER *pNode)
{
	if(NULL != pNode)
	{
		TeacherNode *pTemp = (TeacherNode*)pNode;
		printf("teacher name:");
		scanf("%s",pTemp->m_szName);
		printf("teacher sex:");
		scanf("%s",pTemp->m_szSex);
	}
}

void OutPutTeacherNode(LINKER *pNode)
{
	if(NULL != pNode)
	{
		TeacherNode *pTemp = (TeacherNode*)pNode;
		printf("teacher name:%s\nteacher sex:%s\n",pTemp->m_szName,pTemp->m_szSex);
	}
}


LINKER* FindTeacherNode(LINKER *pHead, LINKER **pLast)
{
	if(NULL != pHead && NULL != pLast)
	{
		char szBuf[255] = "";
		printf("Input the name that you want to find:");
		scanf("%s",szBuf);
		FIND_NODE_BY_NAME(teacher,pHead,szBuf,pLast)
	}
}


bool WriteTeacherNode(LINKER *pNode)
{
	if(NULL != pNode)
	{
	}
	return true;
}

TYPE GetTeacherType()
{
	return teacher;
}

char* GetTeacherNodeName(LINKER *pNode)
{
	return ((TeacherNode*)pNode)->m_szName;
}


DEFINE_CREATE_NODE(TeacherNode,InputTeacherNode,OutPutTeacherNode,FindTeacherNode,WriteTeacherNode,GetTeacherNodeName,GetTeacherType)
