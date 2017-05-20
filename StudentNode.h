#ifndef __STUDENTNODE_H__
#define __STUDENTNODE_H__
#include "ListProc.h"

struct StudentNode
{
	LINKER m_Linker;

	char m_szName[20];
	char m_szSex[20];
	char m_szId[20];
};

DELCARE_CREATE_NODE(StudentNode)


#endif