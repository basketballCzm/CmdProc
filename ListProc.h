#ifndef __LIST_H__
#define __LIST_H__
enum TYPE {student,teacher};
struct LINKER;
struct PFUN
{
	void (*pfnInputNode)(LINKER *pNode);
	void (*pfnOutputNode)(LINKER *pNode);
	LINKER* (*pfnFindNode)(LINKER *pHead, LINKER **pLast);   //if you want to change a pointer`s in function. you have to use two level pointer.
	bool (*pfnWriteNode)(LINKER *pNode);
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

typedef LINKER* (*PCREATE)();
bool CreateList(LINKER **pHead, PCREATE pfn);
bool AddNode(LINKER *pHead, PCREATE pfn);
bool DeleteNode(LINKER **pHead);
//LINKER* FindNode(LINKER *pHead, LINKER **pLast);
bool ModifyNode(LINKER *pHead);
bool InsertNodeBehind(LINKER *pHead, PCREATE pfn);
bool InsertNodeFront(LINKER **pHead, PCREATE pfn);
bool ClearList(LINKER **pHead);

#define DELCARE_CREATE_NODE(name) LINKER* Create##name();

#define DEFINE_CREATE_NODE(name,Input,Output,Find,Write,GetType) \
LINKER* Create##name() \
{ \
	static PFUN g_##name##Fun = {Input,Output,Find,Write,GetType}; \
	LINKER *pNew = (LINKER*)malloc(sizeof(name)); \
	if(NULL != pNew) \
	{ \
		pNew->pfn = &g_##name##Fun; \
		pNew->pNext = NULL; \
	} \
	return pNew; \
}

#define FIND_NODE_BY_NAME(type,pHead, Name, pLast) \
type *pTemp = (type*)pHead; \
while(NULL != pTemp) \
{ \
	if(Strcmp(pTemp->m_szName,Name)) \
	{ \
		break; \
	} \
	*pLast = (LINKER *)pTemp; \
	pTemp = (type *)pTemp->m_Linker.pNext; \
} \
return (LINKER*)pTemp;


#endif