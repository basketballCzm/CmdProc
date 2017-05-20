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
    //TBSYS_LOG(DEBUG,"pFormat+8 = %x",(pFormat+8))
    while('\0' != *pFormat)
    {
        if('%' == *pFormat)
        {
            pFormat++;
            pTemp++;
            TBSYS_LOG(DEBUG,"pTemp = %x",pTemp);
            TBSYS_LOG(DEBUG,"*pTemp = %x",*pTemp);
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



int vsprintf(char *buf, const char *fmt, va_list args)
{
    int len;
    int i;
    char * str;
    char *s;
    int *ip;
 
    int flags;        /* flags to number() */
     
        int field_width;    /* width of output field */
        int precision;        /* min. # of digits for integers; max
                       number of chars for from string */
        int qualifier;        /* 'h', 'l', or 'L' for integer fields */
     
        for (str=buf ; *fmt ; ++fmt) {    //str为最终存放字符串的位置但是他随着字符串增长而增长，buf始终指向最终字符串的启始位置。fmt为格式字符串
            if (*fmt != '%') {                        
                *str++ = *fmt;              //如果不是%则表示这是需要原样打印的字符串，直接复制即可
                continue;
            }
               
            /* process flags */
            flags = ;
            repeat:
                ++fmt;        /* this also skips first '%' */                            //fmt指向%的后一位
                switch (*fmt) {
                    case '-': flags |= LEFT; goto repeat;
                    case '+': flags |= PLUS; goto repeat;
                    case ' ': flags |= SPACE; goto repeat;                         //判断标志位，并设置flags
                    case '#': flags |= SPECIAL; goto repeat;
                    case '': flags |= ZEROPAD; goto repeat;
                    }
           
            /* get field width */
            field_width = -1;
            if (is_digit(*fmt))
                field_width = skip_atoi(&fmt);
            else if (*fmt == '*') {
                /* it's the next argument */
                field_width = va_arg(args, int);
                if (field_width < ) {
                    field_width = -field_width;
                    flags |= LEFT;
                }
            }
     
            /* get the precision */
            precision = -1;
            if (*fmt == '.') {
                ++fmt;   
                if (is_digit(*fmt))
                    precision = skip_atoi(&fmt);
                else if (*fmt == '*') {
                    /* it's the next argument */
                    precision = va_arg(args, int);
                }
                if (precision < )
                    precision = ;
            }
     
            /* get the conversion qualifier */
            qualifier = -1;
            if (*fmt == 'h' || *fmt == 'l' || *fmt == 'L') {
                qualifier = *fmt;
                ++fmt;
            }
     
            switch (*fmt) {                                  //如果没有上面奇怪的标志位(*/./h/l/L)则fmt仍然指向%的后一位，下面判断这个标志位
            case 'c':
                if (!(flags & LEFT))
                    while (--field_width > )
                        *str++ = ' ';
                *str++ = (unsigned char) va_arg(args, int);
                while (--field_width > )
                    *str++ = ' ';
                break;
     
            case 's':
                s = va_arg(args, char *);
                len = strlen(s);
                if (precision < )
                    precision = len;
                else if (len > precision)
                    len = precision;
     
                if (!(flags & LEFT))
                    while (len < field_width--)
                        *str++ = ' ';
                for (i = ; i < len; ++i)
                    *str++ = *s++;
                while (len < field_width--)
                    *str++ = ' ';
                break;
     
            case 'o':
                str = number(str, va_arg(args, unsigned long), 8,
                    field_width, precision, flags);
                break;
     
            case 'p':
                if (field_width == -1) {
                    field_width = 8;
                    flags |= ZEROPAD;
                }
                str = number(str,
                    (unsigned long) va_arg(args, void *), 16,
                    field_width, precision, flags);
                break;
     
            case 'x':
                flags |= SMALL;
            case 'X':
                str = number(str, va_arg(args, unsigned long), 16,
                    field_width, precision, flags);
                break;
     
    

    case 'd':                                    //如果是整型，首先设定flags，然后利用number函数将可变参数取出，并根据base(这里是10)然后转换成字符串，赋给str
            case 'i':
                flags |= SIGN;
            case 'u':
                str = number(str, va_arg(args, unsigned long), 10,
                    field_width, precision, flags);
                break;
     
            case 'n':
                ip = va_arg(args, int *);
                *ip = (str - buf);
                break;
     
            default:
                if (*fmt != '%')//如果格式转换符不是%，则表示出错，直接打印一个%。如果是%，那么格式转换符就是%%，就由下面if(*fmt)只输出一个%
                    *str++ = '%';
                if (*fmt)
                    *str++ = *fmt;//如果格式转换符不正确则输出%+不正确的格式转换符。如果是%%，则只输出一个%
                else
                    --fmt;//如果转换格式符不是上面这些正确的，也不是空，那么直接输出，并返回到判断fmt的for语句；否则就指向末尾了，fmt后退一位，这样在for循环自动再加1进行判断时*fmt的条件就不满足，退出for循环
                break;
            }
        }
        *str = '\0';//设定str字符串的最后一位为'\0'
        return str-buf;//返回值为字符串的长度