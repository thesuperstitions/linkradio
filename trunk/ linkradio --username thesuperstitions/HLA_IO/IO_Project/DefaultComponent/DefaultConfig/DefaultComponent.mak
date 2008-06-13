
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
  "C:\Program Files\boost\boost_1_35_0\lib\libboost_thread-vc71-mt-gd-1_35.lib" \
  "C:\Program Files\boost\boost_1_35_0\lib\libboost_date_time-vc71-mt-gd-1_35.lib"

INCLUDE_PATH= \
  $(INCLUDE_QUALIFIER)"C:\MAK\makRti3.2\include" \
  $(INCLUDE_QUALIFIER)"C:\Program Files\boost\boost_1_35_0" \
  $(INCLUDE_QUALIFIER)"C:\Program Files\boost\boost_1_35_0\boost\thread" \
  $(INCLUDE_QUALIFIER)"C:\Program Files\Microsoft.NET\SDK\v1.1\include\\" \
  $(INCLUDE_QUALIFIER)"C:\Documents and Settings\rosskw1\My Documents\ntds_common\\" \
  $(INCLUDE_QUALIFIER)"C:\Program Files\Microsoft.NET\SDK\v1.1\include\\" \
  $(INCLUDE_QUALIFIER)"C:\Documents and Settings\rosskw1\My Documents\ComponentizedCombatSystemFramework\\" \
  $(INCLUDE_QUALIFIER)"C:\Documents and Settings\rosskw1\My Documents\ComponentizedCombatSystemFramework\framework\\" \
  $(INCLUDE_QUALIFIER)"C:\Documents and Settings\rosskw1\My Documents\ComponentizedCombatSystemFramework\framework\utils\\" \
  $(INCLUDE_QUALIFIER)$(OMROOT)/LangCpp/osconfig/WIN32

ADDITIONAL_OBJS=

OBJS= \
  FrameworkFederateAmbassador.obj \
  RtiAmbassador.obj \
  FederateInterface.obj \
  FederateIO_Handler.obj \
  HLA_FederateInterface.obj \
  OASIS_FederateInterface.obj \
  C_IO_Functions.obj \
  PostOffice.obj \
  HLA_PostOffice.obj \
  Serializer.obj \
  Federate.obj \
  HlaCecFederate.obj \
  FederateInterfaceFactory.obj \
  FrameworkTester.obj \
  framework.obj \
  IO.obj \
  Control.obj \
  FrameworkTest.obj \
  InterprocessQueue.obj \
  Thread.obj \
  InterprocessQueue.obj




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






FrameworkFederateAmbassador.obj : FrameworkFederateAmbassador.cpp FrameworkFederateAmbassador.h    framework.h HLA_PostOffice.h RtiAmbassador.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FrameworkFederateAmbassador.obj" "FrameworkFederateAmbassador.cpp" 



RtiAmbassador.obj : RtiAmbassador.cpp RtiAmbassador.h    framework.h FrameworkFederateAmbassador.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"RtiAmbassador.obj" "RtiAmbassador.cpp" 



FederateInterface.obj : FederateInterface.cpp FederateInterface.h    IO.h FederateIO_Handler.h Control.h Federate.h PostOffice.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FederateInterface.obj" "FederateInterface.cpp" 



FederateIO_Handler.obj : FederateIO_Handler.cpp FederateIO_Handler.h    IO.h FederateInterface.h FederateInterfaceFactory.h Federate.h PostOffice.h C_IO_Functions.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FederateIO_Handler.obj" "FederateIO_Handler.cpp" 



HLA_FederateInterface.obj : HLA_FederateInterface.cpp HLA_FederateInterface.h    IO.h HLA_PostOffice.h FederateInterface.h Control.h FederateIO_Handler.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"HLA_FederateInterface.obj" "HLA_FederateInterface.cpp" 



OASIS_FederateInterface.obj : OASIS_FederateInterface.cpp OASIS_FederateInterface.h    IO.h FederateInterface.h Control.h FederateIO_Handler.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"OASIS_FederateInterface.obj" "OASIS_FederateInterface.cpp" 



C_IO_Functions.obj : C_IO_Functions.cpp C_IO_Functions.h    IO.h Federate.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"C_IO_Functions.obj" "C_IO_Functions.cpp" 



PostOffice.obj : PostOffice.cpp PostOffice.h    IO.h Federate.h FederateInterface.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"PostOffice.obj" "PostOffice.cpp" 



HLA_PostOffice.obj : HLA_PostOffice.cpp HLA_PostOffice.h    IO.h FrameworkFederateAmbassador.h HLA_FederateInterface.h FederateInterface.h PostOffice.h Federate.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"HLA_PostOffice.obj" "HLA_PostOffice.cpp" 



Serializer.obj : Serializer.cpp Serializer.h    Control.h IO.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Serializer.obj" "Serializer.cpp" 



