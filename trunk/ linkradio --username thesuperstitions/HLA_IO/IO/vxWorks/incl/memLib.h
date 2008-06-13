/* memLib.h - memory management library header file */


/*
modification history
--------------------
03s,19aug96,dbt  added memPartAlignedAlloc prototype (fixed SPR #6898).
03r,30oct94,kdl  merge cleanup - removed extra "#ifndef _ASMLANGUAGE".
03o,15oct93,cd   added #ifndef _ASMLANGUAGE.
03q,27oct94,ism  Fixed assembly problem from merge
03p,01dec93,jag  added struct MEM_PART_STATS and function memPartInfoGet.
03o,02apr93,edm  ifdef'd out non-ASMLANGUAGE portions
03n,05feb93,smb  added include of vxWorks.h
03m,22sep92,rrr  added support for c++
03l,19jul92,pme  added external declarations for sm partition functions.
03k,13jul92,rdc  added prototype for valloc.
03j,04jul92,jcf  cleaned up.
03i,22jun92,rdc  added memalign and memPartAlignedAlloc.
03h,26may92,rrr  the tree shuffle
03g,25mar92,jmm  added new options for error handling
03f,04oct91,rrr  passed through the ansification filter
		  -fixed #else and #endif
		  -changed VOID to void
03e,10jun91.del  added pragma for gnu960 alignment.
03d,05oct90,dnw  deleted private routines.
03c,05oct90,shl  added ANSI function prototypes.
                 made #endif ANSI style.
03b,10aug90,dnw  added declaration of memPartInit().
03a,18jul90,jcf  made partitions objects.
		 changed malloc(),realloc(),calloc() etc to return void *.
02c,17mar90,jcf  added structure type definition.
02b,28jun89,llk  added declaration for free();
02a,11jun88,dnw  changed for rev 03a of memLib.
01l,28mar88,gae  added function decl. of calloc().
01j,13nov87,gae  removed FRAGMENT definition; made function decl.'s IMPORTs.
01h,23oct87,rdc  added PARTITION defenitions.
01g,24dec86,gae  changed stsLib.h to vwModNum.h.
01f,21may86,rdc	 added forward declarations for malloc and realloc.
		 added FRAGMENT structure.
01e,13aug84,ecs  changed S_memLib_NO_MORE_MEMORY to S_memLib_NOT_ENOUGH_MEMORY.
01d,07aug84,ecs  added include of stsLib.h, and status codes.
01c,15jun84,dnw  removed declaration of memEnd (no longer exists).
01b,27jan84,ecs  added inclusion test.
01a,24may83,dnw  written
*/

#ifndef MEM_LIB_H
#define MEM_LIB_H

#include <prototype.h>
#include <stdio.h>
#include <malloc.h>
#include <vxWorks.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define M_memLib				(17 << 16)
#define S_memLib_NOT_ENOUGH_MEMORY		(M_memLib | 1)
#define S_memLib_INVALID_NBYTES			(M_memLib | 2)
#define S_memLib_BLOCK_ERROR			(M_memLib | 3)
#define S_memLib_NO_PARTITION_DESTROY		(M_memLib | 4)
#define S_memLib_PAGE_SIZE_UNAVAILABLE		(M_memLib | 5)

typedef char* PART_IDS;
typedef char* PART_ID;

/* partition options */

/* optional check for bad blocks */

#define MEM_BLOCK_CHECK                 0x10

/* response to errors when allocating memory */

#define MEM_ALLOC_ERROR_LOG_FLAG        0x20
#define MEM_ALLOC_ERROR_SUSPEND_FLAG    0x40

/* response to errors when freeing memory */

#define MEM_BLOCK_ERROR_LOG_FLAG        0x80
#define MEM_BLOCK_ERROR_SUSPEND_FLAG    0x100

/* old style allocation errors - block too big, insufficient space */

#define MEM_ALLOC_ERROR_MASK            0x03
#define MEM_ALLOC_ERROR_RETURN          0
#define MEM_ALLOC_ERROR_LOG_MSG         0x01
#define MEM_ALLOC_ERROR_LOG_AND_SUSPEND 0x02

/* old style bad block found */

#define MEM_BLOCK_ERROR_MASK            0x0c
#define MEM_BLOCK_ERROR_RETURN          0
#define MEM_BLOCK_ERROR_LOG_MSG         0x04
#define MEM_BLOCK_ERROR_LOG_AND_SUSPEND 0x08

/* does simple malloc */
/*
 * @limitation In the POSIX implementation, the heap (malloc) is
 * used for the memory partition. Therefore, since typically a malloc'ed pool
 * is passed in as the first argument, this memory is immediately
 * freed.
 */
PART_ID
memPartCreate (
	char *pPool,
	unsigned poolSize
);

/*
 * @limitation Since malloc is used, it is only necessary to return
 * a value that is large enough to satisfy the applications.
 */
int
memFindMax (
	void
);

/*
 * @limitation Always returns OK, since options have no meaning
 * for Unix heap storage.
 */
int
memPartOptionsSet (
	PART_ID partId,
	unsigned options
);

void *
memPartAlloc (
	PART_ID partId,
	unsigned nBytes
);

/*
 * @limitation Since malloc is used by memPartAlloc, the passed in memory can
 * immediately be freed.
 */
int
memPartAddToPool (
	PART_ID partId,
	char *pPool,
	unsigned poolSize
);

STATUS
memPartFree (
	PART_ID partId,
	char *pBlock
);

/*
 * @limitation This has no meaning on Unix systems.
 */
void
memOptionsSet (
	unsigned options
);

#ifdef	__cplusplus
}
#endif

#endif
