#############################################################################
# Makefile for building: mehdiaplayer
# Generated by qmake (2.01a) (Qt 4.5.3) on: sam. nov. 7 13:25:00 2009
# Project:  mehdiaplayer.pro
# Template: app
# Command: /usr/bin/qmake -unix -o Makefile mehdiaplayer.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_PHONON_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -march=i686 -mtune=generic -O2 -pipe -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -march=i686 -mtune=generic -O2 -pipe -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt/mkspecs/linux-g++ -I. -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include/phonon -I/usr/include -I. -Isrc -I/usr/include/phonon_compat/phonon -I/usr/include/phonon_compat -I/usr/include/phonon/Phonon -Ibuild
LINK          = g++
LFLAGS        = -Wl,-O2
LIBS          = $(SUBLIBS)  -L/usr/lib -lphonon -L/usr/lib -lQtDBus -pthread -pthread -pthread -pthread -pthread -pthread -lQtXml -pthread -pthread -pthread -pthread -pthread -pthread -pthread -pthread -L/usr/X11R6/lib -pthread -pthread -pthread -pthread -pthread -pthread -pthread -pthread -lQtGui -pthread -lpng -lfreetype -lgobject-2.0 -lSM -lICE -pthread -pthread -lXrender -lfontconfig -lXext -lX11 -lQtCore -lz -lm -pthread -lgthread-2.0 -lrt -lglib-2.0 -ldl -lpthread
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/

####### Files

SOURCES       = src/Engine.cpp \
		src/main.cpp \
		src/MehdiaPlayer.cpp \
		src/UI.cpp \
		src/UIPlaylist.cpp \
		src/UIFolder.cpp \
		src/UIControl.cpp \
		src/UISettings.cpp \
		src/MehdiaPlayer_VideoWidget.cpp build/moc_Engine.cpp \
		build/moc_MehdiaPlayer.cpp \
		build/moc_UI.cpp \
		build/moc_UIPlaylist.cpp \
		build/moc_UIFolder.cpp \
		build/moc_UIControl.cpp \
		build/moc_UISettings.cpp \
		build/moc_MehdiaPlayer_VideoWidget.cpp
OBJECTS       = build/Engine.o \
		build/main.o \
		build/MehdiaPlayer.o \
		build/UI.o \
		build/UIPlaylist.o \
		build/UIFolder.o \
		build/UIControl.o \
		build/UISettings.o \
		build/MehdiaPlayer_VideoWidget.o \
		build/moc_Engine.o \
		build/moc_MehdiaPlayer.o \
		build/moc_UI.o \
		build/moc_UIPlaylist.o \
		build/moc_UIFolder.o \
		build/moc_UIControl.o \
		build/moc_UISettings.o \
		build/moc_MehdiaPlayer_VideoWidget.o
DIST          = /usr/share/qt/mkspecs/common/g++.conf \
		/usr/share/qt/mkspecs/common/unix.conf \
		/usr/share/qt/mkspecs/common/linux.conf \
		/usr/share/qt/mkspecs/qconfig.pri \
		/usr/share/qt/mkspecs/features/qt_functions.prf \
		/usr/share/qt/mkspecs/features/qt_config.prf \
		/usr/share/qt/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt/mkspecs/features/default_pre.prf \
		/usr/share/qt/mkspecs/features/release.prf \
		/usr/share/qt/mkspecs/features/default_post.prf \
		/usr/share/qt/mkspecs/features/warn_on.prf \
		/usr/share/qt/mkspecs/features/qt.prf \
		/usr/share/qt/mkspecs/features/unix/thread.prf \
		/usr/share/qt/mkspecs/features/moc.prf \
		/usr/share/qt/mkspecs/features/resources.prf \
		/usr/share/qt/mkspecs/features/uic.prf \
		/usr/share/qt/mkspecs/features/yacc.prf \
		/usr/share/qt/mkspecs/features/lex.prf \
		/usr/share/qt/mkspecs/features/include_source_dir.prf \
		mehdiaplayer.pro
QMAKE_TARGET  = mehdiaplayer
DESTDIR       = 
TARGET        = mehdiaplayer

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: mehdiaplayer.pro  /usr/share/qt/mkspecs/linux-g++/qmake.conf /usr/share/qt/mkspecs/common/g++.conf \
		/usr/share/qt/mkspecs/common/unix.conf \
		/usr/share/qt/mkspecs/common/linux.conf \
		/usr/share/qt/mkspecs/qconfig.pri \
		/usr/share/qt/mkspecs/features/qt_functions.prf \
		/usr/share/qt/mkspecs/features/qt_config.prf \
		/usr/share/qt/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt/mkspecs/features/default_pre.prf \
		/usr/share/qt/mkspecs/features/release.prf \
		/usr/share/qt/mkspecs/features/default_post.prf \
		/usr/share/qt/mkspecs/features/warn_on.prf \
		/usr/share/qt/mkspecs/features/qt.prf \
		/usr/share/qt/mkspecs/features/unix/thread.prf \
		/usr/share/qt/mkspecs/features/moc.prf \
		/usr/share/qt/mkspecs/features/resources.prf \
		/usr/share/qt/mkspecs/features/uic.prf \
		/usr/share/qt/mkspecs/features/yacc.prf \
		/usr/share/qt/mkspecs/features/lex.prf \
		/usr/share/qt/mkspecs/features/include_source_dir.prf \
		/usr/lib/libphonon.prl \
		/usr/lib/libQtDBus.prl \
		/usr/lib/libQtXml.prl \
		/usr/lib/libQtCore.prl \
		/usr/lib/libQtGui.prl
	$(QMAKE) -unix -o Makefile mehdiaplayer.pro