Federate.obj : Federate.cpp Federate.h    Control.h PostOffice.h FederateIO_Handler.h FederateInterfaceFactory.h HLA_PostOffice.h FrameworkFederateAmbassador.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Federate.obj" "Federate.cpp" 



HlaCecFederate.obj : HlaCecFederate.cpp HlaCecFederate.h    Control.h Federate.h FederateIO_Handler.h PostOffice.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"HlaCecFederate.obj" "HlaCecFederate.cpp" 



FederateInterfaceFactory.obj : FederateInterfaceFactory.cpp FederateInterfaceFactory.h    Control.h FederateIO_Handler.h HLA_FederateInterface.h OASIS_FederateInterface.h FederateInterface.h framework.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FederateInterfaceFactory.obj" "FederateInterfaceFactory.cpp" 



FrameworkTester.obj : FrameworkTester.cpp FrameworkTester.h    FrameworkTest.h FrameworkFederateAmbassador.h RtiAmbassador.h HlaCecFederate.h C_IO_Functions.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FrameworkTester.obj" "FrameworkTester.cpp" 



framework.obj : framework.cpp framework.h    FrameworkFederateAmbassador.h RtiAmbassador.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"framework.obj" "framework.cpp" 



IO.obj : IO.cpp IO.h    FederateInterface.h FederateIO_Handler.h HLA_FederateInterface.h OASIS_FederateInterface.h C_IO_Functions.h PostOffice.h HLA_PostOffice.h framework.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"IO.obj" "IO.cpp" 



Control.obj : Control.cpp Control.h    Serializer.h Federate.h HlaCecFederate.h FederateInterfaceFactory.h framework.h PostOffice.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Control.obj" "Control.cpp" 



FrameworkTest.obj : FrameworkTest.cpp FrameworkTest.h    FrameworkTester.h 
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"FrameworkTest.obj" "FrameworkTest.cpp" 



InterprocessQueue.obj : "C:\Documents and Settings\rosskw1\My Documents\ComponentizedCombatSystemFramework\framework\utils\InterprocessQueue.cpp"     
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"InterprocessQueue.obj" "C:\Documents and Settings\rosskw1\My Documents\ComponentizedCombatSystemFramework\framework\utils\InterprocessQueue.cpp" 



Thread.obj : "C:\Documents and Settings\rosskw1\My Documents\ComponentizedCombatSystemFramework\framework\utils\Thread.cpp"     
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"Thread.obj" "C:\Documents and Settings\rosskw1\My Documents\ComponentizedCombatSystemFramework\framework\utils\Thread.cpp" 



InterprocessQueue.obj : InterprocessQueueTest-Linux\InterprocessQueue.cpp     
	$(CREATE_OBJ_DIR)
	$(CPP) $(ConfigurationCPPCompileSwitches)  /Fo"InterprocessQueue.obj" "InterprocessQueueTest-Linux\InterprocessQueue.cpp" 






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
	if exist FederateIO_Handler.obj erase FederateIO_Handler.obj
	if exist HLA_FederateInterface.obj erase HLA_FederateInterface.obj
	if exist OASIS_FederateInterface.obj erase OASIS_FederateInterface.obj
	if exist C_IO_Functions.obj erase C_IO_Functions.obj
	if exist PostOffice.obj erase PostOffice.obj
	if exist HLA_PostOffice.obj erase HLA_PostOffice.obj
	if exist Serializer.obj erase Serializer.obj
	if exist Federate.obj erase Federate.obj
	if exist HlaCecFederate.obj erase HlaCecFederate.obj
	if exist FederateInterfaceFactory.obj erase FederateInterfaceFactory.obj
	if exist FrameworkTester.obj erase FrameworkTester.obj
	if exist framework.obj erase framework.obj
	if exist IO.obj erase IO.obj
	if exist Control.obj erase Control.obj
	if exist FrameworkTest.obj erase FrameworkTest.obj
	if exist InterprocessQueue.obj erase InterprocessQueue.obj
	if exist Thread.obj erase Thread.obj
	if exist InterprocessQueue.obj erase InterprocessQueue.obj
	if exist $(TARGET_MAIN)$(OBJ_EXT) erase $(TARGET_MAIN)$(OBJ_EXT)
	if exist *$(OBJ_EXT) erase *$(OBJ_EXT)
	if exist $(TARGET_NAME).pdb erase $(TARGET_NAME).pdb
	if exist $(TARGET_NAME)$(LIB_EXT) erase $(TARGET_NAME)$(LIB_EXT)
	if exist $(TARGET_NAME).ilk erase $(TARGET_NAME).ilk
	if exist $(TARGET_NAME)$(EXE_EXT) erase $(TARGET_NAME)$(EXE_EXT)
	$(CLEAN_OBJ_DIR)
