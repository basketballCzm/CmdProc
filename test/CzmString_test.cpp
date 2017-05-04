#include "CzmString.h"
#include "gtest/gtest.h"
#include <tbsys.h>


TEST(CzmStringTest,CzmStringTest_Strlen)
{
	//right
	TBSYS_LOGGER.setFileName("CzmStringTest.log.txt",true);
	TBSYS_LOGGER.setLogLevel("debug");
	char *pStr = "1234567";
	int nSize = Strlen(pStr);
	EXPECT_EQ(nSize,7);

	//null
	char *pStr_null = NULL;
	nSize = Strlen(pStr_null);
	EXPECT_EQ(nSize,0);
}

TEST(CzmStringTest,CzmStringTest_Strcpy)
{
	//right
	char *pStr = "1234567";
	char szBuf[255] = " ";
	bool flag = Strcpy(szBuf,pStr);
	EXPECT_EQ(flag,true);
	EXPECT_STREQ(szBuf,"1234567");

	//null
	char *pStr_null = NULL;
	flag = Strcpy(szBuf,pStr_null);
	EXPECT_EQ(flag,false);
	EXPECT_STREQ(szBuf,"1234567");
}

TEST(CzmStringTest,CzmStringTest_Strcat)
{
	//right
	char *pStr = "5678";
	char szBuf[255] = "1234";
	bool flag = Strcat(szBuf,pStr);
	EXPECT_STREQ(szBuf,"12345678");
	EXPECT_EQ(flag,true);

	//null
	char *pStr_null = NULL;
	flag = Strcat(szBuf,pStr_null);
	EXPECT_STREQ(szBuf,"12345678");
	EXPECT_EQ(flag,false);
}

TEST(CzmStringTest,CzmStringTest_Strcmp)
{
	char *pStr = "123456";
	char *pStr1 = "123456";
	bool flag = Strcmp(pStr,pStr1);
	EXPECT_EQ(flag,true);

	char *pStr2 = "12345";
	flag = Strcmp(pStr,pStr2);
	EXPECT_EQ(flag,false);
}