/usr/share/qt/mkspecs/common/g++.conf:
/usr/share/qt/mkspecs/common/unix.conf:
/usr/share/qt/mkspecs/common/linux.conf:
/usr/share/qt/mkspecs/qconfig.pri:
/usr/share/qt/mkspecs/features/qt_functions.prf:
/usr/share/qt/mkspecs/features/qt_config.prf:
/usr/share/qt/mkspecs/features/exclusive_builds.prf:
/usr/share/qt/mkspecs/features/default_pre.prf:
/usr/share/qt/mkspecs/features/release.prf:
/usr/share/qt/mkspecs/features/default_post.prf:
/usr/share/qt/mkspecs/features/warn_on.prf:
/usr/share/qt/mkspecs/features/qt.prf:
/usr/share/qt/mkspecs/features/unix/thread.prf:
/usr/share/qt/mkspecs/features/moc.prf:
/usr/share/qt/mkspecs/features/resources.prf:
/usr/share/qt/mkspecs/features/uic.prf:
/usr/share/qt/mkspecs/features/yacc.prf:
/usr/share/qt/mkspecs/features/lex.prf:
/usr/share/qt/mkspecs/features/include_source_dir.prf:
/usr/lib/libphonon.prl:
/usr/lib/libQtDBus.prl:
/usr/lib/libQtXml.prl:
/usr/lib/libQtCore.prl:
/usr/lib/libQtGui.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile mehdiaplayer.pro

dist: 
	@$(CHK_DIR_EXISTS) build/mehdiaplayer1.0.0 || $(MKDIR) build/mehdiaplayer1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/mehdiaplayer1.0.0/ && $(COPY_FILE) --parents src/Engine.h src/MehdiaPlayer.h src/UI.h src/UIPlaylist.h src/UIFolder.h src/UIControl.h src/UISettings.h src/MehdiaPlayer_VideoWidget.h build/mehdiaplayer1.0.0/ && $(COPY_FILE) --parents src/Engine.cpp src/main.cpp src/MehdiaPlayer.cpp src/UI.cpp src/UIPlaylist.cpp src/UIFolder.cpp src/UIControl.cpp src/UISettings.cpp src/MehdiaPlayer_VideoWidget.cpp build/mehdiaplayer1.0.0/ && (cd `dirname build/mehdiaplayer1.0.0` && $(TAR) mehdiaplayer1.0.0.tar mehdiaplayer1.0.0 && $(COMPRESS) mehdiaplayer1.0.0.tar) && $(MOVE) `dirname build/mehdiaplayer1.0.0`/mehdiaplayer1.0.0.tar.gz . && $(DEL_FILE) -r build/mehdiaplayer1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: build/moc_Engine.cpp build/moc_MehdiaPlayer.cpp build/moc_UI.cpp build/moc_UIPlaylist.cpp build/moc_UIFolder.cpp build/moc_UIControl.cpp build/moc_UISettings.cpp build/moc_MehdiaPlayer_VideoWidget.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) build/moc_Engine.cpp build/moc_MehdiaPlayer.cpp build/moc_UI.cpp build/moc_UIPlaylist.cpp build/moc_UIFolder.cpp build/moc_UIControl.cpp build/moc_UISettings.cpp build/moc_MehdiaPlayer_VideoWidget.cpp
build/moc_Engine.cpp: src/MehdiaPlayer_VideoWidget.h \
		src/Engine.h
	/usr/bin/moc $(DEFINES) $(INCPATH) src/Engine.h -o build/moc_Engine.cpp

build/moc_MehdiaPlayer.cpp: src/Engine.h \
		src/MehdiaPlayer_VideoWidget.h \
		src/UI.h \
		src/UIFolder.h \
		src/UIPlaylist.h \
		src/UISettings.h \
		src/UIControl.h \
		src/MehdiaPlayer.h
	/usr/bin/moc $(DEFINES) $(INCPATH) src/MehdiaPlayer.h -o build/moc_MehdiaPlayer.cpp

build/moc_UI.cpp: src/UIFolder.h \
		src/UIPlaylist.h \
		src/UISettings.h \
		src/UIControl.h \
		src/UI.h
	/usr/bin/moc $(DEFINES) $(INCPATH) src/UI.h -o build/moc_UI.cpp

build/moc_UIPlaylist.cpp: src/UIPlaylist.h
	/usr/bin/moc $(DEFINES) $(INCPATH) src/UIPlaylist.h -o build/moc_UIPlaylist.cpp

