/* pipeDrv.h - header file for pipeDrv.c */

#ifndef __INCpipeDrvh
#define __INCpipeDrvh

#ifdef __cplusplus
extern "C" {
#endif

/* function declarations */

#if defined(__STDC__) || defined(__cplusplus)

/*
 * @limitation The POSIX implementation creates a named FIFO
 * to implement the pipe. A named FIFO is a fixed size therefore the 
 * nMessages and nBytes  arguments in pipeDevCreate() are essentially ignored. 
 * However, if the application requests a pipe size that is larger than the
 * named FIFO size then a warning message is printed out. An application
 * that assumes it gets the larger pipe size and does not account for 
 * being blocked in a write to that pipe, may have a problem. The 
 * warning printout may help the developer detect the problem sooner.
 *
 * Note that while VxWorks maintains
 * message boundaries in pipes, POSIX treats pipes as streams.
 * Therefore, if you wish to support message semantics in a
 * portable fashion, you might consider using message queues
 * instead of pipes.
 *
 * A FIFO is a type of file and the 'name' argument specifies a pathname in
 * the file system. The directory of the pathname should exist on the system 
 * before your application calls this routine, and your application should
 * have read and write permission to it. 
 *
 * It's the VxWorks' convention to name pipes like this: /pipe/<yourName>. 
 * Creating a /pipe directory on your host with proper permissions
 * will cover applications using pipes with the vxWorks naming convention.
 *
 */
STATUS 
pipeDevCreate (
	char *name,
	int nMessages,
	int nBytes
);

STATUS
pipeDrv (
	void
);

/*
 * Message boundaries and pipes:
 *
 * A vxWorks pipe preserves message boundaries and a Solaris pipe does not.
 *
 * Solaris pipes do not support ioctl() requests to return the
 * number of messages in the pipe since message boundaries are not
 * preserved. Thus the FIONMSGS ioctl() request supported by vxWorks
 * is not supported in Solaris. The FIONMSGS symbol does not exist in Solaris.
 *
 * In many cases, it's easy for a vxWorks app to change from using a pipe
 * to using a message queue. This would make the code more efficient when
 * running on vxWorks because the pipe layer around the message queue is 
 * eliminated. It would also make the code more portable between vxWorks
 * and Solaris. Changing to a message queue allows you to get the number
 * of messages in the queue without using the unsupported FIONMSGS.
 *
 * One case that is not easy to convert to message queues is the case when a
 * task is doing a select() in multiple pipes. You can't do a select() on
 * multiple message queues in either vxWorks or Solaris. However, if the
 * pipe is carrying messages with identical sizes, it's possible to 
 * keep using the pipe in both environments with some minor adjustments to
 * the application. The Solaris ioct() FIONREAD request along with the 
 * known message size can be used to find how many messages are in a 
 * Solaris pipe. Solaris documents "FIONREAD" as: "Returns the number of 
 * immediately readable characters in the int pointed to by the argument."
 *
 * The "pipeDrvNumMsgs()" provides a way to get the number of messages in 
 * a pipe for this special case situation. The application could use
 * a conditional compile to choose this function when compiling for
 * Solaris or the ioctl(FIONMSGS) when compiling for vxWorks.
 *
 * Also, if the pipe messages all have the same size, the reading application
 * should get one whole message if it requests a number of bytes equal to the
 * message size.  Solaris doc says "In byte-stream mode, read() retrieves 
 * data from the STREAM until as many bytes as were requested are transferred, 
 * or until there is no more data to be retrieved."  The reading app should
 * check that read() has returned a number of bytes that equals the message
 * size. This check should be applicable in both Solaris and vxWorks. 
 *
 * FIONMSGS ioctl() request not supported in Solaris. This
 * pipeDrvNumMsgs() func provides a way to get the
 * number of messages in a Solaris pipe. Func assumes that 
 * all messages are the same size. Will not work 
 * correctly if they are not the same size.
 */

STATUS
pipeDrvNumMsgs (
    int fildes,		/* pipe's file descriptor */ 
    int msgSzBytes,	/* size of fixed size message(s) in pipe, bytes */
    int *numMsgsPtr	/* number of message in pipe */
);

#else	/* __STDC__ */

extern STATUS 	pipeDevCreate ();
extern STATUS 	pipeDrv ();

#endif	/* __STDC__ */

#ifdef __cplusplus
}
#endif

#endif /* __INCpipeDrvh */
