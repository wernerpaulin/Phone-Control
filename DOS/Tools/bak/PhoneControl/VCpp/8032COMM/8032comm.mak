# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=8032comm - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to 8032comm - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "8032comm - Win32 Release" && "$(CFG)" !=\
 "8032comm - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "8032comm.mak" CFG="8032comm - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "8032comm - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "8032comm - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "8032comm - Win32 Debug"
CPP=cl.exe
RSC=rc.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "8032comm - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\8032comm.exe"

CLEAN : 
	-@erase "$(INTDIR)\8032comm.obj"
	-@erase "$(INTDIR)\8032comm.pch"
	-@erase "$(INTDIR)\8032comm.res"
	-@erase "$(INTDIR)\8032commDoc.obj"
	-@erase "$(INTDIR)\8032commView.obj"
	-@erase "$(INTDIR)\ComPort.obj"
	-@erase "$(INTDIR)\DeviceNames.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\Recallset.obj"
	-@erase "$(INTDIR)\RingNr.obj"
	-@erase "$(INTDIR)\SavSett.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\8032comm.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /G5 /MT /W4 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /G5 /MT /W4 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/8032comm.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/8032comm.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/8032comm.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/8032comm.pdb" /machine:I386 /out:"$(OUTDIR)/8032comm.exe" 
LINK32_OBJS= \
	"$(INTDIR)\8032comm.obj" \
	"$(INTDIR)\8032comm.res" \
	"$(INTDIR)\8032commDoc.obj" \
	"$(INTDIR)\8032commView.obj" \
	"$(INTDIR)\ComPort.obj" \
	"$(INTDIR)\DeviceNames.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\Recallset.obj" \
	"$(INTDIR)\RingNr.obj" \
	"$(INTDIR)\SavSett.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\8032comm.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "8032comm - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\8032comm.exe"

CLEAN : 
	-@erase "$(INTDIR)\8032comm.obj"
	-@erase "$(INTDIR)\8032comm.pch"
	-@erase "$(INTDIR)\8032comm.res"
	-@erase "$(INTDIR)\8032commDoc.obj"
	-@erase "$(INTDIR)\8032commView.obj"
	-@erase "$(INTDIR)\ComPort.obj"
	-@erase "$(INTDIR)\DeviceNames.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\Monitor.obj"
	-@erase "$(INTDIR)\Recallset.obj"
	-@erase "$(INTDIR)\RingNr.obj"
	-@erase "$(INTDIR)\SavSett.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\8032comm.exe"
	-@erase "$(OUTDIR)\8032comm.ilk"
	-@erase "$(OUTDIR)\8032comm.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /G5 /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /c
# SUBTRACT CPP /YX /Yc /Yu
CPP_PROJ=/nologo /G5 /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_MBCS" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/8032comm.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/8032comm.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/8032comm.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/8032comm.exe" 
LINK32_OBJS= \
	"$(INTDIR)\8032comm.obj" \
	"$(INTDIR)\8032comm.res" \
	"$(INTDIR)\8032commDoc.obj" \
	"$(INTDIR)\8032commView.obj" \
	"$(INTDIR)\ComPort.obj" \
	"$(INTDIR)\DeviceNames.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\Monitor.obj" \
	"$(INTDIR)\Recallset.obj" \
	"$(INTDIR)\RingNr.obj" \
	"$(INTDIR)\SavSett.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\8032comm.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "8032comm - Win32 Release"
# Name "8032comm - Win32 Debug"

!IF  "$(CFG)" == "8032comm - Win32 Release"

!ELSEIF  "$(CFG)" == "8032comm - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "8032comm - Win32 Release"

