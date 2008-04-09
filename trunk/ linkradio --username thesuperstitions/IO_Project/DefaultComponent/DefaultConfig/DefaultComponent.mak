
############# Target type (Debug/Release) ##################
############################################################
CPPCompileDebug= /Zi /Od /D "_DEBUG" /MDd  /Fd"$(TARGET_NAME)" 
CPPCompileRelease= /Ox /D"NDEBUG" /MD /Fd"$(TARGET_NAME)" 
LinkDebug=
LinkRelease=
BuildSet=Debug
SUBSYSTEM=/SUBSYSTEM:console
COM=False
RPFrameWorkDll=False
SimulinkLibName=

ConfigurationCPPCompileSwitches=   /I . /I . /I $(OMROOT)\LangCpp /I $(OMROOT)\LangCpp\oxf /nologo /W3 /GX $(CPPCompileDebug) /D "RTI_USES_STD_FSTREAM=1" /D "DtIFSPEC1516" /D "RTI_USES_STD_FSTREAM" /D "_AFXDLL" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "_WINDOWS" $(INST_FLAGS) $(INCLUDE_PATH) $(INST_INCLUDES) /c 

!IF "$(RPFrameWorkDll)" == "True"
ConfigurationCPPCompileSwitches=$(ConfigurationCPPCompileSwitches) /D "FRAMEWORK_DLL"
!ENDIF

!IF "$(COM)" == "True"
SUBSYSTEM=/SUBSYSTEM:windows
!ENDIF

################### Compilation flags ######################
############################################################
INCLUDE_QUALIFIER=/I
LIB_PREFIX=MS

################### Commands definition #########################
#################################################################
RMDIR = rmdir
LIB_CMD=link.exe -lib
LINK_CMD=link.exe
LIB_FLAGS=$(LinkDebug) /NOLOGO   
LINK_FLAGS=$(LinkDebug) /NOLOGO    $(SUBSYSTEM) /MACHINE:I386 

############### Generated macros #################
##################################################

FLAGSFILE=
RULESFILE=
OMROOT="C:\Program Files\Telelogic\Rhapsody 7.1\Share"

CPP_EXT=.cpp
H_EXT=.h
OBJ_EXT=.obj
EXE_EXT=.exe
LIB_EXT=.lib

INSTRUMENTATION=None

TIME_MODEL=RealTime

TARGET_TYPE=Executable

TARGET_NAME=DefaultComponent

all : $(TARGET_NAME)$(EXE_EXT) DefaultComponent.mak

TARGET_MAIN=MainDefaultComponent

LIBS= \
  C:\MAK\makRti3.2\lib\librti1516.lib \
  C:\MAK\makRti3.2\lib\libFedTime1516.lib \
  "C:\MAK\makRti3.2\lib\librti1516.lib" \
  "C:\MAK\makRti3.2\lib\libfedtime1516.lib" \
  "C:\Program Files\boost\boost_1_34_1\lib"\libboost_thread-vc71-mt-gd-1_34_1.lib

INCLUDE_PATH= \
  $(INCLUDE_QUALIFIER)"C:\MAK\makRti3.2\include" \
  $(INCLUDE_QUALIFIER)"C:\MAK\makRti3.2\include" \
  $(INCLUDE_QUALIFIER)"C:\Program Files\boost\boost_1_34_1" \
  $(INCLUDE_QUALIFIER)"C:\Documents and Settings\rosskw1\My Documents\ComponentizedCombatSystemFramework\examples\\" \
  $(INCLUDE_QUALIFIER)"C:\Program Files\boost\boost_1_34_1\boost\thread" \
  $(INCLUDE_QUALIFIER)"C:\Program Files\Microsoft.NET\SDK\v1.1\include\\" \
  $(INCLUDE_QUALIFIER)$(OMROOT)/LangCpp/osconfig/WIN32

ADDITIONAL_OBJS=

OBJS= \
  FrameworkFederateAmbassador.obj \
  RtiAmbassador.obj \
  FederateInterface.obj \
  FederateMessage.obj \
  IO_Handler.obj \
  Message.obj \
  PostOffice.obj \
  HLA_PostOffice.obj \
  FederateIO_Handler.obj \
  HLA_FederateInterface.obj \
  OASIS_FederateInterface.obj \
  Buffer.obj \
  FederateIO_OutputThread.obj \
  FederateIO_InputThread.obj \
  C_IO_Functions.obj \
  Serializer.obj \
  Federate.obj \
  ExampleFederate.obj \
  FederateInterfaceFactory.obj \
  Sleep.obj \
  Thread.obj \
  Timer.obj \
  FrameworkTester.obj \
  Framework.obj \
  IO.obj \
  Control.obj




