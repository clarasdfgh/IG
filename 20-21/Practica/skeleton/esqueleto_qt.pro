HEADERS += \
  colors.h \
  basic_object3d.h \
  cone.h \
  cube.h \
  cylinder.h \
  file_ply_stl.h \
  object3d.h \
  axis.h \
  ply_object.h \
  rev_object.h \
  sphere.h \
  tetrahedron.h \
  glwidget.h \
  window.h

SOURCES += \
  basic_object3d.cc \
  cone.cpp \
  cube.cpp \
  cylinder.cpp \
  file_ply_stl.cpp \
  object3d.cc \
  axis.cc \
  ply_object.cpp \
  rev_object.cpp \
  sphere.cpp \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
