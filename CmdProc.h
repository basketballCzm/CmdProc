#ifndef __CMDPROC_H__
#define __CMDPROC_H__
typedef bool (*pfnCmd)();
struct CMD_MAP
{
	const char *pStrCmdName;
	const char *pStrCmdInfo;
	pfnCmd      pfn;
};

extern CMD_MAP *g_EntryCmd;

#define BEGIN_ITEM_CMD(name)    CMD_MAP g_##name##Cmd[] = {

#define ITEM_CMD(name,info,fun) {name,info,fun},

#define END_ITEM_CMD()          {NULL,NULL,NULL}};

#define DECLARE_CMD_MAP(name)   extern CMD_MAP g_##name##Cmd[];

#define GET_CMD_MAP(name)       g_##name##Cmd

bool CmdProc(const char *pStrInfo);

bool Help();
bool Exit();
bool Save();
bool Load();

#endif