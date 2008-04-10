//*********************************************************************************  
//
//	File:				Framework  
//	
//	Componentized Combat System Testbed Framework IR&D    
//	Copyright 2008, Johns Hopkins University / Applied Physics Laboratory (JHU/APL)
//	
//	
//	Created By: 		rosskw1  
//
//!	Date of createion:	Thu, 14, Feb 2008     
//
//	Description:		  
//
//**********************************************************************************



#ifndef Framework_H 

#define Framework_H 

#include <oxf/oxf.h>
#include <string>
#include <algorithm>

//----------------------------------------------------------------------------
// Framework.h                                                                  
//----------------------------------------------------------------------------

//## package Framework 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif


namespace Framework {
    
    //## type FederateType 
    enum FederateType {
        SSDS,
        CEC
    };
    
    //## type FrameworkMessage 
    struct FrameworkMessage {};
    
    // Returned in "getType" function in class "Federate I/O Handler.  I believe that this is the Message Type to be passed by the I/O Handler.
    //## type MessageType 
    enum MessageType {};
    
    //## type FederateFrameworkType 
    enum FederateFrameworkType {
        HLA_FederateFrameworkType,
        OASIS_FederateFrameworkType
    };
    
    
    
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Framework.h
*********************************************************************/