build/moc_UIFolder.cpp: src/UIFolder.h
	/usr/bin/moc $(DEFINES) $(INCPATH) src/UIFolder.h -o build/moc_UIFolder.cpp

build/moc_UIControl.cpp: src/UIControl.h
	/usr/bin/moc $(DEFINES) $(INCPATH) src/UIControl.h -o build/moc_UIControl.cpp

build/moc_UISettings.cpp: src/UISettings.h
	/usr/bin/moc $(DEFINES) $(INCPATH) src/UISettings.h -o build/moc_UISettings.cpp

build/moc_MehdiaPlayer_VideoWidget.cpp: src/MehdiaPlayer_VideoWidget.h
	/usr/bin/moc $(DEFINES) $(INCPATH) src/MehdiaPlayer_VideoWidget.h -o build/moc_MehdiaPlayer_VideoWidget.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

build/Engine.o: src/Engine.cpp src/Engine.h \
		src/MehdiaPlayer_VideoWidget.h \
		src/MehdiaPlayer.h \
		src/UI.h \
		src/UIFolder.h \
		src/UIPlaylist.h \
		src/UISettings.h \
		src/UIControl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Engine.o src/Engine.cpp

build/main.o: src/main.cpp src/MehdiaPlayer.h \
		src/Engine.h \
		src/MehdiaPlayer_VideoWidget.h \
		src/UI.h \
		src/UIFolder.h \
		src/UIPlaylist.h \
		src/UISettings.h \
		src/UIControl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/main.o src/main.cpp

build/MehdiaPlayer.o: src/MehdiaPlayer.cpp src/MehdiaPlayer.h \
		src/Engine.h \
		src/MehdiaPlayer_VideoWidget.h \
		src/UI.h \
		src/UIFolder.h \
		src/UIPlaylist.h \
		src/UISettings.h \
		src/UIControl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/MehdiaPlayer.o src/MehdiaPlayer.cpp

build/UI.o: src/UI.cpp src/MehdiaPlayer.h \
		src/Engine.h \
		src/MehdiaPlayer_VideoWidget.h \
		src/UI.h \
		src/UIFolder.h \
		src/UIPlaylist.h \
		src/UISettings.h \
		src/UIControl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/UI.o src/UI.cpp

build/UIPlaylist.o: src/UIPlaylist.cpp src/MehdiaPlayer.h \
		src/Engine.h \
		src/MehdiaPlayer_VideoWidget.h \
		src/UI.h \
		src/UIFolder.h \
		src/UIPlaylist.h \
		src/UISettings.h \
		src/UIControl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/UIPlaylist.o src/UIPlaylist.cpp

build/UIFolder.o: src/UIFolder.cpp src/MehdiaPlayer.h \
		src/Engine.h \
		src/MehdiaPlayer_VideoWidget.h \
		src/UI.h \
		src/UIFolder.h \
		src/UIPlaylist.h \
		src/UISettings.h \
		src/UIControl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/UIFolder.o src/UIFolder.cpp

build/UIControl.o: src/UIControl.cpp src/UIControl.h \
		src/MehdiaPlayer.h \
		src/Engine.h \
		src/MehdiaPlayer_VideoWidget.h \
		src/UI.h \
		src/UIFolder.h \
		src/UIPlaylist.h \
		src/UISettings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/UIControl.o src/UIControl.cpp

build/UISettings.o: src/UISettings.cpp src/MehdiaPlayer.h \
		src/Engine.h \
		src/MehdiaPlayer_VideoWidget.h \
		src/UI.h \
		src/UIFolder.h \
		src/UIPlaylist.h \
		src/UISettings.h \
		src/UIControl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/UISettings.o src/UISettings.cpp

build/MehdiaPlayer_VideoWidget.o: src/MehdiaPlayer_VideoWidget.cpp src/MehdiaPlayer.h \
		src/Engine.h \
		src/MehdiaPlayer_VideoWidget.h \
		src/UI.h \
		src/UIFolder.h \
		src/UIPlaylist.h \
		src/UISettings.h \
		src/UIControl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/MehdiaPlayer_VideoWidget.o src/MehdiaPlayer_VideoWidget.cpp

build/moc_Engine.o: build/moc_Engine.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_Engine.o build/moc_Engine.cpp

build/moc_MehdiaPlayer.o: build/moc_MehdiaPlayer.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_MehdiaPlayer.o build/moc_MehdiaPlayer.cpp

build/moc_UI.o: build/moc_UI.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_UI.o build/moc_UI.cpp

build/moc_UIPlaylist.o: build/moc_UIPlaylist.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_UIPlaylist.o build/moc_UIPlaylist.cpp

build/moc_UIFolder.o: build/moc_UIFolder.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_UIFolder.o build/moc_UIFolder.cpp

build/moc_UIControl.o: build/moc_UIControl.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_UIControl.o build/moc_UIControl.cpp

build/moc_UISettings.o: build/moc_UISettings.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_UISettings.o build/moc_UISettings.cpp

build/moc_MehdiaPlayer_VideoWidget.o: build/moc_MehdiaPlayer_VideoWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_MehdiaPlayer_VideoWidget.o build/moc_MehdiaPlayer_VideoWidget.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

