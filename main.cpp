#include <stdio.h>
#include "CmdProc.h"
#include <tbsys.h>

int main()
{
	TBSYS_LOGGER.setFileName("Czm.log.txt",true);
	TBSYS_LOGGER.setLogLevel("debug");
	CmdProc("welcome to use XXX system!");
	return 0;
}