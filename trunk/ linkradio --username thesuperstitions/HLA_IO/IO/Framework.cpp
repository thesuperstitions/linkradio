/********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework
//!	Generated Date	: Wed, 21, May 2008  
	File Path	: DefaultComponent\DefaultConfig\framework.cpp
*********************************************************************/

#include "framework.h"
// operation getFrameworkFederateAmbassador() 
#include "FrameworkFederateAmbassador.h"

//----------------------------------------------------------------------------
// framework.cpp                                                                  
//----------------------------------------------------------------------------

//## package framework 
    
static framework::FrameworkFederateAmbassador* frameworkFederateAmbassador;
static rti1516::RTIambassador* rtiAmb;

// the name of the fed file this federate will use. Can be overridden with cmd line parameter fedFile
static std::wstring fedFileName(L"C:/Documents and Settings/rosskw1/My Documents/SVN-Google/HLA_IO/IO/FrameworkTest.xml");

// the name of the federation we'll create.
static std::wstring federationName(L"FrameworkTest");

// The interaction class name
static std::string performanceTestInteractionName = "Unit1_CEC_R49";

namespace framework {
    
}

namespace framework {

//
//// call tick
//// If we are running with fully asynchronous I/O, then we don't need to call tick.
//bool callTick=false;
//
//bool shouldWeTick()  {return callTick;}
//
//void tickMe(rti1516::RTIambassador* rtiAmb, double minTime, double maxTime) {
//    if (shouldWeTick()) {
//       rtiAmb->evokeMultipleCallbacks(minTime, maxTime);
//    }
//}


////////////////////////////////////////////////////////////////////////////////
// Create the federation execution
void createFedEx(rti1516::RTIambassador* rtiAmb,
                 std::wstring const& fedName,
                 std::wstring const& fedFile)
{
   std::cout << "createFederationExecution "
         << DtToString(fedName) << " "
         << DtToString(fedFile) << endl;
   try
   {
      rtiAmb->createFederationExecution(fedName, fedFile);
//      tickMe(rtiAmb,0.1, 0.2);
   }
   catch(rti1516::FederationExecutionAlreadyExists& ex)
   {
      std::cout << "Could not create Federation Execution: "
            << "FederationExecutionAlreadyExists: "
            << DtToString(ex.what()) << endl;
   }
   catch(rti1516::Exception& ex)
   {
      std::cout << "RTI Exception: "
            << DtToString(ex.what()) << endl
            << "Could not create Federation Execution: " << endl;
      exit(0);
   }            
   std::cout << "Federation Created." << endl;
}



////////////////////////////////////////////////////////////////////////////////
// Join the federation execution
void joinFedEx(
               rti1516::RTIambassador* rtiAmb, framework::FrameworkFederateAmbassador & fedAmb,
   std::wstring const& federateType, std::wstring const& federationName)
{
   bool joined=false;
   const int maxTry  = 10;
   int numTries = 0;
   std::cout << "joinFederationExecution "
         << DtToString(federateType) << " "
         << DtToString(federationName) << endl;

   while (!joined && numTries++ < maxTry)
   {
      try
      {
         rtiAmb->joinFederationExecution(federateType, federationName, fedAmb);
         joined = true;
      }
      catch(rti1516::FederationExecutionDoesNotExist)
      {
         std::cout << "FederationExecutionDoesNotExist, try "
              << numTries << " out of "
               << maxTry << endl;
         continue;
      }
      catch(rti1516::Exception& ex)
      {
         std::cout << "RTI Exception: "
               << DtToString(ex.what()) << endl;
         return;
      }
//      tickMe(rtiAmb,0.1, 0.2);
   }
   if (joined)
      std::cout << "Joined Federation." << endl;
   else
   {
      std::cout << "Giving up." << endl;
      rtiAmb->destroyFederationExecution(federationName);
      exit(0);
   }
}

////////////////////////////////////////////////////////////////////////////////
// Resign and destroy the federation execution
void resignAndDestroy( rti1516::RTIambassador * rtiAmb)
{
   rtiAmb->resignFederationExecution(rti1516::DELETE_OBJECTS);
   rtiAmb->destroyFederationExecution(federationName);
}
   



    void initializeFramework()
    {
      // Federate and Federation info
      std::vector< std::wstring > args;
      std::wstring federateType(L"performType1516");      

      std::cout << "Using " 
        << DtToString(rti1516::RTIname().c_str() ) << " " 
                << DtToString(rti1516::RTIversion().c_str()) << std::endl;

      // Adam's comment:  create the RTI factory, get an RTI ambassador, call
      // release on that auto-pointer, which gives us the RTI ambassador.
      // the factory returns an auto-pointer.
      // RTI and Federate Ambassadors
      rti1516::RTIambassadorFactory* rtiAmbFactory = new rti1516::RTIambassadorFactory();
      std::auto_ptr < rti1516::RTIambassador > rtiAmbAP =
         rtiAmbFactory->createRTIambassador(args);
      delete rtiAmbFactory;
      rtiAmb = rtiAmbAP.release();

      frameworkFederateAmbassador = new FrameworkFederateAmbassador();

      // Create the federation
      createFedEx(rtiAmb, federationName, fedFileName);

      // Join the federation
      joinFedEx(rtiAmb, *frameworkFederateAmbassador, federateType, federationName);

    }

    void finalizeFramework()
    {
      delete frameworkFederateAmbassador;

      // Resign and destroy federation
      resignAndDestroy(rtiAmb);
    }
    
    //## operation RealTimeMode() 
    bool RealTimeMode() {
        //#[ operation RealTimeMode() 
        return(true);
        //#]
    }
    
    //## operation getFrameworkFederateAmbassador() 
    FrameworkFederateAmbassador* getFrameworkFederateAmbassador() {
        //#[ operation getFrameworkFederateAmbassador() 
        return(frameworkFederateAmbassador);
        //#]
    }
    
    //## operation getTheRTIambassador () 
    rti1516::RTIambassador* getTheRTIambassador () {
        //#[ operation getTheRTIambassador () 
        return(rtiAmb);
        //#]
    }
    
    framework::FrameworkFederateAmbassador* frameworkFederateAmbassador;
    rti1516::RTIambassador* rtiAmb;

    
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\framework.cpp
*********************************************************************/

