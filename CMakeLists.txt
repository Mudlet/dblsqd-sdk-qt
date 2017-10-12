CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

IF(POLICY CMP0020)
  CMAKE_POLICY(SET CMP0020 NEW)
ENDIF()

PROJECT(dblsqd-sdk-qt)

SET(SOURCES
    dblsqd/release.cpp,
    dblsqd/semver.cpp,
    dblsqd/update_dialog.cpp,
    dblsqd/feed.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

FIND_PACKAGE(Qt5Core REQUIRED)
FIND_PACKAGE(Qt5Widgets REQUIRED)
FIND_PACKAGE(Qt5Network REQUIRED)

set(CMAKE_AUTOMOC ON)
