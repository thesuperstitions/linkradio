/*********************************************************************
	Rhapsody	: 7.1 
	Login		: rosskw1
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: framework::io::hla::HLA_PostOffice
//!	Generated Date	: Mon, 19, May 2008  
	File Path	: DefaultComponent\DefaultConfig\HLA_PostOffice.h
*********************************************************************/


#ifndef HLA_PostOffice_H 

#define HLA_PostOffice_H 

#include "Configuration.h"
// link theHLA_FederateInterface 
#include "HLA_FederateInterface.h"
#include "IO.h"
// class HLA_PostOffice 
#include "PostOffice.h"
#include "RTI\RTI1516.h"
// operation sendMessage(FrameworkMessage*) 
#include "framework.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
//----------------------------------------------------------------------------
// HLA_PostOffice.h                                                                  
//----------------------------------------------------------------------------


namespace framework
{

	namespace Control
	{
		class Federate;

	} 

namespace io
{
	class FederateInterface;

} 

} 

namespace framework
{
	class FrameworkFederateAmbassador;
}


//## package framework::io 

#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif

namespace framework
{
	namespace io
	{
	namespace hla
	{
		//## class HLA_PostOffice 
		class HLA_PostOffice : public PostOffice
		{


		////    Constructors and destructors    ////
		public :

			//## operation HLA_PostOffice(FrameworkFederateAmbassador*) 
			HLA_PostOffice(FrameworkFederateAmbassador* frameworkFederateAmbassador);

			//## auto_generated 
			HLA_PostOffice();

			//## auto_generated 
			virtual ~HLA_PostOffice();


		////    Operations    ////
		public :

			//## operation announcePublication(FederateInterface*) 
			void announcePublication(FederateInterface* interface);

			//## operation announceSubscription(FederateInterface*) 
			void announceSubscription(FederateInterface* interface);

			//## operation createInteractionClassHandle(HLA_FederateInterface*) 
			void createInteractionClassHandle(framework::io::hla::HLA_FederateInterface* interface);

			// 6.9
			//## operation receiveInteraction(rti1516::InteractionClassHandle,const rti1516::ParameterHandleValueMap &,const rti1516::VariableLengthData &,rti1516::OrderType,rti1516::TransportationType) 
			virtual void receiveInteraction(rti1516::InteractionClassHandle theInteraction, const rti1516::ParameterHandleValueMap & theParameterValues, const rti1516::VariableLengthData & theUserSuppliedTag, rti1516::OrderType sentOrder, rti1516::TransportationType theType) throw( rti1516::InteractionClassNotRecognized, rti1516::InteractionParameterNotRecognized, rti1516::InteractionClassNotSubscribed, rti1516::FederateInternalError );

			//## operation sendMessage(FrameworkMessage*) 
			void sendMessage(FrameworkMessage* message);

			//## operation sendMessage(char*,int,FederateInterface*) 
			void sendMessage(char* message, int messageSizeInBytes, FederateInterface* federateInterface);

			//## operation unsubscribe(FederateInterface*) 
			void unsubscribe(FederateInterface* interface);


		////    Additional operations    ////
		public :

			//## auto_generated 
			FrameworkFederateAmbassador* getTheFrameworkFederateAmbassador() const;

			//## auto_generated 
			void setTheFrameworkFederateAmbassador(FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);

			//## auto_generated 
			std::map<rti1516::InteractionClassHandle, framework::io::hla::HLA_FederateInterface*>::const_iterator getTheHLA_FederateInterface() const;

			//## auto_generated 
			std::map<rti1516::InteractionClassHandle, framework::io::hla::HLA_FederateInterface*>::const_iterator getTheHLA_FederateInterfaceEnd() const;

			//## auto_generated 
			void clearTheHLA_FederateInterface();

			//## auto_generated 
			void removeTheHLA_FederateInterface(framework::io::hla::HLA_FederateInterface* p_HLA_FederateInterface);

			//## auto_generated 
			framework::io::hla::HLA_FederateInterface* getTheHLA_FederateInterface(rti1516::InteractionClassHandle key) const;

			//## auto_generated 
			void addTheHLA_FederateInterface(rti1516::InteractionClassHandle key, framework::io::hla::HLA_FederateInterface* p_HLA_FederateInterface);

			//## auto_generated 
			void removeTheHLA_FederateInterface(rti1516::InteractionClassHandle key);


		////    Framework operations    ////
		public :

			//## auto_generated 
			void __setTheFrameworkFederateAmbassador(FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);

			//## auto_generated 
			void _setTheFrameworkFederateAmbassador(FrameworkFederateAmbassador* p_FrameworkFederateAmbassador);

			//## auto_generated 
			void _clearTheFrameworkFederateAmbassador();

			//## auto_generated 
			void _clearTheHLA_FederateInterface();

			//## auto_generated 
			void _removeTheHLA_FederateInterface(framework::io::hla::HLA_FederateInterface* p_HLA_FederateInterface);

			//## auto_generated 
			void _addTheHLA_FederateInterface(rti1516::InteractionClassHandle key, framework::io::hla::HLA_FederateInterface* p_HLA_FederateInterface);

			//## auto_generated 
			void _removeTheHLA_FederateInterface(rti1516::InteractionClassHandle key);

		protected :

			//## auto_generated 
			void cleanUpRelations();


		////    Relations and components    ////
		protected :

			FrameworkFederateAmbassador* theFrameworkFederateAmbassador;		//## link theFrameworkFederateAmbassador 


			std::map<rti1516::InteractionClassHandle, framework::io::hla::HLA_FederateInterface*> theHLA_FederateInterface;		//## link theHLA_FederateInterface 



		};
	}
	}
}


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\HLA_PostOffice.h
*********************************************************************/

