/* vxTypes.h - VxWorks type definition header */


/*
modification history
--------------------
40a,24jul91,shl  SPECIAL VERSION FOR 5.0.2 68040 RELEASE. added defines 
		 of __volatile__ and __const__ if !_STDC_ && _GNUC__
01e,28jan91,kdl  added DBLFUNCPTR and FLTFUNCPTR.
01d,25oct90,dnw  changed VOID to void except when linting.
                 made #endif ANSI style.
01b,10aug90,dnw  added VOIDFUNCPTR
01a,29may90,del  written.
*/

#ifndef INCvxTypesh
#define INCvxTypesh

#ifndef P
#if defined(__STDC__) || defined(__STDCPP__) || defined(USE_PROTOTYPES)
#define P(x)    x
#else /* __STDC__ __STDCPP__ USE_PROTOTYPES */
#define P(x)    ()
#endif /* USE_PROTOTYPES */
#endif /* P */

/* The following stuff must NOT be included if this include file is used
 * from assembly language.  Just #define ASMLANGUAGE before the include,
 * to get rid of it.
 */

#ifndef ASMLANGUAGE

/* vxWorks types */

typedef	char		INT8;
typedef	short		INT16;
/*typedef	int		INT32; */

typedef	unsigned char	UINT8;
typedef	unsigned short	UINT16;
typedef	unsigned int	UINT32;

typedef	unsigned char	UCHAR;
typedef unsigned short	USHORT;
typedef	unsigned int	UINT;
typedef unsigned long	ULONG;

typedef	int		BOOL;
typedef	int		STATUS;
typedef int 		ARGINT;

#ifdef	LINT
typedef	int		VOID;
#else
typedef	void		VOID;
#endif	/* LINT */

typedef int 		(*FUNCPTR) ();	   /* ptr to function returning int */
typedef void 		(*VOIDFUNCPTR) (); /* ptr to function returning void */
typedef void 		(*VOIDINTFUNCPTR) (int); /* ptr to function returning void */
typedef double 		(*DBLFUNCPTR) ();  /* ptr to function returning double*/
typedef float 		(*FLTFUNCPTR) ();  /* ptr to function returning float */
typedef int		(*FUNCINTPTR) (int);


/* historical definitions - now obsolete */

typedef char		TINY;		/* obsolete */
typedef char		TBOOL;		/* obsolete */
typedef unsigned char	UTINY;		/* obsolete */
#define READ		0
#define WRITE		1
#define UPDATE		2

/* architecture dependent typedefs */

#ifdef	CPU_FAMILY

#if	CPU_FAMILY==MC680X0
typedef unsigned short INSTR;		/* word-aligned instructions */
#endif	/* CPU_FAMILY==MC680X0 */

#if	CPU_FAMILY==SPARC
typedef unsigned long INSTR;		/* 32 bit word-aligned instructions */
#endif	/* CPU_FAMILY==SPARC */

#endif	/* CPU_FAMILY */

/* ANSI type qualifiers */

#ifndef __STDC__
#ifndef __STDCPP__
#ifdef  __GNUC__
#define volatile        __volatile__
#define const           __const__
#define signed          __signed__
#else
#define volatile
#define const
#define signed
#endif  /* __GNUC__ */
#endif	/* __STDCPP__ */
#endif  /* __STDC__ */

#endif	/* ASMLANGUAGE */

#endif	/* INCvxTypesh */
