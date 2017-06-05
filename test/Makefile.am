AUTOMAKE_OPTIONS = foreign
TBLIB_ROOT = /usr/local
GTEST_ROOT = /opt/gtest-1.7.0
AM_CPPFLAGS = -std=c++11 -I/${TBLIB_ROOT}/include/tbsys -I/${TBLIB_ROOT}/include/tbnet \
              -I/${GTEST_ROOT}/include -I/${GTEST_ROOT}

bin_PROGRAMS=test_CmdProc test_CmdProcList

test_CmdProc_SOURCES=CzmString_test.cpp ../CzmString.cpp $(GTEST_ROOT)/src/gtest-all.cc
test_CmdProc_LDADD=-lpthread $(TBLIB_ROOT)/lib/libtbsys.a  $(GTEST_ROOT)/libgtest_main.a

test_CmdProcList_SOURCES=ListProc_test.cpp ../CzmString.cpp ../CmdProc.cpp ../MainCmd.cpp   ../ListProc.cpp ../StudentCmd.cpp ../StudentNode.cpp ../TeacherCmd.cpp ../TeacherNode.cpp  $(GTEST_ROOT)/src/gtest-all.cc
test_CmdProcList_LDADD=-lpthread $(TBLIB_ROOT)/lib/libtbsys.a  $(GTEST_ROOT)/libgtest_main.a
