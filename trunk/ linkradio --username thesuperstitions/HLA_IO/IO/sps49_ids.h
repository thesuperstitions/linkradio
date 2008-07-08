#ifndef SPS49_IDS_H
#define SPS49_IDS_H

/*
* Developed by The Johns Hopkins University/Applied Physics Laboratory (JHU/APL)
*
*
*/

/* static char sps49_ids_h_rcsid[] = "$Header: /ceswbl2/src/include/RCS/sps49_ids.h,v 6.34.0.1 2007/10/19 14:23:24 ceswbl2 Exp $"; */


/* 
	*
	*	Project:	CEP WASP CES BL2
	*
	*	File name:	sps49_ids.h
	*
	*	Description:	Input/Output message data structures for SPS-49
	*			radar simulation module
	*
	*	Used By:	SPS-49 radar simulation modules
	*
	*	Programmer:	Nancy Alice Vaughn
	*	Date Created:	14 November 1992
	*
	*	Host System:    SunOS Release 4.1.3_U1
	*	Target System:	VxWorks
	*	Language:	C
	*
	*	Modifications:
	*		$Log: sps49_ids.h,v $
	*		Revision 6.34.0.1  2007/10/19 14:23:24  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.34  2007/10/18 18:23:21  ceswbl2
	*		CESWBL2_6_34_OCT_18_07
	*
	*		Revision 6.33.0.2  2007/10/12 11:15:01  tallman
	*		Removed notices.  IAW TR#2677
	*
	*		Revision 6.33.0.1  2007/04/24 16:25:40  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.33  2007/04/23 16:57:24  ceswbl2
	*		CESWBL2_6_33_APR_23_07
	*
	*		Revision 6.32.0.1  2006/10/26 16:01:33  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.32  2006/10/25 17:20:00  ceswbl2
	*		CESWBL2_6_32_OCT_25_06
	*
	*		Revision 6.31.0.1  2006/04/14 14:46:29  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.31  2006/04/13 19:04:38  ceswbl2
	*		CESWBL2_6_31_APR_14_06
	*
	*		Revision 6.30.0.1  2005/10/12 16:49:46  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.30  2005/10/11 20:13:35  ceswbl2
	*		CESWBL2_6_30_OCT_12_05
	*
	*		Revision 6.29.0.1  2004/12/03 14:30:49  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.29  2004/12/02 19:21:31  ceswbl2
	*		CESWBL2_6_29_DEC_03_04
	*
	*		Revision 6.28.0.1  2004/06/11 14:12:37  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.28  2004/06/10 18:49:42  ceswbl2
	*		CESWBL2_6_28_JUN_11_04
	*
	*		Revision 6.27.0.1  2003/12/17 17:52:59  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.27  2003/12/16 21:03:12  ceswbl2
	*		CESWBL2_6_27_DEC_17_03
	*
	*		Revision 6.26.0.1  2003/08/14 18:44:24  cwbl2tst
	*		Making_Branches
	*
	*		Revision 6.26  2003/08/13 20:06:48  ceswbl2
	*		CESWBL2_6_26_AUG_13_03
	*
	*		Revision 6.25.0.1  2003/04/04 17:33:56  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.25  2003/04/03 21:36:18  ceswbl2
	*		CESWBL2_6_25_APR_03_03
	*
	*		Revision 6.24.0.1  2002/12/18 18:09:06  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.24  2002/12/13 19:08:29  ceswbl2
	*		CESWBL2_6_24_DEC_13_02
	*
	*		Revision 6.23.0.1  2002/09/06 15:04:27  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.23  2002/09/05 20:44:06  ceswbl2
	*		CESWBL2_6_23_SEP_05_02
	*
	*		Revision 6.22.0.1  2002/02/22 15:26:35  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.22  2002/02/20 21:57:01  ceswbl2
	*		CESWBL2_6_22_FEB_20_02
	*
	*		Revision 6.21.0.1  2001/08/03 15:19:45  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.21  2001/08/02 20:15:22  ceswbl2
	*		CESWBL2_6_21_AUG_02_01
	*
	*		Revision 6.20.0.1  2001/05/09 18:47:36  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.20  2001/05/08 20:17:57  ceswbl2
	*		CESWBL2_6_20_MAY_08_01
	*
	*		Revision 6.19.0.1  2001/02/22 16:05:23  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.19  2001/02/21 22:04:22  ceswbl2
	*		CESWBL2_6_19_FEB_21_01
	*
	*		Revision 6.18.0.1  2000/11/10 17:36:34  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.18  2000/11/09 21:21:15  ceswbl2
	*		CESWBL2_6_18_NOV_09_00
	*
	*		Revision 6.17.0.1  2000/09/08 15:29:48  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.17  2000/09/07 21:11:10  ceswbl2
	*		CESWBL2_6_17_SEPT_07_00
	*
	*		Revision 6.16.0.2  2000/09/05 13:14:08  twhite
	*		Changes made for SPS49 Simulation Rewrite, IAW TR #1001.
	*
	*		Revision 6.16.0.1  2000/06/16 15:36:26  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.16  2000/06/15 21:20:25  ceswbl2
	*		CESWBL2_6_16_JUN_15_00
	*
	*		Revision 6.15.0.1  2000/04/13 14:38:04  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.15  2000/04/12 19:55:26  ceswbl2
	*		CESWBL2_6_15_APR_12_00
	*
	*		Revision 6.14.0.1  2000/01/28 15:58:21  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.14  2000/01/27 20:57:34  cwbl2adm
	*		CESWBL2_6_14_JAN_27_00
	*
	*		Revision 6.13.0.1  1999/10/21 17:29:48  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.13  1999/10/20 20:13:51  ceswbl2
	*		CESWBL2_6_13_OCT_20_99
	*
	*		Revision 6.12.0.1  1999/06/24 12:57:06  ceswbl2
	*		Making_Branches
	*
	*		Revision 6.12  1999/06/22 20:58:43  ceswbl2
	*		CESWBL2_6_12_JUN_22_99
	*
	*		Revision 6.11.0.1  1999/03/30 17:25:40  ceswbl2
	*		Making_Branches
	*
	* Revision 6.11  1999/03/29  20:21:36  ceswbl2
	* CESWBL2_6_11_MAR_29_99
	*
	* Revision 6.10.0.1  1999/02/09  17:06:07  ceswbl2
	* Making_Branches
	*
	* Revision 6.10  1999/02/08  20:12:14  ceswbl2
	* CESWBL2_6_10_FEB_08_98
	*
	* Revision 6.9.0.2  1998/11/17  18:52:52  richie
	* correct scaling for SPS-49 Radar brg to be S15 (not S16) IAW TR# 468
	*
	* Revision 6.9.0.1  1998/11/06  14:05:25  ceswbl2
	* Making_Branches
	*
	* Revision 6.9  1998/11/05  19:58:15  ceswbl2
	* CESWBL2_6_9_NOV_05_98
	*
	* Revision 6.8.0.1  1998/09/03  15:43:14  ceswbl2
	* Making_Branches
	*
	* Revision 6.8  1998/09/02  20:11:44  ceswbl2
	* CESWBL2_6_8_SEPT_02_98
	*
	* Revision 6.7.0.2  1998/07/24  18:03:50  dbocek
	* Commenting out rcsid strings to avoid unused compiler warning,
	* iaw TR #315.
	*
	* Revision 6.7.0.1  1998/06/18  16:10:21  ceswbl2
	* Making_Branches
	*
	* Revision 6.7  1998/06/16  21:18:08  ceswbl2
	* CESWBL2_6_7_JUN_16_98
	*
	* Revision 6.6.0.1  1998/05/11  18:43:49  ceswbl2
	* Making_Branches
	*
	* Revision 6.6  1998/05/08  18:23:38  ceswbl2
	* CESWBL2_6_6_MAY_8_98
	*
	* Revision 6.5.0.1  1998/03/18  16:04:49  ceswbl2
	* Making_Branches
	*
	* Revision 6.5  1998/03/17  20:57:18  ceswbl2
	* CESWBL2_6_5_MAR_17_98
	*
	* Revision 6.4.0.1  1998/01/14  14:17:20  ceswbl2
	* Making_Branches
	*
	* Revision 6.4  1998/01/13  21:00:31  ceswbl2
	* CESWBL2_6_4_JAN_13_98
	*
	* Revision 6.3.0.1  1997/11/20  21:35:22  ceswbl2
	* Making_Branches
	*
	* Revision 6.3  1997/11/19  21:09:00  ceswbl2
	* CESWBL2_6_3_NOV_19_97
	*
	* Revision 6.2.0.2  1997/10/24  13:41:29  richie
	* define R49_WRAP_TEST_RESP_STRUCT
	*
	* Revision 6.2.0.1  1997/10/08  14:19:54  ceswbl2
	* Making_Branches
	*
	* Revision 6.2  1997/10/07  20:45:24  ceswbl2
	* CESWBL2_6_2_OCT_07_97
	*
	* Revision 6.1.0.1  1997/09/12  16:51:15  ceswbl2
	* Making_Branches
	*
	* Revision 6.1  1997/09/12  14:25:49  ceswbl2
	* CESWBL2_6_1_SEP_12_97
	*
	*
	*
	*
	*/


