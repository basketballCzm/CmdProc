#ifndef __TEACHERCMD_H__
#define __TEACHERCMD_H__
#include "CmdProc.h"
DECLARE_CMD_MAP(Teacher)
bool TeacherCreate();
bool TeacherDelete();
bool TeacherAdd();
bool TeacherFind();
bool TeacherClear();
bool TeacherModify();
bool TeacherInsert();
bool TeacherShow();


#endif