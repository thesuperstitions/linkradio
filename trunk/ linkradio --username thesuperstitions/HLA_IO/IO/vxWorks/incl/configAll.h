/* configAll.h - default configuration header */


/*
modification history
--------------------
07o,19mar99,dat  removed old driver support SPR 25877
07n,10mar99,drm  changing WINDMP to VXFUSION to reflect new product name.
07m,23feb99,sn   corrected comment for INCLUDE_CPLUS_STL
                 removed INCLUDE_CPLUS_BOOCH and INCLUDE_CPLUS_HEAP since
                 they're no-ops.
07l,04feb99,jmp  added INCLUDE_TSFS_BOOT & INCLUDE_TSFS_BOOT_VIO_CONSOLE to
                 the excluded facilities list (SPR# 24466).
07k,02feb99,tm   added PCI configuration type constants (PCI_CFG_*)
07j,28jan99,dat  removed INCLUDE_JAVA_RTX, according to simon
07i,27jan99,jco  merged from graphics2_0 branch
07h,19nov98,sn   added entries for C++ macros that are excluded by default
07h,01dec98,spm  added INCLUDE_ARP for automatic linking of API (SPR #7576)
07g,27oct98,ms   made INCLUDE_CPLUS the default
07f,25aug98,tpr  added PowerPC EC 603 support.
07o,01sep98,drm  added INCLUDE_WINDMP
07n,17apr98,nps  added INCLUDE_RBUFF.
07m,04mar97,jmb  must have HW_FP for HPSIM.
07l.28jan98,cth  removed WV_DEFAULT_ definitions
07k.18dec97,cth  reworked defines for WV 2.0, removed INCLUDE_INSTRUMENTATION
07j.20aug97,cth  added INCLUDE_WDB_TSFS option
07i,09mar98,sjw  added Java macros for conflict resolution
07h,26jun97,ics  added INCLUDE_HTTP (for Wind Web Server)
07g,02jun97,tcy  added support for WILLOWS RT
07o,04may98,cym  added SIMNT.
07n,29apr98,dbt  removed RDB referencies (no longer supported).
07m,19mar98,dbt  added INCLUDE_WDB_START_NOTIFY and INCLUDE_WDB_USER_EVENT.
07l,18mar98,jmb  HPSIM merge:  must have hardware FP
07k,11mar98,pdn  added WDB_COMM_PIPE (for VxSims)
07i,24nov97,jpd  changed VM_PAGE_SIZE for ARM family.
07f,06oct97,spm  added BSD43_COMPATIBLE define (optional binary compatibility).
07e,26aug97,spm  added defines for DHCP port selection
07d,15jul97,spm  added support for SNTP client and server
07c,03jul97,vin  added INCLUDE_ROUTE_SOCK
07b,03jul97,sgv  added INCLUDE_FTPD_SECURITY to fix spr #8602
07a,28apr97,spm  added DHCP_MAX_HOPS from dhcprLib.h
06w,02feb98,dbt  added INCLUDE_WDB_EVENTPOINTS to support WDB eventpoints.
06v,10dec97,spm  added INCLUDE_FTPD_SECURITY to support configurable password
                 authentication for FTP server (SPR #8602)
06u,04feb96,ms   added WDB support for NetROM 500 series.
06z,17apr97,vin  added INCLUDE_IP_FILTER.
06y,10apr97,jag  added support for DNS resolver.
06x,07arp97,vin  added INCLUDE_MCAST_ROUTING
06w,07apr97,spm  added support for DHCP server and relay agent
06v,07apr97,gnn  removed bogus RIP defaults
06u,14feb97,rjc  added OSPF_INCLUDE dfine for ospf routing
06t,29jan97,spm  added DHCPC_MIN_LEASE define and changed DHCPC_DEFAULT_LEASE. 
06s,11jan97,vin  reorganized network related includes.
06r,04dec96,gnn  added RIP and DHCP defines.
06q,28aug96,gnn	 added WDB_COMM_END define.
06u,28nov96,cdp  added ARM support.
06t,03dec96,dbt  removed #ifdef INCLUDE_ANSI_ALL and #ifdef INCLUDE_MIB2_ALL 
		 (moved in usrDepend.c).
06s,15nov96,jag  changed string associated with MIB2_SYS_DESCR (SPR# 7476)
06r,04oct96,elp  added INCLUDE_SYM_TBL_SYNC (SPR# 6775).
06q,09aug96,dbt  Moved the ifdef INCLUDE_POSIX_ALL to usrDepend.c (SPR #5524).
06p,29jul96,ms   reworked the fix for SPR #5603.
06o,24jul96,ism  hand-merged SIMSOLARIS.
06n,19jul96,dbt  Moved the ifdef INCLUDE_CONFIGURATION_5_2 
		 to usrDepend.c (SPR #5603).
06m,11jul96,jmb  Eliminated alternative WDB macros names.  SPR #5707
06l,21jun96,jmb  long modhist -- deleted entries prior to 1994.  SPR #6528
06k,20jun96,tpr  added PowerPC 860 support.
06j,18jun96,dbt  removed line INCLUDE_ADA (spr 6645)
06i,10jun96,tam  changed STACK_RESIDENT to RAM_DST_ADRS for PPC
06j,16oct96.rjc  deleted snmp memory partition defines
06j,12aug96.rjc  changes for snmpdMemoryAlloc changes
06i,22apr96,kkk	 fixed typo on CPU_FAMILY for PPC (SPR# 6385)
06h,04apr96,rjc  Modifications for snmp v1 agent for 5.3
06g,07mar96,dat  WDB comm config can be specified on make command line
06f,05mar96,tpr  Added RESERVED for PowerPC.
06e,04dec95,vin  increased EVT_STACK_SIZE to 7000.
06d,06sep95,jag  deleted unnecessary STREAMS defines.
06c,01aug95,dzb  renamed STREAMS macros.  Added STREAMS_PROTO_INIT_RTN macro.
06b,28jul95,jag  Changed INCLUDE_STREAMS_LOG to INCLUDE_STREAMS_STRACE and
		 INCLUDE_STREAMS_STERR. Changed STREAMS_LOG_CONFIG_DIR to
		 STREAMS_STRERR_OUTPUT_DIR and STREAMS_STRACE_OUTPUT_DIR
06a,26jul95,dzb  adjusted default socket macro for STREAMS.
05z,25jul95,dzb  added INCLUDE_BSD_SOCKET and DEFAULT_XXX_SOCKET.
05y,18jul95,dzb  added PPP_CONNECT_DELAY.
05x,11jul95,dzb  modified INCLUDE_PPP inclusion.
05w,26jun95,dzb  removed PPP_OPT_USEHOSTNAME option.
05v,22jun95,sgv  Added STREAMS support
05u,21jun95,dzb  Added INCLUDE_PPP_CRYPT for unbundled crypt() support.
05t,20jun95,dzb  added PPP support.
06e,23sep95,tpr  changed VM_PAGE_SIZE for PPC family.
06d,19jun95,caf  additional PPC support.
06e,11oct95,ms   made 5.2 configuration easier to recreate (SPR #5134).
06d,10oct95,dat	 backward compatible BSP_VERSION and BSP_REV
06c,28sep95,dat	 new #define INCLUDE_WDB_ANNOUNCE
06b,21sep95,ms	 switched some WDB macros between here and usrWdb.c
06a,27jun95,ms	 renamed WDB_COMM_XXX macros
05z,21jun95,ms	 added INCLUDE_WDB_TTY_TEST and INCLUDE_WDB_EXIT_NOTIFY
05y,21jun95,tpr  added #define INCLUDE_WDB_MEM.
05x,13jun95,srh  Updated C++ support triggers.
05w,07jun95,ms	 WDB_STACK_SIZE is now CPU dependant.
05v,07jun95,p_m  added INCLUDE_FORMATTED_IO. suppressed spy from default
                 configuration.
05u,01jun95,ms	 all WDB macros start with WDB_ (usrWdb.c modhist has details).
05t,22may95,ms   added WDB agent support.
          + p_m  suppressed shell, symbol table and debug support from default
		 configuration.
05s,29mar95,kdl  added INCLUDE_GCC_FP.
05r,28mar95,kkk  added scalability MACROS, changed edata and end to arrays 
		 (SPR #3917), added misc constants SM_PKTS_SIZE and 
		 SM_CPUS_MAX (SPR #4130), added misc constant CONSOLE_BAUD_RATE
05q,24mar95,tpr  added #define USER_B_CACHE_ENABLE (SPR #4168). 
05p,14mar95,caf  restored mips resident rom support (SPR #3856).
05o,18jan95,tmk  Added MC68060 case for HW_FP
06c,25may95,yao  changed to use _end for FREE_MEM_ADRS for PowerPC.
06b,12jan95,caf  added PPC floating point support.
06a,09jan95,yao  added PPC support.
05n,10dec94,kdl  Moved INCLUDE_POSIX_ALL to unincluded (SPR 3822).
05m,10dec94,caf  undid mod 05a, use _sdata for resident roms (SPR #3856).
05l,09dec94,jag  Added INCLUDE_MIB2_AT.
05k,17nov94,kdl  Added INCLUDE_NFS_SERVER (excluded); removed TRON references.
05j,13nov94,dzb  Moved INCLUDE_PING to excluded.
05i,11nov94,dzb  Added ZBUF_SOCK, TCP_DEBUG, and PING defines.
05h,11nov94,jag  cleanup of SNMP and MIB defines.
05g,04nov94,kdl	 initial merge cleanup.
04x,20jul94,ms   changed INCLUDE_HPPA_OUT to INCLUDE_SOM_COFF
05d,11apr94,jag  Removed conditions for definition of  NFS_GROUP and NFS_USER
		 ID for SNMP demo support.
05c,18feb94,elh  (SNMP VERSION) moved INCLUDE_POSIX_ALL to false section.
		 Added support for the mib2 library.
05f,25may94,kdl	 (POSIX VERSION) removed erroneous NFS def's.
05e,23mar94,smb	 (POSIX VERSION) removed PASSIVE_MODE
05d,15mar94,smb	 renamed tEvtTask parameters.
05c,15feb94,smb	 added define of WV_MODE
05b,12jan94,kdl	 (POSIX VERSION) turned off instrumentation, added 
		 INCLUDE_POSIX_ALL; added INCLUDE_POSIX_SIGNALS; changed
		 INCLUDE_POSIX_MEM_MAN to INCLUDE_POSIX_MEM; added
		 NUM_SIGNAL_QUEUES.
*/

/*
DESCRIPTION
This header contains the parameters that define the default
configuration for VxWorks.
*/

#ifndef	INCconfigAllh
#define	INCconfigAllh

#define NUM_FILES	400


#endif	/* INCconfigAllh */
