HEADERS       = glwidget.h \
                window.h \
                mainwindow.h
SOURCES       = glwidget.cpp \
                main.cpp \
                window.cpp \
                mainwindow.cpp

QT += widgets opengl openglwidgets core gui

# install
target.path = $$[QT_INSTALL_EXAMPLES]/opengl/hellogl2
INSTALLS += target
