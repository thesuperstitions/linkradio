#ifndef KERNEL_LIB_H
#define KERNEL_LIB_H

#include "vxWorks.h"

/*
 * kernelTimeSlice - set a round robin scheduling parameter for tasks that
 * are at the same priority level and ready to run.
 *
 * The default configutation is "round robin" or "time slicing" OFF. Calling
 * the routine with any positive argument turns it ON. Calling it
 * with a zero argument turns round robin OFF. A negative argument is
 * ignored.
 *
 * This routine must be called before tasks are spawned to be efffective. It will
 * not be effective for tasks that already are running when it is called. 
 *
 * The implementation does not use the actual passed in value. Instead it will
 * use the default round robin values if  the 'ticks' argument is > 0.
 * Execute "dispadmin -c RT -g" to display the default time quanta for each 
 * RT priority.
 *
 */
extern STATUS kernelTimeSlice(int ticks);
	/* time-slice in ticks or 0 to disable round-robin */

extern int kernelGetTimeSlice();
	/* get time-slice in ticks. 0 = disable round-robin */

/*
 * Miscellaneous related debug commands: 
 *
 * See the "i" display in the shell for a printout of the policy used on 
 * each thread.
 *
 * "dispadmin -c RT -g" will display the time quanta for each RT priority. units
 * are in milliseconds.
 *
 * "priocntl -d -i class RT" will display the time quanta of all real-time 
 * processes.
 */

#endif /* KERNEL_LIB_H */
