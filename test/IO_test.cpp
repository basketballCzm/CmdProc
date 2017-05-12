#include "IO.h"
#include "gtest/gtest.h"
#include <tbsys.h>

TEST(IOTest,IOTest_atoi_itoa)
{
	TBSYS_LOGGER.setFileName("IOTest.log.txt",false);
	TBSYS_LOGGER.setLogLevel("debug");
	char *pStr = "1234";
	int num = Atoi(pStr);
	EXPECT_EQ(num,1234);

	num = 456789;
	char szBuf[255] = "";
	Itoa(num,szBuf);
	EXPECT_STREQ(szBuf,"456789");
}

TEST(IOTest,IOTest_print)
{
	char szBuf[255] = "123456";
	int num = 78;
	char ch = '9';
	TBSYS_LOG(DEBUG,"szBuf = %x",szBuf);
	print("%s%d%c\n",szBuf,num,ch);

	print_rewrite("%s%d%c\n",szBuf,num,ch);
}

TEST(IOTest,IOTest_scan)
{
	char szBuf[255] = "";
	int num = 0;
	char ch = '\0';

	scan("%s%d%c",szBuf,&num,&ch);

	scan_rewrite("%s%d%c",szBuf,&num,&ch);
}