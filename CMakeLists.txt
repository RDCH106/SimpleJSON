# TOP Level Configuration
# ------------------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8.0)


# Project name & Configuration & Version
# ------------------------------------------------------------------------------------------------------
SET(PROJ_MAIN_NAME "SimpleJSON-Solution")
SET( ${PROJ_MAIN_NAME}_MAJOR_VERSION 0 CACHE STRING "Major version" FORCE)
SET( ${PROJ_MAIN_NAME}_MINOR_VERSION 8 CACHE STRING "Minor version" FORCE)
SET( ${PROJ_MAIN_NAME}_PATCH_VERSION 0 CACHE STRING "Patch version" FORCE)

PROJECT(${PROJ_MAIN_NAME})

# Include Cmake helpers
# ------------------------------------------------------------------------------------------------------
INCLUDE( cmake/scripts.cmake)
SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

# Configure variables
# ------------------------------------------------------------------------------------------------------

# Our custom Paths
SET(${PROJ_MAIN_NAME}_PATH_MAIN 	${CMAKE_SOURCE_DIR} 					          CACHE PATH "This directory contains initial Path")
SET(${PROJ_MAIN_NAME}_PATH_LIBS 	${PROJECT_BINARY_DIR}/bin				        CACHE PATH "This directory contains all libs")
SET(${PROJ_MAIN_NAME}_PATH_EXE 		${PROJECT_BINARY_DIR}/bin				        CACHE PATH "This directory contains executables")
#SET(${PROJ_MAIN_NAME}_PATH_3RDPARTY 	${CMAKE_SOURCE_DIR}/3rdParty 				CACHE PATH "This directory contains 3rdparty libraries")
SET(${PROJ_MAIN_NAME}_PATH_INSTALL 	${PROJECT_BINARY_DIR}/install/${PROJ_MAIN_NAME} 	CACHE PATH "This directory to install prebuilt")

# Configure options
# ------------------------------------------------------------------------------------------------------
SET(${PROJ_MAIN_NAME}_BUILD_TEST       	OFF            							CACHE BOOL "Build test" )

# Library type
IF(TARGET_PLATFORM STREQUAL TARGET_ANDROID)
  SET(${PROJ_MAIN_NAME}_LIB_TYPE "STATIC" CACHE STRING "Choose static or shared")
ELSEIF(TARGET_PLATFORM STREQUAL TARGET_WIN32)
  SET(${PROJ_MAIN_NAME}_LIB_TYPE "SHARED" CACHE STRING "Choose static or shared")
ELSEIF(TARGET_PLATFORM STREQUAL TARGET_LINUX)
  SET(${PROJ_MAIN_NAME}_LIB_TYPE "SHARED" CACHE STRING "Choose static or shared")
ELSEIF(TARGET_PLATFORM STREQUAL TARGET_APPLE)
  SET(${PROJ_MAIN_NAME}_LIB_TYPE "STATIC" CACHE STRING "Choose static or shared")
ELSEIF(TARGET_PLATFORM STREQUAL TARGET_IOS)
  SET(${PROJ_MAIN_NAME}_LIB_TYPE "STATIC" CACHE STRING "Choose static or shared")
ELSE()
   MESSAGE(FATAL_ERROR "ERROR ${PROJ_MAIN_NAME}_LIB_TYPE")
ENDIF()

# Project Logic
# ------------------------------------------------------------------------------------------------------
IF(NOT TARGET_PLATFORM STREQUAL TARGET_NONE)
  ######################################################################################
  # Logic configuration
  ######################################################################################
  MESSAGE("Adding C++11 flags, NEEDED to be supported by compiler")
  IF(TARGET_PLATFORM STREQUAL TARGET_APPLE)
      SET(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++ ${CMAKE_CXX_FLAGS} ")
  ELSE()
    SET(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} ")
  ENDIF()

  ######################################################################################
  # Print info
  ######################################################################################
  PRINTADVANCEDINFO(${PROJ_MAIN_NAME})

  ADD_SUBDIRECTORY("code")

  IF(${PROJ_MAIN_NAME}_BUILD_TEST)
    MESSAGE(" Info: Test enabled!")
    ADD_SUBDIRECTORY(test)
  ELSE()
    MESSAGE(" Info: Test disabled!")
  ENDIF()

ELSE()
  message(FATAL_ERROR " TARGET no autodetected. Please, select a TARGET manually. ")
ENDIF()
		
#PRINTBASICINFO(${PROJ_MAIN_NAME})						# Macro cmake_tools to print, uncomment to add info
MESSAGE(" * Solution ${PROJ_MAIN_NAME} done!")					# Out info
