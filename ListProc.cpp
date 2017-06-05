#include "ListProc.h"
#include <tbsys.h>

LINKER *g_pHead = NULL;

bool CreateList(LINKER **pHead, PCREATE pfn)
{
	if(NULL != pHead && NULL == *pHead)
	{
		if(NULL != (*pHead = pfn()))
		{
			(*pHead)->INPUTNODE(*pHead);
			return true;
		}
	}
	return false;
}

bool ShowList(LINKER *pHead)
{
	if(NULL == pHead)
	{
		return false;
	}

	LINKER *pTemp = pHead;
	while(NULL != pTemp)
	{
		pTemp->OUTPUTNODE(pTemp);
		pTemp = pTemp->pNext;
	}
}

bool AddNode(LINKER *pHead, PCREATE pfn)
{
	if(NULL == pHead)
	{
		//head error!
		return false;
	}
	LINKER *pNew = pfn();
	LINKER *pTemp = pHead;
	if(NULL == pNew)
	{
		//malloc error!
		return false;
	}
	pNew->INPUTNODE(pNew);

	while(NULL != pTemp->pNext)
	{
		pTemp = pTemp->pNext;
	}
	pTemp->pNext = pNew;
	return true;
}

LINKER* ListFindNode(LINKER *pHead,LINKER **pLast)
{
	if(NULL != pHead)
	{
		TBSYS_LOG(DEBUG,"entry ListFindNode!");
		LINKER *pTemp = pHead->FINDNODE(pHead,pLast);
		return pTemp;
	}
	return NULL;
}

bool DeleteNode(LINKER **pHead)
{
	if(NULL == pHead || NULL == *pHead)
	{
		return false;
	}

	LINKER *pLast = NULL;
	LINKER *pTemp = (*pHead)->FINDNODE(*pHead, &pLast);
	if(NULL == pTemp)
	{
		//no find
		return false;
	}
	//delete head
	if(*pHead == pTemp && NULL == pLast)
	{
		*pHead = (*pHead)->pNext;
	}
	else
	{
		pLast->pNext = pTemp->pNext;
	}
	free(pTemp);
	return true;
}

bool ModifyNode(LINKER *pHead)
{
	if(NULL == pHead)
	{
		return false;
	}

	LINKER *pLast = NULL;
	LINKER *pTemp = pHead->FINDNODE(pHead, &pLast);
	if(NULL == pTemp)
	{
		return false;
	}
	pTemp->INPUTNODE(pTemp);
	return true;
}

bool InsertNodeBehind(LINKER *pHead, PCREATE pfn)
{
	if(NULL == pHead)
	{
		return false;
	}

	LINKER *pLast = NULL;
	LINKER *pTemp = pHead->FINDNODE(pHead,&pLast);
	if(NULL == pTemp)
	{
		//no find
		return false;
	}

	LINKER *pNew = pfn();
	if(NULL == pNew)
	{
		//malloc NULL
		return false;
	}
	pNew->INPUTNODE(pNew);

	pNew->pNext = pTemp->pNext;
	pTemp->pNext = pNew;
	return true;
}

//studentHead is ListHead
bool InsertNodeFront(LINKER **pHead, PCREATE pfn)
{
	if(NULL == pHead || NULL == *pHead)
	{
		//NULL or head = NULL
		return false;
	}

	LINKER *pLast = NULL;
	LINKER *pTemp = (*pHead)->FINDNODE(*pHead,&pLast);
	if(NULL == pTemp)
	{
		//no find
		return false;
	}

	LINKER *pNew = pfn();
	if(NULL == pNew)
	{
		//malloc NULL
		return false;
	}
	pNew->INPUTNODE(pNew);
	TBSYS_LOG(DEBUG,"pNew = 0x%x",pNew);

	//insert Head
	if(*pHead == pTemp && NULL == pLast)
	{
		TBSYS_LOG(DEBUG,"start entry insert front node");
		pNew->pNext = *pHead;
		*pHead = pNew;
		TBSYS_LOG(DEBUG,"pHead = 0x%x",*pHead);
	}
	else
	{
		pLast->pNext = pNew;
		pNew->pNext = pTemp;
	}

	return true;
}

/*当学生节点的头结点不是链表的头结点的时候，在进行前插在头上的操作时会变得不一样
其进行的不是真的头插操作*/
bool InsertNodeFront_another(LINKER *pListHead, LINKER *pHead, PCREATE pfn)
{
	if(NULL == pListHead || NULL == pHead)
	{
		return false;
	}

	LINKER *pLast = NULL;
	LINKER *pTemp = pHead->FINDNODE(pHead,&pLast);
	if(NULL == pTemp)
	{
		//no find
		return false;
	}

	LINKER *pNew = pfn();
	if(NULL == pNew)
	{
		//malloc NULL
		return false;
	}
	pNew->INPUTNODE(pNew);

    //this is different from InsertNodeFront ,because StudentHead isnot ListHead
	if(pHead == pTemp && NULL == pLast)
	{
		LINKER *pStr = pListHead;
		while(pHead != pStr->pNext)
		{
			pStr = pStr->pNext;
		}
		pNew->pNext = pHead;
		pStr->pNext = pNew;
	}
	else
	{
		pLast->pNext = pNew;
		pNew->pNext = pTemp;
	}

	return true;
}

bool ClearList(LINKER **pHead)
{
	if(NULL == pHead || NULL == *pHead)
	{
		return false;
	}

	LINKER *pTemp = *pHead;
	while(NULL != pTemp)
	{
		*pHead = pTemp->pNext;
		free(pTemp);
		pTemp = *pHead;
	}
	return true;
}