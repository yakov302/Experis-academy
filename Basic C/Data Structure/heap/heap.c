#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "heap.h"
#include "enum.h"
#define MAGIC_NUMBER 8123475
#define FATHER(i) ((i)-1)/2
#define RIGHT_CHILD(i) (i)*2 + 2
#define LEFT_CHILD(i) (i)*2 + 1

/****************AuxiliaryFunctions****************/

static void bubbleUp (Heap* _heap);
void Heapify(Heap* _heap, int _index);
static int CheckBigest(Heap* _heap, int _index);


/********************structHeap********************/

struct Heap
{
Vector* m_vec;
size_t m_heapSize;
int m_magicNumber;
};

/*********************HeapBuild********************/

Heap* HeapBuild(Vector* _vec)
{
Heap* heapPtr;
size_t numOfltems;
int i;

	if(_vec == NULL)
	{
		return NULL;
	}
	
	if((heapPtr = ((Heap*)malloc(sizeof(Heap)))) == NULL)
	{
		return NULL;
	}
	
	VectorItemsNum (_vec, &numOfltems);
	heapPtr -> m_vec = _vec;
	heapPtr -> m_heapSize = numOfltems;
	heapPtr -> m_magicNumber = MAGIC_NUMBER;
	
	for(i = FATHER(heapPtr -> m_heapSize - 1); i >= 0; i--)
	{
		Heapify(heapPtr,i);
	}
	
return heapPtr;
}


/*********************HeapDestroy********************/

void HeapDestroy(Heap* _heap)
{
	if(_heap == NULL || _heap ->  m_magicNumber != MAGIC_NUMBER)
	{
		return;
	}
	
	_heap ->  m_magicNumber = 0;
	free(_heap);
}

/*********************HeapInsert********************/

ADTErr HeapInsert(Heap* _heap, int _data)
{
ADTErr addErr;

	if(_heap == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	
	addErr = VectorAdd (_heap -> m_vec , _data);
	if( addErr != ERR_OK)
	{
		return addErr;
	}
	
	_heap -> m_heapSize++;
	bubbleUp(_heap);
	
return ERR_OK;
}

/*********************HeapMax********************/

ADTErr HeapMax (Heap* _heap, int* _data)
{
ADTErr addErr;

	if(_heap == NULL || _data == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	
	if(_heap -> m_heapSize == 0)
	{
		return ERR_UNDERFLOW;
	}

	addErr = VectorGet(_heap -> m_vec ,0, _data);

return addErr;
}

/*********************HeapHxtractMax********************/

ADTErr HeapHxtractMax (Heap* _heap, int* _data)
{
int last;

	if(_heap == NULL || _data == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	if(_heap -> m_heapSize == 0)
	{
		return ERR_UNDERFLOW;
	}

	VectorGet(_heap -> m_vec ,0, _data);
	VectorDelete(_heap -> m_vec,  &last);
	VectorSet(_heap -> m_vec, 0, last);
	_heap -> m_heapSize--;
	Heapify(_heap, 0);

return ERR_OK;	
}

/*********************HeapItemsNum********************/

int HeapItemsNum(Heap* _heap)
{
	if( _heap == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	return _heap -> m_heapSize;
}

/********************HeapPrint*********************/

void HeapPrint(Heap* _heap)
{
	if( _heap == NULL)
	{
		return;
	}
	VectorPrint(_heap -> m_vec);
}

/********************AuxiliaryFunctions*********************/

static void bubbleUp (Heap* _heap)
{
int New;
int Father;
int iNew = 0;
int iFather = 0;

	iNew = _heap -> m_heapSize -1;
	iFather = FATHER(iNew);
	
	VectorGet(_heap -> m_vec, iNew, &New);
	VectorGet(_heap -> m_vec,iFather, &Father);
	
	while( New > Father && iNew > 0)
	{
		VectorSet(_heap -> m_vec, iNew, Father);
		VectorSet(_heap -> m_vec, iFather, New);

		iNew = 	iFather;
		iFather = FATHER(iNew);
		
		VectorGet(_heap -> m_vec, iNew, &New);
	        VectorGet(_heap -> m_vec, iFather, &Father);
	}	
}


void Heapify(Heap* _heap, int _index)
{
int Father;
int Bigest;
int iBigest;
int iFather;
int iLeftChild;

	iFather = _index;
	iLeftChild = LEFT_CHILD( _index);
	
	if(iLeftChild >  _heap -> m_heapSize - 1)
	{
		return;
	}
	
	iBigest = CheckBigest( _heap, _index);
	
	VectorGet(_heap -> m_vec ,iBigest, &Bigest);
	VectorGet(_heap -> m_vec ,iFather, &Father);
			
	if(iBigest != _index)
	{
		VectorSet(_heap -> m_vec , iBigest, Father);
		VectorSet(_heap -> m_vec , iFather, Bigest);	
		Heapify(_heap, iBigest);	
	}
}


static int CheckBigest(Heap* _heap, int _index)
{
int Father;
int LeftChild;
int RightChild;
int iFather;
int iLeftChild;
int iRightChild;

	iFather = _index;
	iLeftChild = LEFT_CHILD( _index);
	iRightChild = RIGHT_CHILD( _index);
	
	if(iRightChild <= _heap -> m_heapSize -1)
	{
		VectorGet(_heap -> m_vec ,iFather, &Father);
		VectorGet(_heap -> m_vec ,iLeftChild, &LeftChild);		
		VectorGet(_heap -> m_vec  ,iRightChild, &RightChild);
		
		if(Father >= LeftChild && Father >= RightChild)
		{
			return iFather;
		}
		else if ( LeftChild >= RightChild)
		{
			return iLeftChild;
		}
		else
		{
			return iRightChild;
		}	
	}
	
		VectorGet(_heap -> m_vec ,iFather, &Father);
		VectorGet(_heap -> m_vec ,iLeftChild, &LeftChild);
		
		if(Father >= LeftChild)
		{
			return iFather;
		}
		else 
		{
			return iLeftChild;
		}		
}


/*********************TeseFunction********************/

getHeapSize(Heap* Heap)
{
	return Heap -> m_heapSize;
}

getMagicNumber(Heap* Heap)
{
	return Heap -> m_magicNumber;
}












