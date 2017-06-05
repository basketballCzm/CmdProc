#ifndef __LIST_H__
#define __LIST_H__
#include <stdio.h>
#include <stdlib.h>
#include <tbsys.h>
enum TYPE {student,teacher};
struct LINKER;
struct PFUN
{
	void (*pfnInputNode)(LINKER *pNode);
	void (*pfnOutputNode)(LINKER *pNode);
	//I have add pfnGetName. it is no important to do.
	LINKER* (*pfnFindNode)(LINKER *pHead, LINKER **pLast);   //if you want to change a pointer`s in function. you have to use two level pointer.
	bool (*pfnWriteNode)(LINKER *pNode);
	char* (*pfnGetName)(LINKER *pNode);
	TYPE (*pfnGetType)();
};

struct LINKER
{
	LINKER *pNext;
	PFUN   *pfn;
};

#define INPUTNODE   pfn->pfnInputNode
#define OUTPUTNODE  pfn->pfnOutputNode
#define FINDNODE    pfn->pfnFindNode
#define WRITENODE   pfn->pfnWriteNode
#define GETTYPE     pfn->pfnGetType
#define GETNAME     pfn->pfnGetName

typedef LINKER* (*PCREATE)();
bool CreateList(LINKER **pHead, PCREATE pfn);
bool AddNode(LINKER *pHead, PCREATE pfn);
bool DeleteNode(LINKER **pHead);
LINKER* ListFindNode(LINKER *pHead, LINKER **pLast);
bool ModifyNode(LINKER *pHead);
bool InsertNodeBehind(LINKER *pHead, PCREATE pfn);
bool InsertNodeFront(LINKER **pHead, PCREATE pfn);
bool InsertNodeFront_another(LINKER *pListHead, LINKER *pHead, PCREATE pfn);
bool ClearList(LINKER **pHead);
bool ShowList(LINKER *pHead);

#define DELCARE_CREATE_NODE(name) LINKER* Create##name();

#define DEFINE_CREATE_NODE(name,Input,Output,Find,Write,GetName,GetType) \
LINKER* Create##name() \
{ \
	static PFUN g_##name##Fun = {Input,Output,Find,Write,GetName,GetType}; \
	LINKER *pNew = (LINKER*)malloc(sizeof(name)); \
	if(NULL != pNew) \
	{ \
		pNew->pfn = &g_##name##Fun; \
		pNew->pNext = NULL; \
	} \
	return pNew; \
}

#define FIND_NODE_BY_NAME(type,pHead, Name, pLast) \
LINKER *pTemp = (LINKER*)pHead; \
while(NULL != pTemp) \
{ \
	TBSYS_LOG(DEBUG,"Start find node by name"); \
	if(type == pTemp->GETTYPE() && Strcmp(pTemp->GETNAME(pTemp),Name)) \
	{ \
		TBSYS_LOG(DEBUG,"find node success!"); \
		break; \
	} \
	*pLast = pTemp; \
	pTemp = pTemp->pNext; \
} \
if(NULL == pTemp) \
{ \
	printf("%s","no find this node!\n"); \
} \
return pTemp;


extern LINKER *g_pHead;


#endif