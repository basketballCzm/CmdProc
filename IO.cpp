#include "IO.h"
#include "CzmString.h"
#include <tblog.h>
#include <stdio.h>
int Atoi(const char *pStr)
{
    int nNum = 0;
    if(NULL != pStr)
    {
        int nSize = Strlen(pStr);
        int ntmp = 1;
        //this is a debug ,i = nSize-1; pay attention to the array labels
        for(int i = nSize-1; i >= 0; i--)
        {
            TBSYS_LOG(DEBUG,"ntmp = %d, nSize = %d, nNum = %d",ntmp,nSize,nNum);
            //this is a debug priority += > *,so it is necessary to add ()
            nNum += (ntmp*(pStr[i] - '0'));
            ntmp *= 10;
        }
    }
    return nNum;
}

void Itoa(int num,char *pStr)
{
    if(NULL == pStr)
    {
        return;
    }
    int ntmp = num;
    int nSize = 0;
    while(0 != ntmp/10)
    {
        nSize++;
        ntmp /= 10;
    }
    nSize++;

    ntmp = num;
    //this is a debug too
    for(int i = nSize-1; i >= 0; i--)
    {
        pStr[i] = ntmp%10 + '0';
        TBSYS_LOG(DEBUG,"nSize = %d, pStr[i] = %c",nSize,pStr[i]);
        ntmp /= 10;
    }
    pStr[nSize] = '\0';
}

void Input_char(char *pStr)
{
	if(NULL == pStr)
	{
		return;
	}
    int i = 0;
	for(i = 0; '\n' != (pStr[i] = getchar()) && ' ' != pStr[i]; i++);
	pStr[i] = '\0';
}

//this is a printf written with two level pointer,one level pointer is right too.
void print(const char *pFormat,...)
{
	if(NULL == pFormat)
	{
		return;
	}
    TBSYS_LOG(DEBUG,"entry print");
	//this should have a forced conversion(char **)
    char **pTemp = (char **)&pFormat;
    TBSYS_LOG(DEBUG,"pFormat = %s,%x",pFormat,pFormat);
    TBSYS_LOG(DEBUG,"pTemp = %x",pTemp);
    TBSYS_LOG(DEBUG,"*pTemp = %x",*pTemp);
    while('\0' != *pFormat)
    {
        if('%' == *pFormat)
        {
            pFormat++;
            pTemp++;
            TBSYS_LOG(DEBUG,"pTemp = %x",pTemp);
            TBSYS_LOG(DEBUG,"*pTemp = %x",*(pTemp+1));
            switch(*pFormat)
            {
            case 'd':
            case 'D':
            {
                int ntmp = *((int*)pTemp);
                TBSYS_LOG(DEBUG,"this is d! %d",&ntmp);
                char szBuf[255] = "";
                Itoa(ntmp,szBuf);
                for(int i = 0; '\0' != szBuf[i]; i++)
                {
                    putchar(szBuf[i]);
                }
                break;
            }
            case 's':
            case 'S':
            {
                char *pStr = *pTemp;
                TBSYS_LOG(DEBUG,"this is s! %s pStr = %x",pStr,pStr);
                for(int i = 0; '\0' != pStr[i]; i++)
                {
                    putchar(pStr[i]);
                }
                break;
            }
            case 'c':
            case 'C':
            {
                char ch = *((char*)pTemp);
                TBSYS_LOG(DEBUG,"this is c! %c",&ch);
                putchar(ch);
                break;
            }
            default:
            {
                break;
            }
            }
        }
        else
        {
            putchar(*pFormat);
        }
        pFormat++;
    }
}

void print_rewrite(const char *pFormat,...)
{
	if(NULL == pFormat)
	{
		return;
	}

    char *pTemp = (char *)&pFormat;
    while('\0' != *pFormat)
    {
        if('%' == *pFormat)
        {
            pTemp += 4;
            pFormat++;
            switch(*pFormat)
            {
            case 'd':
            case 'D':
            {
            	int nSize = *((int*)pTemp);
            	char szBuf[255] = "";
            	Itoa(nSize,szBuf);
            	for(int i = 0; '\0' != szBuf[i]; i++)
            	{
            		putchar(szBuf[i]);
            	}
                break;
            }
            case 's':
            case 'S':
            {
            	char *pStr = *((char **)pTemp);
            	for(int i = 0; '\0' != pStr[i]; i++)
            	{
            		putchar(pStr[i]);
            	}
                break;
            }
            case 'c':
            case 'C':
            {
            	putchar(*pTemp);
                break;
            }
            default:
            {
                break;
            }
            }
        }
        else
        {
        	putchar(*pFormat);
        }
        pFormat++;
    }
}

void scan(const char *pFormat,...)
{
	if(NULL == pFormat)
	{
		return ;
	}

	char **pTemp = (char **)&pFormat;
	while('\0' != *pFormat)
	{
		if('%' == *pFormat)
		{
			pTemp++;
			pFormat++;
			char *pStr = *pTemp;
			switch(*pFormat)
			{
				case 'd':
				case 'D':
				{
					Input_char(pStr);
					*((int*)pStr) = Atoi(pStr);
					break;
				}
				case 's':
				case 'S':
				{
					Input_char(pStr);
					break;
				}
				case 'c':
				case 'C':
				{
					*pStr = getchar();
					break;
				}
				default:
				{
					break;
				}
			}
		}
		pFormat++;
	}
}

void scan_rewrite(const char *pFormat,...)
{
	if(NULL == pFormat)
	{
		return ;
	}

	char *pTemp = (char *)&pFormat;
	while('\0' != *pFormat)
	{
		if('%' == *pFormat)
		{
			pTemp += 4;
			pFormat++;
			char *pStr = *((char**)pTemp);
			switch(*pFormat)
			{
				case 'd':
				case 'D':
				{
					Input_char(pStr);
					*((int*)pStr) = Atoi(pStr);
					break;
				}
				case 's':
				case 'S':
				{
					Input_char(pStr);
					break;
				}
				case 'c':
				case 'C':
				{
					*pStr = getchar();
					break;
				}
				default:
				{
					break;
				}
			}
		}
		pFormat++;
	}
}