#-------------------------------------------------
#
# Qt Projekt Template Computer Grafik SS20
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = P1
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

# Here comes the magic block to be dropped into the .pro
# to make assimp *just work*
# Assimp folder needs to be one directory up on windows.
win32 {
	contains(QT_ARCH, i386) {
		# for 32-bit windows applications
		message(Target: win32)
		LIBS += -L../assimp-mingw32-4.1.0/bin -lassimp
		INCLUDEPATH += ../assimp-mingw32-4.1.0/include		
	} else {
		# for 64-bit windows applications	
		message(Target: x64)
		LIBS += -L../assimp-mingw_w64-5.01/bin -lassimp
		INCLUDEPATH += ../assimp-mingw_w64-5.01/include
	}
} unix {
    message(Target: unix)
    CONFIG += link_pkgconfig
    PKGCONFIG += assimp
}

SOURCES += \
    *.cpp \

HEADERS += \
    *.h \

FORMS += \
    *.ui

DISTFILES += \
    *.frag \
    *.vert
