/* config.h - UNIX-target configuration header */


/*
modification history
--------------------
02j,20oct98,pr   added WindView 2.0 defines
02i,07jul98,db   changed BSP_VERSION to "1.2" and BSP_REVISION to "/0".
		 added BSP_VER_1_1 and BSP_VER_1_2 macros, 
		 (Tornado 2.0 release).
02h,08apr98,pdn  changed defaults to build intergrated simulator.
02g,15apr97,pr   Changed default WDB_MTU for ULIP driver.
02f,12feb97,ms   Added PPP network configuration macros
02e,03jan97,dat  BSP_REV 1, Tornado 1.0.1, (c) 1997
02d,30nov96,dvs  removing def's for testing
02c,28may96,ism  added USER_RESERVED_MEM
02b,22may96,dat  cleanup, added BSP_VERSION, BSP_REV
02a,20dec95,ism  added INCLUDE_TYCODRV_5_2
01k,20jul94,ms   removed the undef of INCLUDE_RDB.
01j,19feb94,gae  changed SM_INT_ARG2 from vector 1.
01i,14feb94,gae  changed SM_INT_ARG2 from vector 30.
01h,11jan94,gae  added SM parameters.
01g,14dec93,gae  moved TYCO_DEV here.
01f,30jul93,gae  reduced NV_RAM_SIZE from 2040; added MATH macro's.
01e,05jul93,gae  added sysBootLineMagic.
01d,23jan93,gae  cleanup.
01c,07aug92,gae  added INCLUDE_ULIP and NFS.
01b,29jul92,gae  variable change: lwplvlLock.
01a,22apr92,gae  derived from BNR.
*/

#ifndef CONFIG_H
#define CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

#define BOOT_LINE_SIZE 255

#ifndef INCLUDE_SCSI2
#define INCLUDE_SCSI2
#endif

#ifdef	__cplusplus
}
#endif

#endif