/******************************************************************************/
/*    Define the MAXIMUM sizeof the various NTDS message structure areas     */

#define R49MAXRPC 7     /*  Maximum Number of RPC Gates in Message            */
#define R49MAXEMC 4     /*  Maximum Number of EMC Gates in Message            */
#define R49MAXSMC 7     /*  Maximum Number of SMC Gates in Message            */
#define R49MAXTGT 15    /*  Maximum Number of TGT Gates in Message            */
#define R49MAXWRT 1     /*  Maximum Number of Wrap Test in Message            */
#define R49MAXTTG 2     /*  Maximum Number of Test Targets in Message         */
#define R49MAXSHH 1     /*  Maximum Number of Ship Headings in Message        */
#define R49MAXSYC 1     /*  Maximum Number of System Controls in Message      */
/******************************************************************************/


typedef struct            /* R49_NTDS_HDR_STRUCT */
{
		unsigned short
			num_wrds,     /*            Number of words in message            */
			msg_type;     /*                  Type of message                 */

}	R49_NTDS_HDR_STRUCT;




/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
/*$$$$  Structures of messages received by the SPS-49(V) Sensor Processing  $$*/
/*$$$$$$                Function from the SPS-49(V)5 Radar              $$$$$$*/



/*******************************************************************************

*  49 RADAR DATA MESSAGE STRUCTURE       ---NTDS Input Message Type = 0008h    *
* - Receiver     : SPS-49(V)5 I/F : I/O CONTROL & MONITOR FUNCTION             *
* - Response to  : SPS-49(V)5 I/F : RADAR STATUS PROCESSING FUNCTION to report *
*                  radar data message information.                             * 
*******************************************************************************/

