# call it with: cmake -DCMAKE_INSTALL_PREFIX=<path to install> <path to root dir with top CMakeLists.txt>
# get shared libs and link paths of binary: readelf -d <binary> 

cmake_minimum_required(VERSION 2.6)

# define project name
project(SkinTemplate CXX C)

# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

find_package(TCommon REQUIRED)
include_directories(${TCOMMON_INCLUDE_DIR})
add_definitions(${TCOMMON_DEFINITIONS})
message(STATUS "TTCOMMON_INCLUDE_DIR " ${TCOMMON_INCLUDE_DIR})

find_package(TThreads REQUIRED)
include_directories(${TTHREADS_INCLUDE_DIR})
add_definitions(${TTHREADS_DEFINITIONS})
message(STATUS "TTHREADS_INCLUDE_DIR " ${TTHREADS_INCLUDE_DIR})

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
add_definitions(${EIGEN_DEFINITIONS})
message(STATUS "EIGEN3_INCLUDE_DIR " ${EIGEN3_INCLUDE_DIR})

find_package(Boost REQUIRED)
include_directories(${BOOST_INCLUDE_DIRS})
message(STATUS "Boost_INCLUDE_DIRS  " ${Boost_INCLUDE_DIRS})

find_package(Ftdi REQUIRED)
include_directories(${FTDI_INCLUDE_DIRS})
#add_definitions(${FTDI_DEFINITIONS})
message(STATUS "FTDI_INCLUDE_DIRS " ${FTDI_INCLUDE_DIRS})
message(STATUS "FTDI_LIBRARIES " ${FTDI_LIBRARIES})

find_package(SkinCore REQUIRED)
include_directories(${SKINCORE_INCLUDE_DIRS})
#add_definitions(${SKINCORE_DEFINITIONS})
message(STATUS "SKINCORE_INCLUDE_DIRS   " ${SKINCORE_INCLUDE_DIRS})
#message(STATUS "SKINCORE_LIBRARIES      " ${SKINCORE_LIBRARIES})

find_package(SkinRecon REQUIRED)
include_directories(${SKINRECON_INCLUDE_DIRS})
#add_definitions(${SKINRECON_DEFINITIONS})
message(STATUS "SKINRECON_INCLUDE_DIRS   " ${SKINRECON_INCLUDE_DIRS})
#message(STATUS "SKINRECON_LIBRARIES      " ${SKINRECON_LIBRARIES})

find_package(SkinViz REQUIRED)
include_directories(${SKINVIZ_INCLUDE_DIRS})
#add_definitions(${SKINVIZ_DEFINITIONS})
message(STATUS "SKINVIZ_INCLUDE_DIRS   " ${SKINVIZ_INCLUDE_DIRS})
#message(STATUS "SKINVIZ_LIBRARIES      " ${SKINVIZ_LIBRARIES})

find_package(SkinManagers REQUIRED)
include_directories(${SKINMANAGERS_INCLUDE_DIRS})
#add_definitions(${SKINMANAGERS_DEFINITIONS})
message(STATUS "SKINMANAGERS_INCLUDE_DIRS   " ${SKINMANAGERS_INCLUDE_DIRS})
#message(STATUS "SKINMANAGERS_LIBRARIES      " ${SKINMANAGERS_LIBRARIES})

# OpenGL
find_package(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

# Qt
find_package(Qt4 COMPONENTS QtCore QtGui QtOpenGL REQUIRED)

# add Qt Modules
set(QT_USE_QTNETWORK TRUE)
# set(QT_USE_QTOPENGL TRUE)

# resolve qt dependencies
include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

# add binary path to include path
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

include_directories(include)


###############################################################################
#           Library: skinTasks
###############################################################################

set(LIB_NAME
	skinTasks
)

set(QT_HEADERS
	include/Tasks/LedFeedback.h
	include/Tasks/Recon.h
)

# private headers
set(HEADERS_P
)

set(HEADERS
)

set(SOURCES
	src/Tasks/LedFeedback.cpp
	src/Tasks/Recon.cpp
)

# feed moc
QT4_WRAP_CPP(HEADERS_MOC ${QT_HEADERS})

# add executables
add_library(${LIB_NAME} SHARED ${SOURCES} ${HEADERS} ${HEADERS_P} ${HEADERS_MOC} ${QT_HEADERS})

# link target against qt libs
target_link_libraries(${LIB_NAME}
    ${QT_LIBRARIES}
)

###############################################################################
#          App: skin
###############################################################################

set(APP_NAME
    skin
)

set(QT_HEADERS
    src/Applications/mainwindow.h
    src/Applications/MainConsole.h
)

SET(FORMS
    src/Applications/mainwindow.ui
)

set(HEADERS

)

set(SOURCES
    src/Applications/main.cpp
    src/Applications/mainwindow.cpp
    src/Applications/MainConsole.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

# feed moc
QT4_WRAP_CPP(HEADERS_MOC ${QT_HEADERS})

# feed user interface compiler
QT4_WRAP_UI(FORMS_UI ${FORMS})

# add executables
add_executable(${APP_NAME} ${SOURCES} ${HEADERS} ${HEADERS_MOC} ${FORMS_UI})

# link target against qt libs
target_link_libraries(${APP_NAME}
	skinTasks
    ${QT_LIBRARIES}
    ${SKINMANAGERS_LIBRARIES}
    ${SKINIMPLS_LIBRARIES}
    ${SKINRECON_LIBRARIES}
    ${SKINVIZ_LIBRARIES}
    ${SKINCORE_LIBRARIES}
    ${FTDI_LIBRARIES}
    ${TTHREADS_LIBRARIES}
    ${TCOMMON_LIBRARIES}
    glut
)


###############################################################################
#           Export
###############################################################################

# install
install(FILES "cmake/Find${PROJECT_NAME}.cmake" DESTINATION share/cmake/${PROJECT_NAME} RENAME ${PROJECT_NAME}Config.cmake)
install(FILES "cmake/Find${PROJECT_NAME}.cmake" DESTINATION share/${PACKAGE_NAME}/cmake)

# uninstall target
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
