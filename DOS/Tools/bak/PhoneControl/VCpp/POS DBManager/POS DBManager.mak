# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=POS DBManager - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to POS DBManager - Win32\
 Debug.
!ENDIF 

!IF "$(CFG)" != "POS DBManager - Win32 Release" && "$(CFG)" !=\
 "POS DBManager - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "POS DBManager.mak" CFG="POS DBManager - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "POS DBManager - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "POS DBManager - Win32 Debug" (based on "Win32 (x86) Application")
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
# PROP Target_Last_Scanned "POS DBManager - Win32 Debug"
RSC=rc.exe
CPP=cl.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "POS DBManager - Win32 Release"

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

ALL : "$(OUTDIR)\POS DBManager.exe"

CLEAN : 
	-@erase "$(INTDIR)\POS DBManager.obj"
	-@erase "$(INTDIR)\POS DBManager.pch"
	-@erase "$(INTDIR)\POS DBManager.res"
	-@erase "$(INTDIR)\POS DBManagerDlg.obj"
	-@erase "$(INTDIR)\PosRunDb.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\POS DBManager.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/POS DBManager.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x807 /d "NDEBUG"
# ADD RSC /l 0x807 /d "NDEBUG"
RSC_PROJ=/l 0x807 /fo"$(INTDIR)/POS DBManager.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/POS DBManager.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/POS DBManager.pdb" /machine:I386\
 /out:"$(OUTDIR)/POS DBManager.exe" 
LINK32_OBJS= \
	"$(INTDIR)\POS DBManager.obj" \
	"$(INTDIR)\POS DBManager.res" \
	"$(INTDIR)\POS DBManagerDlg.obj" \
	"$(INTDIR)\PosRunDb.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\POS DBManager.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "POS DBManager - Win32 Debug"

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

ALL : "$(OUTDIR)\POS DBManager.exe" "$(OUTDIR)\POS DBManager.bsc"

CLEAN : 
	-@erase "$(INTDIR)\POS DBManager.obj"
	-@erase "$(INTDIR)\POS DBManager.pch"
	-@erase "$(INTDIR)\POS DBManager.res"
	-@erase "$(INTDIR)\POS DBManager.sbr"
	-@erase "$(INTDIR)\POS DBManagerDlg.obj"
	-@erase "$(INTDIR)\POS DBManagerDlg.sbr"
	-@erase "$(INTDIR)\PosRunDb.obj"
	-@erase "$(INTDIR)\PosRunDb.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\POS DBManager.bsc"
	-@erase "$(OUTDIR)\POS DBManager.exe"
	-@erase "$(OUTDIR)\POS DBManager.ilk"
	-@erase "$(OUTDIR)\POS DBManager.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/POS DBManager.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x807 /d "_DEBUG"
# ADD RSC /l 0x807 /d "_DEBUG"
RSC_PROJ=/l 0x807 /fo"$(INTDIR)/POS DBManager.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/POS DBManager.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\POS DBManager.sbr" \
	"$(INTDIR)\POS DBManagerDlg.sbr" \
	"$(INTDIR)\PosRunDb.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\POS DBManager.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/POS DBManager.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/POS DBManager.exe" 
LINK32_OBJS= \
	"$(INTDIR)\POS DBManager.obj" \
	"$(INTDIR)\POS DBManager.res" \
	"$(INTDIR)\POS DBManagerDlg.obj" \
	"$(INTDIR)\PosRunDb.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\POS DBManager.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "POS DBManager - Win32 Release"
# Name "POS DBManager - Win32 Debug"

!IF  "$(CFG)" == "POS DBManager - Win32 Release"

!ELSEIF  "$(CFG)" == "POS DBManager - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "POS DBManager - Win32 Release"

!ELSEIF  "$(CFG)" == "POS DBManager - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=".\POS DBManager.cpp"
DEP_CPP_POS_D=\
	".\POS DBManager.h"\
	".\POS DBManagerDlg.h"\
	".\PosRunDb.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "POS DBManager - Win32 Release"


"$(INTDIR)\POS DBManager.obj" : $(SOURCE) $(DEP_CPP_POS_D) "$(INTDIR)"\
 "$(INTDIR)\POS DBManager.pch"


!ELSEIF  "$(CFG)" == "POS DBManager - Win32 Debug"


"$(INTDIR)\POS DBManager.obj" : $(SOURCE) $(DEP_CPP_POS_D) "$(INTDIR)"\
 "$(INTDIR)\POS DBManager.pch"

"$(INTDIR)\POS DBManager.sbr" : $(SOURCE) $(DEP_CPP_POS_D) "$(INTDIR)"\
 "$(INTDIR)\POS DBManager.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=".\POS DBManagerDlg.cpp"
DEP_CPP_POS_DB=\
	".\POS DBManager.h"\
	".\POS DBManagerDlg.h"\
	".\PosRunDb.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "POS DBManager - Win32 Release"


"$(INTDIR)\POS DBManagerDlg.obj" : $(SOURCE) $(DEP_CPP_POS_DB) "$(INTDIR)"\
 "$(INTDIR)\POS DBManager.pch"


!ELSEIF  "$(CFG)" == "POS DBManager - Win32 Debug"


"$(INTDIR)\POS DBManagerDlg.obj" : $(SOURCE) $(DEP_CPP_POS_DB) "$(INTDIR)"\
 "$(INTDIR)\POS DBManager.pch"

"$(INTDIR)\POS DBManagerDlg.sbr" : $(SOURCE) $(DEP_CPP_POS_DB) "$(INTDIR)"\
 "$(INTDIR)\POS DBManager.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "POS DBManager - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS"\
 /Fp"$(INTDIR)/POS DBManager.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\POS DBManager.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "POS DBManager - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/POS DBManager.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\StdAfx.sbr" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\POS DBManager.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=".\POS DBManager.rc"
DEP_RSC_POS_DBM=\
	".\res\POS DBManager.ico"\
	".\res\POS DBManager.rc2"\
	

"$(INTDIR)\POS DBManager.res" : $(SOURCE) $(DEP_RSC_POS_DBM) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PosRunDb.cpp
DEP_CPP_POSRU=\
	".\POS DBManager.h"\
	".\PosRunDb.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "POS DBManager - Win32 Release"


"$(INTDIR)\PosRunDb.obj" : $(SOURCE) $(DEP_CPP_POSRU) "$(INTDIR)"\
 "$(INTDIR)\POS DBManager.pch"


!ELSEIF  "$(CFG)" == "POS DBManager - Win32 Debug"


"$(INTDIR)\PosRunDb.obj" : $(SOURCE) $(DEP_CPP_POSRU) "$(INTDIR)"\
 "$(INTDIR)\POS DBManager.pch"

"$(INTDIR)\PosRunDb.sbr" : $(SOURCE) $(DEP_CPP_POSRU) "$(INTDIR)"\
 "$(INTDIR)\POS DBManager.pch"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