typedef struct            /* R49_RADAR_DATA_MSG_STRUCT */
{
			unsigned short
							/*              Radar Data Message Word # 1         */
			msg_id   :4,  /*               "Message ID" bits  "1000"          */
			spare1   :5,  /*                      "Spare" bits                */
			ecm_lvl  :7;  /*            "ECM Level" at Bearing (s1) db        */

			unsigned short
							/*              Radar Data Message Word # 2         */
			zero_bit1:1,  /*                  "Always Zero" bit               */
			rad      :1,  /*             "Radiation On" 1=on,0=off            */
			cslc     :1,  /*          "Coho Side Lobe Canc" 1=on,0=off        */
			fa       :1,  /*           "Frequency Agility" 1=on,0=off         */
			slb      :1,  /*           "Side Lobe Blanking" 1=on,0=off        */
			stc      :1,  /*           "Sens Time Constant" 1=on,0=off        */
			rpm      :2,  /*         "RPM Indicator" 00=still,01=lo,10=hi     */
			ppfa     :1,  /*  "Pulse to Pulse Frequency Agility" 1=on,0=off   */
			sm       :2,  /*             "Sector Mode" 01=LR,10=AC            */
			spare2   :4,  /*                        "spares"                  */
			gor      :1;  /*          "Gated Only Reports" 1=gated,0=all      */

			unsigned short
							/*              Radar Data Message Word # 3         */
			zero_bit2:1,  /*                  "Always Zero" bit               */
			spare3   :7,  /*                      "Spare" bits                */
			det_rng  :8;  /*            "Radar Detection Range" (s0) rmi      */


			unsigned short
							/*              Radar Data Message Word # 4         */
			zero_bit3:1,  /*                  "Always Zero" bit               */
			ant_elev :15; /*            "Antenna Elevation" (s15) bams        */

			unsigned short
							/*              Radar Data Message Word # 5         */
			zero_bit4:1,  /*                  "Always Zero" bit               */
			time_ind :2,  /*              "Delta Time Index" (0-3)            */
			del_time :13; /*             "Delta time" (s0) millsec's          */

			unsigned short
							/*              Radar Data Message Word # 6         */
			zero_bit5:1,  /*                  "Always Zero" bit               */
			sh_pit   :15; /*              "Ships Pitch" (s15) bams            */

			unsigned short
							/*              Radar Data Message Word # 7         */
			zero_bit6:1,  /*                  "Always Zero" bit               */
			sh_roll  :15; /*              "Ships Roll" (s15) bams             */

			unsigned short
							/*              Radar Data Message Word # 10        */
			zero_bit7:1,  /*                  "Always Zero" bit               */
			sh_hdg   :15; /*              "Ships Heading" (s15) bams          */

			unsigned short
							/*              Radar Data Message Word # 11        */
			zero_bit8:1,  /*                  "Always Zero" bit               */
			rdr_brg  :15; /*          "Current Radar Bearing" (s15) bams      */

			unsigned short
							/*              Radar Data Message Word # 12        */
			zero_bit9:1,  /*                  "Always Zero" bit               */
			sh_spd   :15; /*               "Ships Speed"(s7) knots            */

}        R49_RADAR_DATA_MSG_STRUCT;

typedef struct            /* R49_MPU_RADAR_DATA_MSG_STRUCT */
{
			unsigned short
							/*              Radar Data Message Word # 1         */
			msg_id   :4,  /*               "Message ID" bits  "1000"          */
			spare1   :5,  /*                      "Spare" bits                */
			ecm_lvl  :7;  /*            "ECM Level" at Bearing (s1) db        */

			unsigned short
							/*              Radar Data Message Word # 2         */
			zero_bit1:1,  /*                  "Always Zero" bit               */
			rad      :1,  /*             "Radiation On" 1=on,0=off            */
			cslc     :1,  /*          "Coho Side Lobe Canc" 1=on,0=off        */
			fa       :1,  /*           "Frequency Agility" 1=on,0=off         */
			slb      :1,  /*           "Side Lobe Blanking" 1=on,0=off        */
			spare2   :1,  /*                        "spares"                  */
			rpm      :2,  /*         "RPM Indicator" 00=still,01=lo,10=hi     */
			spare3   :5,  /*                        "spares"                  */
			mcm      :3;  /*          "Moving Channel Clutter Map" 0/3/7      */

			unsigned short
							/*              Radar Data Message Word # 3         */
			zero_bit2:1,  /*                  "Always Zero" bit               */
			delay    :7,  /*            "Process Delay" (s11) bams            */
			det_rng  :8;  /*            "Radar Detection Range" (s0) rmi      */


			unsigned short
							/*              Radar Data Message Word # 4         */
			zero_bit3:1,  /*                  "Always Zero" bit               */
			ant_elev :15; /*            "Antenna Elevation" (s15) bams        */

			unsigned short
							/*              Radar Data Message Word # 5         */
			zero_bit4:1,  /*                  "Always Zero" bit               */
			time_ind :2,  /*              "Delta Time Index" (0-3)            */
			del_time :13; /*             "Delta time" (s0) millsec's          */

			unsigned short
							/*              Radar Data Message Word # 6         */
			zero_bit5:1,  /*                  "Always Zero" bit               */
			sh_pit   :15; /*              "Ships Pitch" (s15) bams            */

			unsigned short
							/*              Radar Data Message Word # 7         */
			zero_bit6:1,  /*                  "Always Zero" bit               */
			sh_roll  :15; /*              "Ships Roll" (s15) bams             */

			unsigned short
							/*              Radar Data Message Word # 10        */
			zero_bit7:1,  /*                  "Always Zero" bit               */
			sh_hdg   :15; /*              "Ships Heading" (s15) bams          */

			unsigned short
							/*              Radar Data Message Word # 11        */
			zero_bit8:1,  /*                  "Always Zero" bit               */
			rdr_brg  :15; /*          "Current Radar Bearing" (s15) bams      */

			unsigned short
							/*              Radar Data Message Word # 12        */
			zero_bit9:1,  /*                  "Always Zero" bit               */
			sh_spd   :15; /*               "Ships Speed"(s7) knots            */

}        R49_MPU_RADAR_DATA_MSG_STRUCT;


/*******************************************************************************

*  49 CONTACT DATA MESSAGE STRUCTURE     ---NTDS Input Message Type = 0009h    *
* - Receiver     : SPS-49(V)5 I/F : CONTACT PROCESSING FUNCTION                *
* - Response to  : SPS-49(V)5 I/F : I/O CONTROL & MONITOR FUNCTION to report   *
*                  contact data message information.                           * 
*******************************************************************************/

