/*
 *
 * Developed by The Johns Hopkins University/Applied Physics Laboratory (JHU/APL)
 *
 *
 */

/*
 * Developed by The Johns Hopkins University/Applied Physics Laboratory
 *
 *      Project:        Cooperative Engagement Capability Software
 *
 *	Module Name:	ntpinfo
 *
 *	Description:	
 *		This module provides a simplified interface for retrieving
 *		critical NTP parameters from an NTP server.
 *
 *	Programmer:	Steven Kahn
 *
 */
#ifdef  __cplusplus
extern "C" {
#endif


/*
 *			GET_NTP_STATS
 *
 *	DESCRIPTION:
 *		This function provides a simple API for retrieving critical
 *		NTP parameters from a designated NTP server. In general, it
 *		is sufficient to check for a success code (return code of 0).
 *		If a non-zero code is returned, you can assume there's a
 *		problem with NTP synchronization. On success, additional
 *		information is returned via the pass-by-reference parameters.
 *
 *	INPUTS:
 *		server_address: IP address (in dotted decimal notation) of the
 *			NTP server; if 0, uses 127.0.0.1 (loopback)
 *		stratum: Address of location where stratum of server is placed
 *		refid: Char array where the NTP reference peer is placed; must
 *			reserve at least 16 bytes for this array
 *		reach: Address of location where the reachability value is placed
 *		offset: Address of location where the NTP-estimated clock offset
 *			value is placed
 *		delay: Address of location where the NTP-estimated delay time
 *			is placed
 *		jitter: Address of location where the NTP-estimated jitter value
 *			is placed
 *
 *	RETURNS:
 *		NOTE: the return code can be passed to NTP_Error_To_String to
 *		obtain a human-readable string describing the error.
 *
 *		0: Success
 *		1: Error creating socket
 *		2: Error binding socket to local address
 *		3: Error in NTP version
 *		4: Error in mode field
 *		5: Returned NTP control message is not a response
 *		6: NTP server indicates an error in the request
 *		7: Unexpectedly long response to NTP request
 *		8: Response contains incorrect opcode
 *		9: Response contains the wrong sequence number
 *		10: Response is an unexpected fragment
 *		11: Unexpectedly large amount of returned data
 *		12: Unexpectedly short response to NTP request
 *		13: No file descriptor is set after select
 *		14: Failure on select (probably timeout)
 *		15: Cannot find requested variable in response
 *		16: Malformed response string
 *		17: Response contains the wrong association ID
 *		18: Error converting variable string to long int
 *		19: Error converting variable string to float
 *		20: Clock not synchronized
 */
int Get_NTP_Stats(
	const char *server_address,
	unsigned int *stratum,
	char *refid,  /* must point to buffer of at least 16 bytes */
	unsigned int *reach,
	float *offset,
	float *delay,
	float *jitter
);

/*
 *			NTP_ERROR_TO_STRING
 *
 *	DESCRIPTION:
 *		This function converts an error code returned by Get_NTP_Stats
 *		into a human-readable string, which is returned.
 *
 *	INPUTS:
 *		error_code: return value of Get_NTP_Stats
 *
 *	RETURNS:
 *		Pointer to constant string describing the error
 */
const char *NTP_Error_To_String(int error_code);

#ifdef  __cplusplus
}
#endif

