# CmdProc
This is a generic list ,you can use it by cmd. 
* if you want to run this program,you should install tb-common-util and googletest-release-1.7.0. the way to install it I will write next time.

tb-common-util:
* git clone https://github.com/basketballCzm/tb-common-utils.git /home/tb-common-utils
* chmod u+x /home/tb-common-utils/build.sh
* TBLIB_ROOT=/usr/local /home/tb-common-utils/build.sh

googletest-release-1.7.0
* cd /opt && wget https://github.com/google/googletest/archive/release-1.7.0.tar.gz && tar xvf release-1.7.0.tar.gz &&  mv googletest-release-1.7.0 gtest-1.7.0
* yum install -y cmake
* cd /opt/gtest-1.7.0 && cmake . && make -j6

* if you are zhouran. you maybe can run this program,and you can write printf and scanf in single .cpp file first.

---

* I want to write rewrite printf and scanf. but I can not achieve it in Centos7 64 bit. I write print and scan in IO file. if you want to help me solve it .you can visit my blog  http://czm.farbox.com/post/2017-05-16  .I record the detail in it.