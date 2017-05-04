#include "CzmString.h"
#include <tblog.h>
#define NULL 0
int Strlen(const char *pStr)
{
	int nSize = 0;
	if(NULL != pStr)
	{
		 while('\0' != *pStr)
		 {
		 	pStr++;
		 	nSize++;
		 }
	}
	return nSize;
}

bool Strcmp(const char *pDest, const char *pSrc)
{
	if(NULL == pDest || NULL == pSrc)
	{
		return false;
	}
	int i = 0;
	//this should add '\0' != pSrc[i]
	for(i = 0; pSrc[i] == pDest[i] && '\0' != pSrc[i]; i++);
	if(pSrc[i]==pDest[i] && '\0' == pSrc[i])
	{
		return true;
	}
	return false;
}

bool Strcat(char *pDest, const char *pSrc)
{
	if(NULL == pDest || NULL == pSrc)
	{
		return false;
	}
	//this is cool
	//for(int i = 0; '\0' != pDest[i]; i++);
	//error while('\0' != *pDest++);pDest--;
	while('\0' != *pDest)
	{
		pDest++;
	}
	for(int i = 0; (pDest[i] = pSrc[i]) != '\0'; i++);
	return true;
}

bool Strcpy(char *pDest, const char *pSrc)
{
	if(NULL == pDest || NULL == pSrc)
	{
		return false;
	}
	for(int i = 0; (pDest[i] = pSrc[i]) != '\0'; i++);
	return true;
}