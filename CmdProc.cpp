#include "CzmString.h"
#include <stdio.h>
#include <tblog.h>
#include "CmdProc.h"
#include "MainCmd.h"
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
//mark，before you write Makefile you should pay attention to the GET_CMD_MAP(Main) object should have been define
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
bool Exit()
{
	printf("the program will exit within one second!\n");
	Sleep(1000);
	exit(0);
	return true;
}

bool Save()
{
	return true;
}

bool Load()
{
	return true;
}


