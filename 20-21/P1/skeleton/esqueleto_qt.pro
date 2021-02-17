HEADERS += \
  colors.h \
  basic_object3d.h \
  cone.h \
  cube.h \
  cylinder.h \
  object3d.h \
  axis.h \
  object_ply.h \
  object_revolution.h \
  tetrahedron.h \
  glwidget.h \
  window.h \
  file_ply_stl.h

SOURCES += \
  basic_object3d.cc \
  cone.cpp \
  cube.cc \
  cylinder.cpp \
  object3d.cc \
  axis.cc \
  object_ply.cpp \
  object_revolution.cpp \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc \
  file_ply_stl.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
