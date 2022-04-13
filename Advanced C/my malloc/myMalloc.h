/***************************************************************
* Author : Yakov Hananel Zaidenberg
* Project : My Malloc
* Description: Malloc interface for shared object
* Version : V1.0
* Date : 05/01/2022
***************************************************************/
#ifndef __MYMALLOC_H__
#define __MYMALLOC_H__

typedef unsigned char BYTE;
/*After initializiation only _memorySize-24 bytes are available
for client usage */
void MyMallocInit(void* _memory, size_t _memorySize);
/*Every allocation returns _requiredBlockSize bytes to the
client,
* but reserves _requiredBlockSize+8 bytes from _memory .
*/
void* MyMalloc(void* _memory, size_t _requiredBlockSize);

void MyFree(void* _myBlock);

#endif /* __MYMALLOC_H__ */