typedef struct            /* R49_CONTACT_DATA_MSG_STRUCT */
{
			unsigned short
							/*          Contact Data Message Word # 1           */
			msg_id   :4,  /*            "Message ID" bits "1001"              */
			rc       :2,  /*             "Report Channel" bits                */
			si       :3,  /*         "Sensitivity Increment" bits             */
			vt       :1,  /*            "Varience Threshold" bit              */
			tt       :1,  /*              "Test Target" bit                   */
			tgt      :1,  /*            "Target Gate Tag"  bit                */
			cnt_env  :4;  /*          "Contact Environment" bits              */

			unsigned short
							/*           Contact Data Message Word # 2          */
			zero_bit1:1,  /*                 "Always Zero" bit                */
			cnt_lnl  :7,  /*          "Local Noise Level" bits (s1)db         */
			dcd      :1,  /*            "Dual Channel Detection" bit          */
			cnt_amp  :7;  /*          "Contact Amplitude" bits (s1)db         */

			unsigned short
							/*           Contact Data Message Word # 3          */
			zero_bit2:1,  /*                 "Always Zero" bit                */
			spare1   :2,  /*                   "Spare" bits                   */
			cnt_rng  :13; /*           "Contact Range" bits (s5)rmi           */

			unsigned short
							/*           Contact Data Message Word # 4          */
			zero_bit3:1,  /*                 "Always Zero" bit                */
			spare2   :2,  /*                    "Spare" bits                  */
			cnt_brg  :13; /*         "Contact Bearing" bits (s13)bams         */

			unsigned short
							/*           Contact Data Message Word # 5          */
			zero_bit4:1,  /*                 "Always Zero" bit                */
			cnt_ext  :5,  /*          "Contact Extent" bits (s9)bams          */
			spare3   :2,  /*                    "Spare" bits                  */
			ce       :1,  /*             "Environment Censor" bit             */
			ecm_lvl  :7;  /*              "ECM Level" bits (s1)db             */

}        R49_CONTACT_DATA_MSG_STRUCT;


typedef struct            /* R49_MPU_CONTACT_DATA_MSG_STRUCT */
{
			unsigned short
							/*          Contact Data Message Word # 1           */
			msg_id   :4,  /*            "Message ID" bits "1001"              */
			rc       :2,  /*             "Report Channel" bits                */
			spare1   :1,  /*                     spare                        */
			si       :2,  /*         "Sensitivity Increment" bits             */
			spare2   :1,  /*                     spare                        */
			tt       :1,  /*              "Test Target" bit                   */
			tgt      :1,  /*            "Target Gate Tag"  bit                */
			co       :1,  /*            "Censor Override" bit                 */
			sa       :1,  /*             "Special Alert" bit                  */
			cnt_env  :2;  /*          "Contact Environment" bits              */

			unsigned short
							/*           Contact Data Message Word # 2          */
			zero_bit1:1,  /*                 "Always Zero" bit                */
			cnt_lnl  :7,  /*          "Local Noise Level" bits (s1)db         */
			dcd      :1,  /*            "Dual Channel Detection" bit          */
			cnt_amp  :7;  /*          "Contact Amplitude" bits (s1)db         */

			unsigned short
							/*           Contact Data Message Word # 3          */
			zero_bit2:1,  /*                 "Always Zero" bit                */
			spare3   :2,  /*                   "Spare" bits                   */
			cnt_rng  :13; /*           "Contact Range" bits (s5)rmi           */

			unsigned short
							/*           Contact Data Message Word # 4          */
			zero_bit3:1,  /*                 "Always Zero" bit                */
			spare4   :2,  /*                    "Spare" bits                  */
			cnt_brg  :13; /*         "Contact Bearing" bits (s13)bams         */

			unsigned short
							/*           Contact Data Message Word # 5          */
			zero_bit4:1,  /*                 "Always Zero" bit                */
			cnt_ext  :5,  /*          "Contact Extent" bits (s9)bams          */
			spare5   :3,  /*                    "Spare" bits                  */
			ecm_lvl  :7;  /*              "ECM Level" bits (s1)db             */

			unsigned short
							/*           Contact Data Message Word # 6          */
			zero_bit5:1,  /*                 "Always Zero" bit                */
			qual     :3,  /*     "Radial Velocity Estimate Quality" bits      */
			best     :12; /*  "Best Estimate Radial Velocity" bits (s-1) DH   */

			unsigned short
							/*           Contact Data Message Word # 7          */
			zero_bit6:1,  /*                 "Always Zero" bit                */
	    spare6   :2,  /*                       spare                      */
			rej      :1,  /*                "SVC Rejected" bit                */
			second   :12; /* "Second Estimate Radial Velocity" bits (s-1) DH  */

			unsigned short
							/*           Contact Data Message Word # 10         */
			zero_bit7:1,  /*                 "Always Zero" bit                */
	    nae	     :3,  /*           "Number of Accepted Events"            */
	    spare7   :3,  /*                       spare                      */
			xsection :9;  /*           "Cross Section" bits (s1) dBsm         */
						  /*        MSB is a sign bit so range = +/- 127.   */


			unsigned short
							/*           Contact Data Message Word # 11         */
			zero_bit8:1,  /*                 "Always Zero" bit                */
	    spare8   :7,  /*                       spare                      */
			dev_sec  :4,  /*   "Deviation Secondary Estimate" bits (s0) DH    */
			dev_best :4;  /*     "Deviation Best Estimate" bits (s0) DH       */

}        R49_MPU_CONTACT_DATA_MSG_STRUCT;


/*******************************************************************************

*  49 JAM STROBE MESSAGE STRUCTURE       ---NTDS Input Message Type = 000Ah    *
* - Receiver     : SPS-49(V)5 I/F : RADAR STATUS PROCESSING FUNCTION           *
* - Response to  : SPS-49(V)5 I/F : I/O CONTROL & MONITOR FUNCTION to report   *
*                  jam strobe data information.                                * 
*******************************************************************************/