OBJ_DIR=

!IF "$(OBJ_DIR)"!=""
CREATE_OBJ_DIR=if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
CLEAN_OBJ_DIR= if exist $(OBJ_DIR) $(RMDIR) $(OBJ_DIR)
!ELSE
CREATE_OBJ_DIR=
CLEAN_OBJ_DIR=
!ENDIF

######################## Predefined macros ############################
#######################################################################
$(OBJS) : $(INST_LIBS) $(OXF_LIBS)

LIB_POSTFIX=
!IF "$(BuildSet)"=="Release"
LIB_POSTFIX=R
!ENDIF

!IF "$(TARGET_TYPE)" == "Executable"
LinkDebug=$(LinkDebug) /DEBUG
LinkRelease=$(LinkRelease) /OPT:NOREF
!ELSEIF "$(TARGET_TYPE)" == "Library"
LinkDebug=$(LinkDebug) /DEBUGTYPE:CV
!ENDIF


!IF "$(INSTRUMENTATION)" == "Animation"
INST_FLAGS=/D "OMANIMATOR"
INST_INCLUDES=/I $(OMROOT)\LangCpp\aom /I $(OMROOT)\LangCpp\tom
!IF "$(RPFrameWorkDll)" == "True"
INST_LIBS= 
OXF_LIBS=$(OMROOT)\LangCpp\lib\$(LIB_PREFIX)oxfanimdll$(LIB_POSTFIX)$(LIB_EXT) 
!ELSE
INST_LIBS= $(OMROOT)\LangCpp\lib\$(LIB_PREFIX)aomanim$(LIB_POSTFIX)$(LIB_EXT)
OXF_LIBS=$(OMROOT)\LangCpp\lib\$(LIB_PREFIX)oxfinst$(LIB_POSTFIX)$(LIB_EXT) $(OMROOT)\LangCpp\lib\$(LIB_PREFIX)omComAppl$(LIB_POSTFIX)$(LIB_EXT) $(SimulinkLibName)
!ENDIF
SOCK_LIB=wsock32.lib

!ELSEIF "$(INSTRUMENTATION)" == "Tracing"
INST_FLAGS=/D "OMTRACER"
INST_INCLUDES=/I $(OMROOT)\LangCpp\aom /I $(OMROOT)\LangCpp\tom
!IF "$(RPFrameWorkDll)" == "True"
INST_LIBS=
OXF_LIBS= $(OMROOT)\LangCpp\lib\$(LIB_PREFIX)oxftracedll$(LIB_POSTFIX)$(LIB_EXT) 
!ELSE
INST_LIBS=$(OMROOT)\LangCpp\lib\$(LIB_PREFIX)tomtrace$(LIB_POSTFIX)$(LIB_EXT) $(OMROOT)\LangCpp\lib\$(LIB_PREFIX)aomtrace$(LIB_POSTFIX)$(LIB_EXT)
OXF_LIBS= $(OMROOT)\LangCpp\lib\$(LIB_PREFIX)oxfinst$(LIB_POSTFIX)$(LIB_EXT) $(OMROOT)\LangCpp\lib\$(LIB_PREFIX)omComAppl$(LIB_POSTFIX)$(LIB_EXT) $(SimulinkLibName)
!ENDIF
SOCK_LIB=wsock32.lib

!ELSEIF "$(INSTRUMENTATION)" == "None" 
INST_FLAGS=
INST_INCLUDES=
INST_LIBS=
!IF "$(RPFrameWorkDll)" == "True"
OXF_LIBS=$(OMROOT)\LangCpp\lib\$(LIB_PREFIX)oxfdll$(LIB_POSTFIX)$(LIB_EXT)
!ELSE
OXF_LIBS=$(OMROOT)\LangCpp\lib\$(LIB_PREFIX)oxf$(LIB_POSTFIX)$(LIB_EXT) $(SimulinkLibName)
!ENDIF
SOCK_LIB=

!ELSE
!ERROR An invalid Instrumentation $(INSTRUMENTATION) is specified.
!ENDIF



################## Generated dependencies ########################
##################################################################






FrameworkFederateAmbassador.obj : FrameworkFederateAmbassador.cpp FrameworkFederateAmbassador.h    Framework.h HLA_PostOffice.h RtiAmbassador.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FrameworkFederateAmbassador.obj" "FrameworkFederateAmbassador.cpp" 



RtiAmbassador.obj : RtiAmbassador.cpp RtiAmbassador.h    Framework.h FrameworkFederateAmbassador.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"RtiAmbassador.obj" "RtiAmbassador.cpp" 



