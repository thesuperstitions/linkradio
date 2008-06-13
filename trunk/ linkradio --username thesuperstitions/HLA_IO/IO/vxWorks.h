#ifndef VXWORKS_KWR__H
#define VXWORKS_KWR__H


//typedef char* PART_ID;

typedef unsigned int CLOCK;	/* cep wasp simulation clock */

#if     !defined(FALSE) || (FALSE!=0)
#define FALSE           0
#endif

#if     !defined(TRUE) || (TRUE!=1)
#define TRUE            1
#endif
//
//#ifndef ERROR
//#define ERROR (-1)
//#endif

#ifndef OK
#define OK 0
#endif

typedef void *MSG_Q_ID;


#define WAIT_FOREVER	(-1)


typedef	int		STATUS;



int
sysClkRateGet (
	void
);












#endif  //VXWORKS_KWR__H