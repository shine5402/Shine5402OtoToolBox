QT += testlib
QT += gui core
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_removeduplicatetest.cpp \
    ../../lib/diff-match-patch/diff_match_patch.cpp \
    ../../src/toolBase/tooldialog.cpp \
    ../../src/removeDuplicate/removeduplicatedialogadapter.cpp \
    ../../src/removeDuplicate/removeduplicatedialogoptionwidget.cpp \
    ../../src/toolBase/tooldialogadapter.cpp \
    ../../src/toolBase/tooloptions.cpp \
    ../../src/toolBase/tooloptionwidget.cpp \
    ../../src/utils/dialogs/showdiffdialog.cpp \
    ../../src/utils/dialogs/showotolistdialog.cpp \
    ../../src/utils/dialogs/tableviewdialog.cpp \
    ../../src/utils/models/otolistmodel.cpp \
    ../../src/utils/models/otolistshowvaluechangemodel.cpp \
    ../../src/utils/widgets/filenameeditwithbrowse.cpp \
    ../../src/utils/widgets/otofileloadwidget.cpp \
    ../../src/utils/widgets/otofilenameeditwithbrowse.cpp \
    ../../src/utils/widgets/otofilesavewidget.cpp \
    ../../src/utils/widgets/stringlistmodifywidget.cpp

FORMS += \
    ../../src/removeDuplicate/removeduplicatedialogoptionwidget.ui \
    ../../src/toolBase/tooldialog.ui \
    ../../src/utils/dialogs/showdiffdialog.ui \
    ../../src/utils/widgets/filenameeditwithbrowse.ui \
    ../../src/utils/widgets/otofileloadwidget.ui \
    ../../src/utils/widgets/otofilesavewidget.ui \
    ../../src/utils/widgets/stringlistmodifywidget.ui

HEADERS += \
    ../../lib/diff-match-patch/diff_match_patch.h \
    ../../src/toolBase/tooldialog.h \
    ../../src/removeDuplicate/removeduplicatedialogadapter.h \
    ../../src/removeDuplicate/removeduplicatedialogoptionwidget.h \
    ../../src/toolBase/tooldialogadapter.h \
    ../../src/toolBase/tooloptions.h \
    ../../src/toolBase/tooloptionwidget.h \
    ../../src/utils/dialogs/showdiffdialog.h \
    ../../src/utils/dialogs/showotolistdialog.h \
    ../../src/utils/dialogs/tableviewdialog.h \
    ../../src/utils/models/otolistmodel.h \
    ../../src/utils/models/otolistshowvaluechangemodel.h \
    ../../src/utils/widgets/filenameeditwithbrowse.h \
    ../../src/utils/widgets/otofileloadwidget.h \
    ../../src/utils/widgets/otofilenameeditwithbrowse.h \
    ../../src/utils/widgets/otofilesavewidget.h \
    ../../src/utils/widgets/stringlistmodifywidget.h

DEFINES += SHINE5402OTOBOX_TEST

INCLUDEPATH += ../../src/
DEPENDPATH += ../../src/

include(include.pri)

RESOURCES += \
    resources.qrc