typedef struct            /* R49_JAM_STROBE_MSG_STRUCT */
{
			unsigned short
							/*            Jam Strobe Message Word # 1           */
			msg_id   :4,  /*             "Message ID" bits  "1010"            */
			spare1   :5,  /*                  "Spare" bits                    */
			jam_lvl  :7;  /*              "Jam Level" bits (s1)db             */

			unsigned short
							/*            Jam Strobe Message Word # 2           */
			zero_bit1:1,  /*                "Always Zero" bit                 */
			spare2   :2,  /*                  "Spare" bits                    */
			jam_brg  :13; /*          "Strobe Bearing" bits (s13)bams         */

}        R49_JAM_STROBE_MSG_STRUCT;




/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
/*$$$$   Structures of messages sent to the SPS-49(V)5 Radar by the       $$$$*/
/*$$$$$$               SPS-49(V) Sensor Processing Function             $$$$$$*/



/*******************************************************************************

*  49 RPC GATE STRUCTURE                                                       *
* - Receiver     : SPS-49(V)5 I/F : I/O CONTROL & MONITOR FUNCTION             *
* - Response to  : SPS-49(V)5 I/F : RADAR CONTROL FUNCTION sending the RPC     *
*                  gate data information.                                      * 
*******************************************************************************/

typedef struct            /* R49_RPC_GATE_STRUCT */
{
			unsigned short
							/*$$$$$$$$    RPC Gate Message Word # 1     $$$$$$$$*/

			frst_bit :1,  /* Bit 15    = Message 1st Word ID bit = 1          */
			rpcgt    :3,  /* Bit 14>12 = Radar Processing Control Gate Tag    */
						:3,  /* Bit 11>09 = Spare                                */
			lv       :1,  /* Bit 08    = Low Velocity Enable                  */
			vtd      :1,  /* Bit 07    = Variance Threshold Disable           */
			st       :1,  /* Bit 06    = Surface Target Enable                */
			so       :3,  /* Bit 05>03 = Sensitivity Override                 */
			vi       :3;  /* Bit 02>00 = Video Override                       */

			unsigned short   /*$$$$$$$$    RPC Gate Message Word # 2     $$$$$$$$*/

			zero_bit1:1,  /* Bit 15    = Message 2nd Word ID bit = 0          */
			start_brg:7,  /* Bit 14>08 = Start Bearing                        */
			start_rng:8;  /* Bit 07>00 = Start Range                          */

			unsigned short   /*$$$$$$$$    RPC Gate Message Word # 3     $$$$$$$$*/

			zero_bit2:1,  /* Bit 15    = Message 3rd Word ID bit = 0          */
			stop_brg :7,  /* Bit 14>08 = Stop Bearing                         */
			stop_rng :8;  /* Bit 07>00 = Stop Range                           */

			unsigned short   /*$$$$$$$$    RPC Gate Message Word # 4     $$$$$$$$*/

			zero_bit3:1,  /* Bit 15    = Message 4th Word ID bit = 0          */
						:11, /* Bit 14>04 = Spare                                */
			environ  :4;  /* Bit 03>00 = Environment selected                 */

} R49_RPC_GATE_STRUCT;

typedef struct            /* R49_MPU_RPC_GATE_STRUCT */
{
			unsigned short
							/*$$$$$$$$    RPC Gate Message Word # 1     $$$$$$$$*/

			frst_bit :1,  /* Bit 15    = Message 1st Word ID bit = 1          */
			rpcgt    :3,  /* Bit 14>12 = Radar Processing Control Gate Tag    */
			cen      :1,  /* Bit 11    = Censor Reports                       */
			environ  :2,  /* Bit 10>09 = Environment                          */
			lv       :1,  /* Bit 08    = Low Velocity Enable                  */
						:1,  /* Bit 07    = Spare                                */
			st       :1,  /* Bit 06    = Surface Target Enable                */
			so       :2,  /* Bit 05>04 = Sensitivity Override                 */
						:4;  /* Bit 03>00 = Spare                                */

			unsigned short   /*$$$$$$$$    RPC Gate Message Word # 2     $$$$$$$$*/

			zero_bit1:1,  /* Bit 15    = Message 2nd Word ID bit = 0          */
			start_brg:7,  /* Bit 14>08 = Start Bearing                        */
			start_rng:8;  /* Bit 07>00 = Start Range                          */

			unsigned short   /*$$$$$$$$    RPC Gate Message Word # 3     $$$$$$$$*/

			zero_bit2:1,  /* Bit 15    = Message 3rd Word ID bit = 0          */
			stop_brg :7,  /* Bit 14>08 = Stop Bearing                         */
			stop_rng :8;  /* Bit 07>00 = Stop Range                           */

} R49_MPU_RPC_GATE_STRUCT;


/*******************************************************************************

*  49 EMC GATE STRUCTURE                                                       *
* - Receiver     : SPS-49(V)5 I/F : I/O CONTROL & MONITOR FUNCTION             *
* - Response to  : SPS-49(V)5 I/F : RADAR CONTROL FUNCTION sending the EMC     *
*                  gate data information.                                      * 
*******************************************************************************/

typedef struct            /* R49_EMC_GATE_STRUCT */
{
			unsigned short   /*$$$$$$$$    EMC Gate Message Word # 1     $$$$$$$$*/

			frst_bit :1,  /* Bit 15    = Message 1st Word ID bit = 1          */
			emcgt    :3,  /* Bit 14>12 = Emission Gate Tag                    */
			ec       :3,  /* Bit 11>09 = Emission Code                        */
						:9;  /* Bit 08>00 = Spare                                */

			unsigned short   /*$$$$$$$$    EMC Gate Message Word # 2     $$$$$$$$*/

			zero_bit1:1,  /* Bit 15    = Message 2nd Word ID bit = 0          */
			start_brg:7,  /* Bit 14>08 = Start Bearing                        */
						:1,  /* Bit 07    = spare                                */
			stop_brg :7;  /* Bit 06>00 = Stop Bearing                         */

} R49_EMC_GATE_STRUCT;


