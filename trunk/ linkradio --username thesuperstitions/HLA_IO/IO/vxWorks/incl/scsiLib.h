/* scsi2Lib.h - SCSI library header file */


/*
modification history
--------------------
01b,19aug95,jds  added comments 
01a,10oct94,jds  merged for SCSI1 and SCSI2 compatability
*/

#ifndef SCSI_LIB_H
#define SCSI_LIB_H

#ifndef INCLUDE_SCSI2

#include <scsi1Lib.h>

#else

#include <scsi2Lib.h>

#endif

#define M_scsiLib            (55 << 16)

#endif