FederateInterface.obj : FederateInterface.cpp FederateInterface.h    IO.h FederateIO_Handler.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FederateInterface.obj" "FederateInterface.cpp" 



FederateMessage.obj : FederateMessage.cpp FederateMessage.h    IO.h FederateInterface.h Message.h Buffer.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FederateMessage.obj" "FederateMessage.cpp" 



IO_Handler.obj : IO_Handler.cpp IO_Handler.h    IO.h Serializer.h FederateMessage.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"IO_Handler.obj" "IO_Handler.cpp" 



Message.obj : Message.cpp Message.h    IO.h Buffer.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Message.obj" "Message.cpp" 



PostOffice.obj : PostOffice.cpp PostOffice.h    IO.h Federate.h FederateInterface.h FederateMessage.h Buffer.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"PostOffice.obj" "PostOffice.cpp" 



HLA_PostOffice.obj : HLA_PostOffice.cpp HLA_PostOffice.h    IO.h FrameworkFederateAmbassador.h HLA_FederateInterface.h FederateIO_InputThread.h FederateInterface.h FederateMessage.h Buffer.h PostOffice.h Federate.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"HLA_PostOffice.obj" "HLA_PostOffice.cpp" 



FederateIO_Handler.obj : FederateIO_Handler.cpp FederateIO_Handler.h    IO.h FederateInterface.h FederateInterfaceFactory.h FederateIO_OutputThread.h Federate.h FederateMessage.h FederateIO_InputThread.h PostOffice.h Buffer.h C_IO_Functions.h IO_Handler.h Serializer.h Timer.h Thread.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FederateIO_Handler.obj" "FederateIO_Handler.cpp" 



HLA_FederateInterface.obj : HLA_FederateInterface.cpp HLA_FederateInterface.h    IO.h HLA_PostOffice.h FederateInterface.h FederateIO_Handler.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"HLA_FederateInterface.obj" "HLA_FederateInterface.cpp" 



OASIS_FederateInterface.obj : OASIS_FederateInterface.cpp OASIS_FederateInterface.h    IO.h FederateInterface.h FederateIO_Handler.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"OASIS_FederateInterface.obj" "OASIS_FederateInterface.cpp" 



Buffer.obj : Buffer.cpp Buffer.h    IO.h Message.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Buffer.obj" "Buffer.cpp" 



FederateIO_OutputThread.obj : FederateIO_OutputThread.cpp FederateIO_OutputThread.h    IO.h FederateIO_Handler.h FederateMessage.h Control.h PostOffice.h Sleep.h Federate.h Thread.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FederateIO_OutputThread.obj" "FederateIO_OutputThread.cpp" 



FederateIO_InputThread.obj : FederateIO_InputThread.cpp FederateIO_InputThread.h    IO.h FederateIO_Handler.h FederateIO_OutputThread.h FederateMessage.h Thread.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FederateIO_InputThread.obj" "FederateIO_InputThread.cpp" 



C_IO_Functions.obj : C_IO_Functions.cpp C_IO_Functions.h    IO.h Federate.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"C_IO_Functions.obj" "C_IO_Functions.cpp" 



Serializer.obj : Serializer.cpp Serializer.h    Control.h IO_Handler.h IO.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Serializer.obj" "Serializer.cpp" 



Federate.obj : Federate.cpp Federate.h    Control.h PostOffice.h FederateIO_Handler.h FederateInterfaceFactory.h HLA_PostOffice.h FrameworkFederateAmbassador.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Federate.obj" "Federate.cpp" 



ExampleFederate.obj : ExampleFederate.cpp ExampleFederate.h    Control.h FrameworkFederateAmbassador.h Federate.h FederateIO_Handler.h PostOffice.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ExampleFederate.obj" "ExampleFederate.cpp" 



FederateInterfaceFactory.obj : FederateInterfaceFactory.cpp FederateInterfaceFactory.h    Control.h FederateIO_Handler.h HLA_FederateInterface.h OASIS_FederateInterface.h FederateInterface.h Framework.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FederateInterfaceFactory.obj" "FederateInterfaceFactory.cpp" 



Sleep.obj : Sleep.cpp Sleep.h    
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Sleep.obj" "Sleep.cpp" 



Thread.obj : Thread.cpp Thread.h    
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Thread.obj" "Thread.cpp" 



Timer.obj : Timer.cpp Timer.h    Sleep.h Thread.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Timer.obj" "Timer.cpp" 



FrameworkTester.obj : FrameworkTester.cpp FrameworkTester.h    FrameworkFederateAmbassador.h RtiAmbassador.h ExampleFederate.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FrameworkTester.obj" "FrameworkTester.cpp" 