!ELSEIF  "$(CFG)" == "8032comm - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\8032comm.cpp
DEP_CPP_8032C=\
	".\8032comm.h"\
	".\8032commDoc.h"\
	".\8032commView.h"\
	".\ComPort.h"\
	".\DeviceNames.h"\
	".\MainFrm.h"\
	".\Monitor.h"\
	".\Recallset.h"\
	".\RingNr.h"\
	".\SavSett.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\8032comm.obj" : $(SOURCE) $(DEP_CPP_8032C) "$(INTDIR)"\
 "$(INTDIR)\8032comm.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "8032comm - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /G5 /MT /W4 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/8032comm.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\8032comm.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "8032comm - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /G5 /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)/8032comm.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\8032comm.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\8032comm.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\8032comm.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\8032commDoc.cpp
DEP_CPP_8032CO=\
	".\8032comm.h"\
	".\8032commDoc.h"\
	".\8032commView.h"\
	".\ComPort.h"\
	".\DeviceNames.h"\
	".\Monitor.h"\
	".\Recallset.h"\
	".\RingNr.h"\
	".\SavSett.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\8032commDoc.obj" : $(SOURCE) $(DEP_CPP_8032CO) "$(INTDIR)"\
 "$(INTDIR)\8032comm.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\8032commView.cpp
DEP_CPP_8032COM=\
	".\8032comm.h"\
	".\8032commDoc.h"\
	".\8032commView.h"\
	".\ComPort.h"\
	".\DeviceNames.h"\
	".\Monitor.h"\
	".\Recallset.h"\
	".\RingNr.h"\
	".\SavSett.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\8032commView.obj" : $(SOURCE) $(DEP_CPP_8032COM) "$(INTDIR)"\
 "$(INTDIR)\8032comm.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\8032comm.rc
DEP_RSC_8032COMM=\
	".\res\8032comm.rc2"\
	".\res\bitmap1.bmp"\
	".\res\bmp00001.bmp"\
	".\RES\Lightoff.ico"\
	".\RES\Lighton.ico"\
	".\Res\Phone07.ico"\
	".\RES\W95mbx03.ico"\
	

"$(INTDIR)\8032comm.res" : $(SOURCE) $(DEP_RSC_8032COMM) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\RingNr.cpp
DEP_CPP_RINGN=\
	".\8032comm.h"\
	".\RingNr.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\RingNr.obj" : $(SOURCE) $(DEP_CPP_RINGN) "$(INTDIR)"\
 "$(INTDIR)\8032comm.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DeviceNames.cpp
DEP_CPP_DEVIC=\
	".\8032comm.h"\
	".\8032commDoc.h"\
	".\DeviceNames.h"\
	".\RingNr.h"\
	".\SavSett.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\DeviceNames.obj" : $(SOURCE) $(DEP_CPP_DEVIC) "$(INTDIR)"\
 "$(INTDIR)\8032comm.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\SavSett.cpp
DEP_CPP_SAVSE=\
	".\8032comm.h"\
	".\SavSett.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\SavSett.obj" : $(SOURCE) $(DEP_CPP_SAVSE) "$(INTDIR)"\
 "$(INTDIR)\8032comm.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ComPort.cpp
DEP_CPP_COMPO=\
	".\8032comm.h"\
	".\ComPort.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ComPort.obj" : $(SOURCE) $(DEP_CPP_COMPO) "$(INTDIR)"\
 "$(INTDIR)\8032comm.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Recallset.cpp
DEP_CPP_RECAL=\
	".\8032comm.h"\
	".\Recallset.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Recallset.obj" : $(SOURCE) $(DEP_CPP_RECAL) "$(INTDIR)"\
 "$(INTDIR)\8032comm.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Monitor.cpp
DEP_CPP_MONIT=\
	".\8032comm.h"\
	".\8032commDoc.h"\
	".\8032commView.h"\
	".\ComPort.h"\
	".\DeviceNames.h"\
	".\Monitor.h"\
	".\Recallset.h"\
	".\RingNr.h"\
	".\SavSett.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Monitor.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\8032comm.pch"


# End Source File
# End Target
# End Project
################################################################################
