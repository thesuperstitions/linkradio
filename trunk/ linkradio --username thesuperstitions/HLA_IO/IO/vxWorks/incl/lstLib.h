/* lstLib.h - doubly linked list library header */


/*
modification history
--------------------
01m,02apr93,edm  ifdef'd out non-ASMLANGUAGE portions
01l,22sep92,rrr  added support for c++
01k,04jul92,jcf  cleaned up.
01j,26may92,rrr  the tree shuffle
01i,04oct91,rrr  passed through the ansification filter
		  -changed VOID to void
01h,23oct90,shl  included "vxWorks.h" so include file order isn't crucial.
01g,05oct90,shl  added ANSI function prototypes.
                 made #endif ANSI style.
01f,10aug90,dnw  added declaration of lstInsert().
01e,07aug90,shl  added IMPORT type to function declarations.
01d,21may86,llk	 added forward declaration of lstNStep.
01c,03jun84,dnw  changed list.{head,tail} to list.node.
		 added declarations of lst{First,Last,Next,Previous}.
01b,27jan84,ecs  added inclusion test.
01b,15mar83,dnw  changed name from lstlb to lstLib
*/

#ifndef _LSTLIB_H
#define _LSTLIB_H

#include <vxTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct node
{
	struct node *next;
	struct node *previous;
} NODE;


typedef struct
{
	int count;
	NODE *head;
	NODE *tail;
} LIST;

/*
 * Turn internal list validation on/off
 * val: TRUE=do internal list validation, FALSE=don't validate
 */
void lstValidateOn (
	BOOL val
);

/*
 * check the whole link list for errors
 */
STATUS lstValidate (
	LIST *pList
);

NODE *
lstFirst (
	LIST *pList
);

NODE *
lstGet (
	LIST *pList
);

NODE *
lstLast (
	LIST *pList
);

/*
 * @limitation Not currently implemented.
 */
NODE *
lstNStep (
	NODE *pNode,
	int nStep
);

NODE *
lstNext (
	NODE *pNode
);

NODE *
lstNth (
	LIST *pList,
	int nodenum
);

NODE *
lstPrevious (
	NODE *pNode
);

int
lstCount (
	LIST *pList
);

int
lstFind (
	LIST *pList,
	NODE *pNode
);

void
lstAdd (
	LIST *pList,
	NODE *pNode
);

/*
 * @limitation Not currently implemented.
 */
void
lstConcat (
	LIST *pDstList,
	LIST *pAddList
);

void
lstDelete (
	LIST *pList,
	NODE *pNode
);

/*
 * @limitation Not currently implemented.
 */
void
lstExtract (
	LIST *pSrcList,
	NODE *pStartNode,
	NODE *pEndNode,
	LIST *pDstList
);

void
lstFree (
	LIST *pList
);

void
lstInit (
	LIST *pList
);

void
lstInsert (
	LIST *pList,
	NODE *pPrev,
	NODE *pNode
);

#ifdef __cplusplus
}
#endif

#endif /* _LSTLIB_H */
