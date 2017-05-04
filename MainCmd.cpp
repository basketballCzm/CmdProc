#include <stdio.h>
#include "StudentCmd.h"
#include "TeacherCmd.h"
#include "MainCmd.h"

#if defined __GNUC__
#include <stdlib.h>
#define CLEAR "clear"
#elif defined _MSC_VER
#include <windows.h>
#define CLEAR "cls"
#endif



BEGIN_ITEM_CMD(Main)
ITEM_CMD("teacher",  "teacher interface",    Teacher)
ITEM_CMD("student",  "student interface",    Student)
ITEM_CMD("help"   ,  "help    interface",    Help)
ITEM_CMD("exit"   ,  "exit      program",    Exit)
END_ITEM_CMD()

bool Teacher()
{
	g_EntryCmd = GET_CMD_MAP(Teacher);
	system(CLEAR);
	printf("Teacher interface\n");
	Help();
	return true;
}

bool Student()
{
	g_EntryCmd = GET_CMD_MAP(Student);
	system(CLEAR);
	printf("Student interface\n");
	Help();
	return true;
}