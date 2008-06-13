#ifndef SC_posix_H
#define SC_posix_H

#include <stdio.h>
#include <sys/socket.h>

#ifdef  __cplusplus
extern "C" {
#endif

int sc_accept (int s, struct sockaddr *addr, socklen_t *addrlen);

int sc_connect (int s, struct sockaddr *name, int namelen);

int sc_select(int width, fd_set *pReadFds, fd_set *pWriteFds, fd_set *pExceptFds, struct timeval *pTimeOut);

int sc_pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);

int sc_pthread_cond_timedwait(pthread_cond_t *cond, pthread_mutex_t *mutex,
	int deltaTimeMs);

int sc_gettimeofday(struct timeval *tp, void *);

#ifdef  __cplusplus
}
#endif

#endif
