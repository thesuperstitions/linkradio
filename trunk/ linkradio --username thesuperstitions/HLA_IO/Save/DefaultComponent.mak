
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

ConfigurationCPPCompileSwitches=   /I . /I . /I $(OMROOT)\LangCpp /I $(OMROOT)\LangCpp\oxf /nologo /W3 /GX $(CPPCompileDebug) /D "_AFXDLL" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "_WINDOWS" $(INST_FLAGS) $(INCLUDE_PATH) $(INST_INCLUDES) /c 

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
  "C:\MAK\makRti3.2\lib\librti1516.lib" \
  "C:\MAK\makRti3.2\lib\libFedTime1516.lib"

INCLUDE_PATH= \
  $(INCLUDE_QUALIFIER)"C:\Program Files\Microsoft.NET\SDK\v1.1\include\\" \
  $(INCLUDE_QUALIFIER)"C:\MAK\makRti3.2\include" \
  $(INCLUDE_QUALIFIER)"C:\MAK\makRti3.2\include\RTI" \
  $(INCLUDE_QUALIFIER)$(OMROOT)/LangCpp/osconfig/WIN32

ADDITIONAL_OBJS=

OBJS= \
  FederateInterface.obj \
  FederateMessage.obj \
  IO_Handler.obj \
  Message.obj \
  PostOffice.obj \
  HLA_PostOffice.obj \
  FederateIO_Handler.obj \
  RtiAmbassador.obj \
  FederateInterfaceFactory.obj \
  HLA_FederateInterface.obj \
  OASIS_FederateInterface.obj \
  Buffer.obj \
  RTI_Ambassador.obj \
  FrameworkFederateAmbassador.obj \
  Serializer.obj \
  ExampleFederate.obj \
  Federate.obj \
  T.obj \
  Framework.obj \
  IO.obj \
  Control.obj \
  RTItypes.obj




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






FederateInterface.obj : FederateInterface.cpp FederateInterface.h    IO.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FederateInterface.obj" "FederateInterface.cpp" 



FederateMessage.obj : FederateMessage.cpp FederateMessage.h    IO.h FederateIO_Handler.h FederateInterface.h Buffer.h Message.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FederateMessage.obj" "FederateMessage.cpp" 



IO_Handler.obj : IO_Handler.cpp IO_Handler.h    IO.h Serializer.h PostOffice.h FederateMessage.h Framework.h Buffer.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"IO_Handler.obj" "IO_Handler.cpp" 



Message.obj : Message.cpp Message.h    IO.h Buffer.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Message.obj" "Message.cpp" 



PostOffice.obj : PostOffice.cpp PostOffice.h    IO.h IO_Handler.h Message.h Federate.h FederateInterface.h FederateMessage.h Buffer.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"PostOffice.obj" "PostOffice.cpp" 



HLA_PostOffice.obj : HLA_PostOffice.cpp HLA_PostOffice.h    IO.h FrameworkFederateAmbassador.h HLA_FederateInterface.h FederateInterface.h FederateMessage.h Buffer.h PostOffice.h IO_Handler.h Message.h Federate.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"HLA_PostOffice.obj" "HLA_PostOffice.cpp" 



FederateIO_Handler.obj : FederateIO_Handler.cpp FederateIO_Handler.h    IO.h FederateMessage.h Federate.h FederateInterface.h Framework.h Buffer.h IO_Handler.h Serializer.h PostOffice.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FederateIO_Handler.obj" "FederateIO_Handler.cpp" 



RtiAmbassador.obj : RtiAmbassador.cpp RtiAmbassador.h    IO.h FrameworkFederateAmbassador.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"RtiAmbassador.obj" "RtiAmbassador.cpp" 



FederateInterfaceFactory.obj : FederateInterfaceFactory.cpp FederateInterfaceFactory.h    IO.h Federate.h FederateInterface.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FederateInterfaceFactory.obj" "FederateInterfaceFactory.cpp" 



HLA_FederateInterface.obj : HLA_FederateInterface.cpp HLA_FederateInterface.h    IO.h HLA_PostOffice.h FrameworkFederateAmbassador.h FederateInterface.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"HLA_FederateInterface.obj" "HLA_FederateInterface.cpp" 



