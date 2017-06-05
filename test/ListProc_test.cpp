#include "gtest/gtest.h"
#include "TeacherCmd.h"
#include "StudentCmd.h"
#include "TeacherNode.h"
#include "StudentNode.h"
#include <tbsys.h>

TEST(CzmListTest,CzmListTest)
{
	TBSYS_LOGGER.setFileName("CzmListTest.log.txt",true);
	TBSYS_LOGGER.setLogLevel("debug");
	printf("***********CreateList**************\n");
	CreateList(&g_pHead,CreateStudentNode);

	printf("***********AddNode**************\n");
	AddNode(g_pHead,CreateStudentNode);
	ShowList(g_pHead);


	printf("***********ModifyNode**************\n");
	ModifyNode(g_pHead);

	printf("***********ListFindNode**************\n");
	LINKER *pLast = NULL;
	LINKER *pTemp = ListFindNode(g_pHead,&pLast);
	if(NULL != pTemp)
	{
		pTemp->OUTPUTNODE(pTemp);
	}
	else
	{
		printf("%s","no find this node!\n");
	}
	ShowList(g_pHead);


	printf("***********InsertNodeBehind**************\n");
	//insert head behind 
	printf("*******insert head behind**********\n");
	InsertNodeBehind(g_pHead,CreateStudentNode);
	ShowList(g_pHead);

	//insert end behind
	printf("*******insert end behind**********\n");
	InsertNodeBehind(g_pHead,CreateStudentNode);
	ShowList(g_pHead);

	//insert intermediate behind
	printf("*******insert intermediate behind**********\n");
	InsertNodeBehind(g_pHead,CreateStudentNode);
	ShowList(g_pHead);

	printf("***********DeleteNode**************\n");
	//delete head
	printf("*******delete head**********\n");
	DeleteNode(&g_pHead);
	ShowList(g_pHead);

	//delete end
	printf("*******delete end**********\n");
	DeleteNode(&g_pHead);
	ShowList(g_pHead);

	//delete intermediate
	printf("*******delete intermediate**********\n");
	DeleteNode(&g_pHead);
	ShowList(g_pHead);

	printf("***********InsertNodeFront**************\n");
	//insert head behind 
	printf("*******insert head Front **********\n");
	InsertNodeFront(&g_pHead,CreateStudentNode);
	ShowList(g_pHead);

	//insert end behind
	printf("*******insert end Front**********\n");
	InsertNodeFront(&g_pHead,CreateStudentNode);
	ShowList(g_pHead);

	//insert intermediate behind
	printf("******insert intermediate Front**********\n");
	InsertNodeFront(&g_pHead,CreateStudentNode);
	ShowList(g_pHead);

	printf("***********ClearList**************\n");
	if(ClearList(&g_pHead))
	{
		printf("%s\n","clear List success!");
	}

}