/*******************************************************************************

*  49 SMC GATE STRUCTURE                                                       *
* - Receiver     : SPS-49(V)5 I/F : I/O CONTROL & MONITOR FUNCTION             *
* - Response to  : SPS-49(V)5 I/F : RADAR CONTROL FUNCTION sending the SMC     *
*                  gate data information.                                      * 
*******************************************************************************/

typedef struct            /* R49_SMC_GATE_STRUCT */
{
			unsigned short
							/*$$$$$$$$    SMC Gate Message Word # 1     $$$$$$$$*/

			frst_bit :1,  /* Bit 15    = Message 1st Word ID bit = 1          */
			smcgt    :3,  /* Bit 14>12 = Sector Mode Control Gate Tag         */
			ppfa     :1,  /* Bit 11    = Pulse To Pulse Freq Agility Enable   */
			sms      :2,  /* Bit 10>09 = Sector Mode Select                   */
			eur      :1,  /* Bit 08    = Elevation Upspot Request             */
						:3,  /* Bit 07>05 = Spare                                */
			elcom    :5;  /* Bit 04>00 = Elevation Command                    */

			unsigned short   /*$$$$$$$$    SMC Gate Message Word # 2     $$$$$$$$*/

			zero_bit1:1,  /* Bit 15    = Message 2nd Word ID bit = 0          */
			start_brg:7,  /* Bit 14>08 = Start Bearing                        */
						:1,  /* Bit 07    = spare                                */
			stop_brg :7;  /* Bit 06>00 = Stop Bearing                         */

} R49_SMC_GATE_STRUCT;


typedef struct            /* R49_MPU_SMC_GATE_STRUCT */
{
			unsigned short
							/*$$$$$$$$    SMC Gate Message Word # 1     $$$$$$$$*/

			frst_bit :1,  /* Bit 15    = Message 1st Word ID bit = 1          */
			smcgt    :3,  /* Bit 14>12 = Sector Mode Control Gate Tag         */
						:7,  /* Bit 11>05 = Spare                                */
			elcom    :5;  /* Bit 04>00 = Elevation Command                    */

			unsigned short   /*$$$$$$$$    SMC Gate Message Word # 2     $$$$$$$$*/

			zero_bit1:1,  /* Bit 15    = Message 2nd Word ID bit = 0          */
			start_brg:7,  /* Bit 14>08 = Start Bearing                        */
						:1,  /* Bit 07    = spare                                */
			stop_brg :7;  /* Bit 06>00 = Stop Bearing                         */

} R49_MPU_SMC_GATE_STRUCT;


/*******************************************************************************

*  49 SPECIAL ALERTS GATE STRUCTURE                                            *

*******************************************************************************/

typedef struct            /* R49_MPU_SA_GATE_STRUCT */
{
			unsigned short
							/*$$$$$$$$    SA Gate Message Word # 1     $$$$$$$$*/

			frst_bit :1,  /* Bit 15    = Message 1st Word ID bit = 1          */
			sagt     :3,  /* Bit 14>12 = Special Alerts Gate Tag              */
						:6,  /* Bit 11>06 = Spare                                */
			tgo      :6;  /* Bit 05>00 = Time To Go                           */

			unsigned short   /*$$$$$$$$    SA Gate Message Word # 2     $$$$$$$$*/

			zero_bit1:1,  /* Bit 15    = Message 2nd Word ID bit = 0          */
			start_brg:7,  /* Bit 14>08 = Start Bearing                        */
			start_rng:8;  /* Bit 07>00 = Start Range                          */

			unsigned short   /*$$$$$$$$    SA Gate Message Word # 3     $$$$$$$$*/

			zero_bit2:1,  /* Bit 15    = Message 3rd Word ID bit = 0          */
			stop_brg :7,  /* Bit 14>08 = Stop Bearing                         */
			stop_rng :8;  /* Bit 07>00 = Stop Range                           */

} R49_MPU_SA_GATE_STRUCT;


/*******************************************************************************

*  49 TGT GATE STRUCTURE                                                       *
* - Receiver     : SPS-49(V)5 I/F : I/O CONTROL & MONITOR FUNCTION             *
* - Response to  : SPS-49(V)5 I/F : RADAR CONTROL FUNCTION sending the TGT     *
*                  gate data information.                                      * 
*******************************************************************************/

typedef struct            /* R49_TGT_GATE_STRUCT */
{
			unsigned short
							/*$$$$$$$$    TGT Gate Message Word # 1     $$$$$$$$*/

			frst_bit :1,  /* Bit 15    = Message 1st Word ID bit = 1          */
			tgtgt    :5,  /* Bit 14>10 = Target Gate Tag                      */
			vtd      :1,  /* Bit 09    = Variance Threshold Disable           */
			eo       :1,  /* Bit 08    = Emission Override                    */
			lv       :1,  /* Bit 07    = Low Velocity Enable                  */
						:1,  /* Bit 06    = Spare                                */
			st       :1,  /* Bit 05    = Surface Target Enable                */
			env_cen  :1,  /* Bit 04    = Environment Status                   */
			environ  :4;  /* Bit 03>00 = Environment                          */

			unsigned short   /*$$$$$$$$    TGT Gate Message Word # 2     $$$$$$$$*/

			zero_bit1:1,  /* Bit 15    = Message 2nd Word ID bit = 0          */
			so       :3,  /* Bit 14>12 = Sensitivity Override                 */
						:1,  /* Bit 11    = spare                                */
			start_rng:11; /* Bit 10>00 = Start Range                          */

			unsigned short   /*$$$$$$$$    TGT Gate Message Word # 3     $$$$$$$$*/

			zero_bit2:1,  /* Bit 15    = Message 3rd Word ID bit = 0          */
						:4,  /* Bit 14>11 = spare                                */
			stop_rng :11; /* Bit 10>00 = Stop Range                           */

			unsigned short   /*$$$$$$$$    TGT Gate Message Word # 4     $$$$$$$$*/

			zero_bit3:1,  /* Bit 15    = Message 4th Word ID bit = 0          */
			start_brg:7,  /* Bit 14>08 = Start Bearing                        */
						:1,  /* Bit 07    = spare                                */
			stop_brg :7;  /* Bit 06>00 = Stop Bearing                         */

} R49_TGT_GATE_STRUCT;


