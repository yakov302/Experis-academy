#ifndef __ENUM_H__
#define __ENUM_H__
#include <stdio.h>

/*return messages*/
typedef enum{
ERR_OK,
ERR_GENERAL,
ERR_NOT_INITIALIZED,
ERR_ALLOCATION_FAILED,
ERR_REALLOCATION_FAILED,
ERR_UNDERFLOW, 
ERR_OVERFLOW, 
ERR_WRONG_INDEX,
ERR_SIZE,
UNBALANC,
BALANC}ADTErr;



#endif /*#ifndef__INUM_H__*/