Framework.obj : Framework.cpp Framework.h    FrameworkFederateAmbassador.h RtiAmbassador.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Framework.obj" "Framework.cpp" 



IO.obj : IO.cpp IO.h    FederateInterface.h FederateMessage.h IO_Handler.h Message.h PostOffice.h HLA_PostOffice.h FederateIO_Handler.h HLA_FederateInterface.h OASIS_FederateInterface.h Buffer.h FederateIO_OutputThread.h FederateIO_InputThread.h C_IO_Functions.h Framework.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"IO.obj" "IO.cpp" 



Control.obj : Control.cpp Control.h    Serializer.h Federate.h ExampleFederate.h FederateInterfaceFactory.h Framework.h PostOffice.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Control.obj" "Control.cpp" 






$(TARGET_MAIN)$(OBJ_EXT) : $(TARGET_MAIN)$(CPP_EXT) $(OBJS) 
	$(CPP) $(ConfigurationCPPCompileSwitches) /Fo"$(TARGET_MAIN)$(OBJ_EXT)" $(TARGET_MAIN)$(CPP_EXT)

########################## Linking instructions ###############################
###############################################################################
$(TARGET_NAME)$(EXE_EXT): $(OBJS) $(ADDITIONAL_OBJS) $(TARGET_MAIN)$(OBJ_EXT) DefaultComponent.mak 
	@echo Linking $(TARGET_NAME)$(EXE_EXT)
	$(LINK_CMD)  $(TARGET_MAIN)$(OBJ_EXT) $(OBJS) $(ADDITIONAL_OBJS) \
	$(LIBS) \
	$(INST_LIBS) \
	$(OXF_LIBS) \
	$(SOCK_LIB) \
	$(LINK_FLAGS) /out:$(TARGET_NAME)$(EXE_EXT)

$(TARGET_NAME)$(LIB_EXT) : $(OBJS) $(ADDITIONAL_OBJS) DefaultComponent.mak
	@echo Building library $@
	$(LIB_CMD) $(LIB_FLAGS) /out:$(TARGET_NAME)$(LIB_EXT) $(OBJS) $(ADDITIONAL_OBJS)

clean:
	@echo Cleanup
	if exist FrameworkFederateAmbassador.obj erase FrameworkFederateAmbassador.obj
	if exist RtiAmbassador.obj erase RtiAmbassador.obj
	if exist FederateInterface.obj erase FederateInterface.obj
	if exist FederateMessage.obj erase FederateMessage.obj
	if exist IO_Handler.obj erase IO_Handler.obj
	if exist Message.obj erase Message.obj
	if exist PostOffice.obj erase PostOffice.obj
	if exist HLA_PostOffice.obj erase HLA_PostOffice.obj
	if exist FederateIO_Handler.obj erase FederateIO_Handler.obj
	if exist HLA_FederateInterface.obj erase HLA_FederateInterface.obj
	if exist OASIS_FederateInterface.obj erase OASIS_FederateInterface.obj
	if exist Buffer.obj erase Buffer.obj
	if exist FederateIO_OutputThread.obj erase FederateIO_OutputThread.obj
	if exist FederateIO_InputThread.obj erase FederateIO_InputThread.obj
	if exist C_IO_Functions.obj erase C_IO_Functions.obj
	if exist Serializer.obj erase Serializer.obj
	if exist Federate.obj erase Federate.obj
	if exist ExampleFederate.obj erase ExampleFederate.obj
	if exist FederateInterfaceFactory.obj erase FederateInterfaceFactory.obj
	if exist Sleep.obj erase Sleep.obj
	if exist Thread.obj erase Thread.obj
	if exist Timer.obj erase Timer.obj
	if exist FrameworkTester.obj erase FrameworkTester.obj
	if exist Framework.obj erase Framework.obj
	if exist IO.obj erase IO.obj
	if exist Control.obj erase Control.obj
	if exist $(TARGET_MAIN)$(OBJ_EXT) erase $(TARGET_MAIN)$(OBJ_EXT)
	if exist *$(OBJ_EXT) erase *$(OBJ_EXT)
	if exist $(TARGET_NAME).pdb erase $(TARGET_NAME).pdb
	if exist $(TARGET_NAME)$(LIB_EXT) erase $(TARGET_NAME)$(LIB_EXT)
	if exist $(TARGET_NAME).ilk erase $(TARGET_NAME).ilk
	if exist $(TARGET_NAME)$(EXE_EXT) erase $(TARGET_NAME)$(EXE_EXT)
	$(CLEAN_OBJ_DIR)