typedef struct            /* R49_MPU_TGT_GATE_STRUCT */
{
			unsigned short
							/*$$$$$$$$    TGT Gate Message Word # 1     $$$$$$$$*/

			frst_bit :1,  /* Bit 15    = Message 1st Word ID bit = 1          */
			tgtgt    :5,  /* Bit 14>10 = Target Gate Tag                      */
						:1,  /* Bit 09    = Spare				      */
			eo       :1,  /* Bit 08    = Emission Override                    */
			lv       :1,  /* Bit 07    = Low Velocity Enable                  */
						:1,  /* Bit 06    = Spare                                */
			st       :1,  /* Bit 05    = Surface Target Enable                */
						:5;  /* Bit 04>00 = Spare                                */

			unsigned short   /*$$$$$$$$    TGT Gate Message Word # 2     $$$$$$$$*/

			zero_bit1:1,  /* Bit 15    = Message 2nd Word ID bit = 0          */
						:4,  /* Bit 14>11 = Spare                                */
			start_rng:11; /* Bit 10>00 = Start Range                          */

			unsigned short   /*$$$$$$$$    TGT Gate Message Word # 3     $$$$$$$$*/

			zero_bit2:1,  /* Bit 15    = Message 3rd Word ID bit = 0          */
						:4,  /* Bit 14>11 = spare                                */
			stop_rng :11; /* Bit 10>00 = Stop Range                           */

			unsigned short   /*$$$$$$$$    TGT Gate Message Word # 4     $$$$$$$$*/

			zero_bit3:1,  /* Bit 15    = Message 4th Word ID bit = 0          */
			start_brg:7,  /* Bit 14>08 = Start Bearing                        */
						:1,  /* Bit 07    = spare                                */
			stop_brg :7;  /* Bit 06>00 = Stop Bearing                         */

} R49_MPU_TGT_GATE_STRUCT;


/*******************************************************************************

*  49 TEST TARGET STRUCTURE                                                    *
* - Receiver     : SPS-49(V)5 I/F : I/O CONTROL & MONITOR FUNCTION             *
* - Response to  : SPS-49(V)5 I/F : RADAR CONTROL FUNCTION sending the test    *
*                  target data information.                                    * 
*******************************************************************************/

typedef struct            /* R49_TEST_TGT_STRUCT */
{
			unsigned short
							/*$$$$$$$$    TTG Message Word # 1          $$$$$$$$*/

			frst_bit :1,  /* Bit 15    = Message 1st Word ID bit = 1          */
			tt_mode  :3,  /* Bit 14>12 = Test Mode                            */
			back_amp :6,  /* Bit 11>06 = Background Amplitude                 */
			tt_amp   :6;  /* Bit 05>00 = Target Amplitude                     */

			unsigned short   /*$$$$$$$$    TTG Message Word # 2          $$$$$$$$*/

			zero_bit1:1,  /* Bit 15    = Message 2nd Word ID bit = 0          */
			mtc      :1,  /* Bit 14    = Moving Target Channel                */
			fxtc     :1,  /* Bit 13    = Fixed Target Channel                 */
						:2,  /* Bit 12>11 = Spare                                */
			tt_rng   :11; /* Bit 10>00 = Test Target Range                    */

			unsigned short   /*$$$$$$$$    TTG Message Word # 3          $$$$$$$$*/

			zero_bit2:1,  /* Bit 15    = Message 3rd Word ID bit = 0          */
			tt_width :5,  /* Bit 14>10 = Test Target Bearing Width            */
			tt_brg   :10; /* Bit 09>00 = Test Target Bearing Start (s10)bams  */

} R49_TEST_TGT_STRUCT;

typedef struct            /* R49_MPU_TEST_TGT_STRUCT */
{
			unsigned short
							/*$$$$$$$$    TTG Message Word # 1          $$$$$$$$*/

			frst_bit :1,  /* Bit 15    = Message 1st Word ID bit = 1          */
						:2,  /* Bit 14>13 = Spare                                */
			back_amp :6,  /* Bit 12>07 = Background Amplitude                 */
						:1,  /* Bit 06    = Spare                                */
			tt_amp   :6;  /* Bit 05>00 = Target Amplitude                     */

			unsigned short   /*$$$$$$$$    TTG Message Word # 2          $$$$$$$$*/

			zero_bit1:1,  /* Bit 15    = Message 2nd Word ID bit = 0          */
			tt_mode  :2,  /* Bit 14>13 = Test Mode                            */
						:2,  /* Bit 12>11 = Spare                                */
			tt_rng   :11; /* Bit 10>00 = Test Target Range (s3) DM            */

			unsigned short   /*$$$$$$$$    TTG Message Word # 3          $$$$$$$$*/

			zero_bit2:1,  /* Bit 15    = Message 3rd Word ID bit = 0          */
			tt_width :5,  /* Bit 14>10 = Test Target Bearing Width            */
			tt_brg   :10; /* Bit 09>00 = Test Target Bearing Start (s10)bams  */

			unsigned short   /*$$$$$$$$    TTG Message Word # 4          $$$$$$$$*/

			zero_bit3:1,  /* Bit 15    = Message 4th Word ID bit = 0          */
						:2,  /* Bit 14>13 = Spare                                */
			tt_radial:13; /* Bit 12>00 = Test Target Radial Velocity (s0) DH  */

} R49_MPU_TEST_TGT_STRUCT;


/*******************************************************************************

*  49 SYSTEM CONTROL STRUCTURE                                                 *
* - Receiver     : SPS-49(V)5 I/F : I/O CONTROL & MONITOR FUNCTION             *
* - Response to  : SPS-49(V)5 I/F : RADAR CONTROL FUNCTION sending the system  *
*                  control data information.                                   * 
*******************************************************************************/

