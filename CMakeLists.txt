CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

OPTION(BUILD_WITH_QT5 "Whether to build with Qt5 or Qt6." ON)

IF(POLICY CMP0020)
  CMAKE_POLICY(SET CMP0020 NEW)
ENDIF()

PROJECT(dblsqd-sdk-qt)

SET(SOURCES
  dblsqd/release.cpp
  dblsqd/semver.cpp
  dblsqd/update_dialog.cpp
  dblsqd/feed.cpp
)

SET(HEADERS
  dblsqd/release.h
  dblsqd/semver.h
  dblsqd/update_dialog.h
  dblsqd/feed.h
)

IF(BUILD_WITH_QT5)
  FIND_PACKAGE(Qt5 REQUIRED
    COMPONENTS Core
    Network
	Widgets)
	SET(QT_LIBS Qt5::Core Qt5::Network Qt5::Widgets)
ELSE()
  FIND_PACKAGE(Qt6 REQUIRED
    COMPONENTS Core
	Network
	Widgets)
  SET(QT_LIBS Qt6::Core Qt6::Network Qt6::Widgets)
ENDIF()

# Qt 5.7 or greater require C++11 standard. Set this requirement conditionally to lower requirements where possible
IF(NOT BUILD_WITH_QT5)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
ELSEIF(Qt5Core_VERSION VERSION_EQUAL 5.7 OR Qt5Core_VERSION VERSION_GREATER 5.7)
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
ENDIF()

# automatically use moc and uic when needed
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

ADD_LIBRARY(dblsqd STATIC
  ${SOURCES} ${HEADERS}
)

TARGET_LINK_LIBRARIES(dblsqd
	${QT_LIBS})

# publish the include directories to allow dependent projects to find the needed headers
TARGET_INCLUDE_DIRECTORIES(dblsqd PUBLIC
# the includes below are needed to find generated uic headers
# see https://gitlab.kitware.com/cmake/cmake/issues/16925
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}/dblsqd_autogen/include
  ${CMAKE_CURRENT_BINARY_DIR}/dblsqd_autogen/include_$<CONFIG>
  ${CMAKE_CURRENT_SOURCE_DIR}
)
