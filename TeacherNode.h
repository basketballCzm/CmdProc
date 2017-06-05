#ifndef __TEACHERNODE_H__
#define __TEACHERNODE_H__
#include "ListProc.h"
struct TeacherNode
{
	LINKER m_Linker;

	TYPE m_type;
	char m_szName[255];         //mark. I do it that in order to make program be strong 
	char m_szSex[20];
};

DELCARE_CREATE_NODE(TeacherNode)

#endif