typedef struct            /* R49_SYS_CTRL_STRUCT */
{
		unsigned short    /*$$$$$$   System Control Message Word # 1   $$$$$$$*/

			msg_id    :4,  /* Bit 15>12 = Message ID bits = "0001"             */
						:11, /* Bit 11>01 = Spare                                */
			tst_enable:1;  /* Bit 00    = Test Enable                          */

		unsigned short    /*$$$$$$   System Control Message Word # 2   $$$$$$$*/

						:16; /* Bit 15>00 = Spare                                */

} R49_SYS_CTRL_STRUCT;


/*******************************************************************************

*  49 SHIPS HEADING STRUCTURE                                                  *
* - Receiver     : SPS-49(V)5 I/F : I/O CONTROL & MONITOR FUNCTION             *
* - Response to  : SPS-49(V)5 I/F : RADAR CONTROL FUNCTION sending the ships   *
*                  heading data information.                                   * 
*******************************************************************************/

typedef struct            /* R49_SHIP_HDG_STRUCT */
{
			unsigned short   /*$$$$  Ships Heading Gate Message Word # 1     $$$$*/

			msg_id   :4,  /* Bit 15>12 = Message ID bits = "0010"             */
						:12; /* Bit 08>00 = Spare                                */

			unsigned short   /*$$$$  Ships Heading Gate Message Word # 2     $$$$*/

			ship_hdg :16; /* Bit 15>00 = Ships Heading (s16)bams              */

} R49_SHIP_HDG_STRUCT;


/*******************************************************************************

*                    49 WRAP-AROUND TEST MESSAGE STRUCTURE                     * 

*******************************************************************************/

typedef struct            /* R49_WRAP_TEST_STRUCT */
{
			unsigned short   /*$$$$  Wrap-Around Test Message Word # 1 $$$$*/

			fwb      :1,  /* Bit 15    = First Word Bit = 1             */
			spare1   :13, /* Bit 14>02 = Spare                          */
			ctr      :2;  /* Bit 01>00 = counter (0 -> 3)               */

			unsigned short   /*$$$$  Wrap-Around Test Message Word # 2 $$$$*/

			rtc_hi   :16; /* Bit 15>00 = Sync time in Milliseconds      */

			unsigned short   /*$$$$  Wrap-Around Test Message Word # 3 $$$$*/

			rtc_lo   :16; /* Bit 15>00 = Sync time in Milliseconds      */

			unsigned short   /*$$$$  Wrap-Around Test Message Word # 4 $$$$*/

			btp1     :16; /* Bit 15>00 = bit test pattern #1            */

			unsigned short   /*$$$$  Wrap-Around Test Message Word # 5 $$$$*/

			btp2     :16; /* Bit 15>00 = bit test pattern #2            */

			unsigned short   /*$$$$  Wrap-Around Test Message Word # 6 $$$$*/

			spare2   :16; /* Bit 15>00 = Spare                          */

} R49_WRAP_TEST_STRUCT;


/*******************************************************************************

*                    49 WRAP-AROUND TEST RESPONSE MESSAGE STRUCTURE            * 

*******************************************************************************/

typedef struct            /* R49_WRAP_TEST_RESP_STRUCT */
{
			unsigned short   /*$$$$  Wrap-Around Test Message Word # 1 $$$$*/

			ur       :1,  /* Bit 15    = Unrequest Response             */
			s8       :1,  /* Bit 14    = Output Transfer Time-Out       */
			s7       :1,  /* Bit 13    = Input Transfer Time-Out        */
			s6       :1,  /* Bit 12    = Output Buffer Overflow         */
			s5       :1,  /* Bit 11    = Input Buffer Overflow          */
			s4       :1,  /* Bit 10    = RTR Count Error                */
			s3       :1,  /* Bit 9     = Illegal EF Sequence            */
			s2       :1,  /* Bit 8     = Illegal EF                     */
			vbn      :4,  /* Bit 7>4   = Valid Buffer Number            */
			s1       :1,  /* Bit 3     = Input Data Dropped             */
			spare1   :3;  /* Bit 2>0   = Spare                          */


			unsigned short   /*$$$$  Wrap-Around Test Message Word # 2 $$$$*/

			spare2   :1,  /* Bit 15    = Spare                          */
			ctr      :2,  /* Bit 14>13 = counter (0 -> 3)               */
			time_delta :13; /* Bit 12>00 = Time Delta in Milliseconds   */

			unsigned short   /*$$$$  Wrap-Around Test Message Word # 3 $$$$*/

			btp1     :16; /* Bit 15>00 = bit test pattern #1            */

			unsigned short   /*$$$$  Wrap-Around Test Message Word # 4 $$$$*/

			btp2     :16; /* Bit 15>00 = bit test pattern #2            */

			unsigned short   /*$$$$  Wrap-Around Test Message Word # 5 $$$$*/

			tpr1     :16; /* Bit 15>00 = test pattern repeatback#1      */

			unsigned short   /*$$$$  Wrap-Around Test Message Word # 6 $$$$*/

			tpr2     :16; /* Bit 15>00 = test pattern repeatback#2      */

			unsigned short   /*$$$$  Wrap-Around Test Message Word # 7 $$$$*/

			spare3   :10, /* Bit 15>6  = Spare                          */
	    detf     :1,  /* Bit 5     = Detection Fault                */
			spare4   :1,  /* Bit 4     = Spare                          */
	    duml     :1,  /* Bit 3     = Dummy Load                     */
	    cs       :1,  /* Bit 2     = Cold Shutdown                  */
	    stao     :1,  /* Bit 1     = Stabilization Off              */
	    he       :1;  /* Bit 0     = Heading Error                  */

} R49_WRAP_TEST_RESP_STRUCT;

#endif SPS49_IDS_H