OASIS_FederateInterface.obj : OASIS_FederateInterface.cpp OASIS_FederateInterface.h    IO.h FederateInterfaceFactory.h FederateInterface.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"OASIS_FederateInterface.obj" "OASIS_FederateInterface.cpp" 



Buffer.obj : Buffer.cpp Buffer.h    IO.h Message.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Buffer.obj" "Buffer.cpp" 



RTI_Ambassador.obj : RTI_Ambassador.cpp RTI_Ambassador.h    Control.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"RTI_Ambassador.obj" "RTI_Ambassador.cpp" 



FrameworkFederateAmbassador.obj : FrameworkFederateAmbassador.cpp FrameworkFederateAmbassador.h    Control.h HLA_PostOffice.h RtiAmbassador.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FrameworkFederateAmbassador.obj" "FrameworkFederateAmbassador.cpp" 



Serializer.obj : Serializer.cpp Serializer.h    Control.h IO_Handler.h IO.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Serializer.obj" "Serializer.cpp" 



ExampleFederate.obj : ExampleFederate.cpp ExampleFederate.h    Federate.h PostOffice.h FederateInterfaceFactory.h FederateInterface.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"ExampleFederate.obj" "ExampleFederate.cpp" 



Federate.obj : Federate.cpp Federate.h    PostOffice.h FederateInterfaceFactory.h FederateInterface.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Federate.obj" "Federate.cpp" 



T.obj : T.cpp T.h    
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"T.obj" "T.cpp" 



Framework.obj : Framework.cpp Framework.h    
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Framework.obj" "Framework.cpp" 



IO.obj : IO.cpp IO.h    FederateInterface.h FederateMessage.h IO_Handler.h Message.h PostOffice.h HLA_PostOffice.h FederateIO_Handler.h RtiAmbassador.h FederateInterfaceFactory.h HLA_FederateInterface.h OASIS_FederateInterface.h Buffer.h Framework.h FrameworkFederateAmbassador.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"IO.obj" "IO.cpp" 



Control.obj : Control.cpp Control.h    RTI_Ambassador.h FrameworkFederateAmbassador.h Serializer.h Framework.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Control.obj" "Control.cpp" 



RTItypes.obj : include\RTItypes.hh     
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"RTItypes.obj" "include\RTItypes.hh" 






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
	if exist FederateInterface.obj erase FederateInterface.obj
	if exist FederateMessage.obj erase FederateMessage.obj
	if exist IO_Handler.obj erase IO_Handler.obj
	if exist Message.obj erase Message.obj
	if exist PostOffice.obj erase PostOffice.obj
	if exist HLA_PostOffice.obj erase HLA_PostOffice.obj
	if exist FederateIO_Handler.obj erase FederateIO_Handler.obj
	if exist RtiAmbassador.obj erase RtiAmbassador.obj
	if exist FederateInterfaceFactory.obj erase FederateInterfaceFactory.obj
	if exist HLA_FederateInterface.obj erase HLA_FederateInterface.obj
	if exist OASIS_FederateInterface.obj erase OASIS_FederateInterface.obj
	if exist Buffer.obj erase Buffer.obj
	if exist RTI_Ambassador.obj erase RTI_Ambassador.obj
	if exist FrameworkFederateAmbassador.obj erase FrameworkFederateAmbassador.obj
	if exist Serializer.obj erase Serializer.obj
	if exist ExampleFederate.obj erase ExampleFederate.obj
	if exist Federate.obj erase Federate.obj
	if exist T.obj erase T.obj
	if exist Framework.obj erase Framework.obj
	if exist IO.obj erase IO.obj
	if exist Control.obj erase Control.obj
	if exist RTItypes.obj erase RTItypes.obj
	if exist $(TARGET_MAIN)$(OBJ_EXT) erase $(TARGET_MAIN)$(OBJ_EXT)
	if exist *$(OBJ_EXT) erase *$(OBJ_EXT)
	if exist $(TARGET_NAME).pdb erase $(TARGET_NAME).pdb
	if exist $(TARGET_NAME)$(LIB_EXT) erase $(TARGET_NAME)$(LIB_EXT)
	if exist $(TARGET_NAME).ilk erase $(TARGET_NAME).ilk
	if exist $(TARGET_NAME)$(EXE_EXT) erase $(TARGET_NAME)$(EXE_EXT)
	$(CLEAN_OBJ_DIR)
