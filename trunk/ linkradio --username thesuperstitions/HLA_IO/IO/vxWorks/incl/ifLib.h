/* ifLib.h - network interface library header */


/*
modification history
--------------------
01d,06oct98,ham  added ifAddrAdd.
01c,02sep93,elh  changed param name to ifunit
01b,22sep92,rrr  added support for c++
01a,04jul92,jcf  cleaned up.
01b,26may92,rrr  the tree shuffle
01a,10dec91,gae  written.
	   +rrr
*/

#ifndef IF_LIB_H
#define IF_LIB_H

#include <vxWorks.h>

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef LINUX
/*
 * This structure is only defined for LINUX, since it no longer
 * appears in net/if.h.
 */
struct ifnet {
	int	if_mtu;  /* maximum transmission unit */
};
#endif

/*
 * @limitation Only the if_mtu field of the returned ifnet structure
 * is currently filled in.
 */
struct ifnet *
ifunit (
	char	*ifname
);

/*
 * @limitation Has no effect on Unix systems.
 */
STATUS
ifFlagChange (
	char	*interfaceName,
	int	flags,
	BOOL	on
);

/*
 * @limitation Simply returns the address corresponding
 * to the <i>interfaceName</i> that must have been previously
 * set by <i>ifAddrSet</i> (see below).
 */
STATUS
ifAddrGet (
	char	*interfaceName,
	char	*interfaceAddress
);

/*
 * @limitation Simply sets the address by calling <i>hostAdd</i>.
 */
STATUS
ifAddrSet (
	char	*interfaceName,
	char	*interfaceAddress
);

#ifdef	__cplusplus
}
#endif

#endif
