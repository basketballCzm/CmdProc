#ifndef __STUDENTCMD_H__
#define __STUDENTCMD_H__
#include "CmdProc.h"
DECLARE_CMD_MAP(Student)

bool StudentCreate();
bool StudentDelete();
bool StudentAdd();
bool StudentFind();
bool StudentClear();
bool StudentModify();
bool StudentInsert();
bool StudentShow();

#endif