#include "CzmString.h"
#include <stdio.h>
#include <tblog.h>
#include "CmdProc.h"
#include "MainCmd.h"
#include "ListProc.h"
#include "StudentNode.h"
#include "TeacherNode.h"
#define N 7
//this is a across-perform exercise
/* Windows: WIN32
   LINUX:   linux
   Solaris: __sun

   VC:      _MSC_VER
   GCC/G++  __GNUC__
   SunCC    __SUNPRO_C  __SUNPRO_CC
*/
#if defined __GNUC__
#include <unistd.h>
#define Sleep(x) usleep(x##000)
#elif defined _MSC_VER
#include <windows.h>
#endif

#if defined __GNUC__
#include <stdlib.h>
#define CLEAR "clear"
#elif defined _MSC_VER
#include <windows.h>
#define CLEAR "cls"
#endif

//mark，before you write Makefile you should pay attention to the GET_CMD_MAP(Main) object should have been define
//在编写Makefile.am的过程中.cpp的文件放置的顺序是要按照一定的规则进行排列
CMD_MAP *g_EntryCmd = GET_CMD_MAP(Main);

bool CmdProc(const char *pStrInfo)
{
	if(NULL == pStrInfo)
	{
		return false;
	}
	else
	{
		printf("%s\n",pStrInfo);
	}

	Help();
	char szBuf_Input[255] = " ";
	CMD_MAP *pTemp = NULL;
	while(true)
	{
		scanf("%s",szBuf_Input);
		pTemp = g_EntryCmd;
		while(NULL != pTemp->pStrCmdName)
		{
			if(Strcmp(szBuf_Input,pTemp->pStrCmdName))
			{
				pTemp->pfn();
				break;
			}
			pTemp++;
		}
		if(NULL == pTemp->pStrCmdName)
		{
			printf("the input command is wrong!\n");
		}
	}

	return true;
}

bool Help()
{
	printf("command   description         \n");
	CMD_MAP *pTemp = g_EntryCmd;
	int nSize = 0;
	while(NULL != pTemp->pStrCmdName)
	{
		nSize = Strlen(pTemp->pStrCmdName);
		printf("%s",pTemp->pStrCmdName);
		for(int i = nSize; i < N; i++)
		{
			printf(" ");
		}
		printf("   ");                                  //if these commmand is not aligned, you can adjust these spaces
		printf("%s\n",pTemp->pStrCmdInfo);
		pTemp++;
	}
	return true;
}

bool Back()
{
	g_EntryCmd = GET_CMD_MAP(Main);
	system(CLEAR);
	printf("Main interface\n");
	Help();
	return true;
}

bool ShowAllNode()
{
	if(NULL != g_pHead)
	{
		ShowList(g_pHead);
	}
	return true;
}

bool Exit()
{
	printf("the program will exit within one second!\n");
	ClearList(&g_pHead);
	Sleep(1000);
	exit(0);
	return true;
}

bool Save()
{
	int nfile = open("DataBase.txt",O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IXUSR);
	if(-1 == nfile)
	{
		printf("%s\n","open file fail!");
		return false;
	}

	LINKER *pTemp = g_pHead;
	while(NULL != pTemp)
	{
		if(!pTemp->WRITENODE(nfile,pTemp))
		{
			return false;
		}
		pTemp = pTemp->pNext;
	}
	close(nfile);
	printf("%s\n","Save data success!");
	return true;
}

bool Load()
{
	if(NULL != g_pHead)
	{
		printf("%s\n","List have existed!");
		return false;
	}

	int nfile = open("DataBase.txt",O_RDONLY);
	if(-1 == nfile)
	{
		printf("%s\n","open file fail!");
		return false;
	}
	char szBuf[512] = "";
	LINKER *pTempOut = g_pHead;
	while(read(nfile,szBuf,sizeof(LINKER)))
	{
		LINKER *pTemp = (LINKER*)szBuf;
		if(student == pTemp->GETTYPE())
		{
			TBSYS_LOG(DEBUG,"load student node!");
			if(0 == read(nfile,szBuf+sizeof(LINKER),sizeof(StudentNode)-sizeof(LINKER)))
			{
				printf("%s\n","read file fail!");
		        return false;
			}
			StudentNode *pStudent = (StudentNode*)szBuf;
			StudentNode *pNew = (StudentNode*)CreateStudentNode();
			if(NULL == pNew)
			{
				printf("%s\n","Load malloc fail!");
				return false;
			}
			if(NULL == g_pHead)
			{
				g_pHead = &(pNew->m_Linker);
				pTempOut = &(pNew->m_Linker);
			}
			pTempOut->pNext = &(pNew->m_Linker);
			memcpy((char*)pNew+sizeof(LINKER),(char*)pStudent+sizeof(LINKER),sizeof(StudentNode)-sizeof(LINKER));
		}
		else if(teacher == pTemp->GETTYPE())
		{
			TBSYS_LOG(DEBUG,"load teacher node!");
			if(0 == read(nfile,szBuf+sizeof(LINKER),sizeof(TeacherNode)-sizeof(LINKER)))
			{
				printf("%s\n","read file fail!");
		        return false;
			};
			TeacherNode *pTeacher = (TeacherNode*)szBuf;
			TeacherNode *pNew = (TeacherNode*)CreateTeacherNode();
			if(NULL == pNew)
			{
				printf("%s\n","Load malloc fail!");
				return false;
			}
			if(NULL == g_pHead)
			{
				g_pHead = &(pNew->m_Linker);
				pTempOut = &(pNew->m_Linker);
			}
			pTempOut->pNext = &(pNew->m_Linker);
			memcpy((char*)pNew+sizeof(LINKER),(char*)pTeacher+sizeof(LINKER),sizeof(TeacherNode)-sizeof(LINKER));
			TBSYS_LOG(DEBUG,"load teacher node!3");
		}
		memset(szBuf,0,sizeof(szBuf));
	}

	return true;
}

	TYPE m_type;
	char m_szName[20];
	char m_szSex[20];
	char m_szId[20];
