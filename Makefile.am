AUTOMAKE_OPTIONS = foreign
TBLIB_ROOT = /usr/local
AM_CPPFLAGS = -std=c++11 -I/${TBLIB_ROOT}/include/tbsys -I/${TBLIB_ROOT}/include/tbnet

bin_PROGRAMS=CmdProc

CmdProc_SOURCES=main.cpp StudentCmd.cpp TeacherCmd.cpp MainCmd.cpp CmdProc.cpp CzmString.cpp ListProc.cpp TeacherNode.cpp StudentNode.cpp 
CmdProc_LDADD=-lpthread $(TBLIB_ROOT)/lib/libtbsys.a