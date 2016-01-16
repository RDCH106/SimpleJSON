cmake_minimum_required(VERSION 2.8.0)

# Header
#-----------------------------------------------------------------------#
SET(PROJ_MAIN_NAME SimpleJSON)
PROJECT(${PROJ_MAIN_NAME})

# Configure variables
# ------------------------------------------------------------------------------------------------------

# Paths
SET(${PROJ_MAIN_NAME}_PATH_MAIN 	${CMAKE_SOURCE_DIR} 					CACHE PATH "This directory contains initial Path")


# Configure options
# ------------------------------------------------------------------------------------------------------
SET(${PROJ_MAIN_NAME}_BUILD_TEST       	"Build test"            							OFF )

INCLUDE_DIRECTORIES("code/include")

# Source, macro to find all files. If you add more, regenerate project
#-----------------------------------------------------------------------#
FILE(GLOB ${PROJ_MAIN_NAME}_SRC
    "code/src/*.cpp"
)
FILE(GLOB ${PROJ_MAIN_NAME}_HEADERS
    "code/include/*.h"
)

# Create Library
#-----------------------------------------------------------------------#
ADD_LIBRARY(${PROJ_MAIN_NAME} ${${PROJ_MAIN_NAME}_LIB_TYPE} ${${PROJ_MAIN_NAME}_HEADERS} ${${PROJ_MAIN_NAME}_SRC} )

# Create Project
#-----------------------------------------------------------------------#
#IF(${${PROJ_MAIN_NAME}_BUILD_TEST})
		ADD_SUBDIRECTORY(test)

# Installation files in path 
#---------------------------------------------------#
INSTALL(TARGETS ${PROJ_MAIN_NAME}
        DESTINATION "${${PROJ_MAIN_NAME}_PATH_INSTALL}/${PROJ_MAIN_NAME}/lib"
        )
INSTALL(FILES ${${PROJ_MAIN_NAME}_HEADERS}
        DESTINATION "${${PROJ_MAIN_NAME}_PATH_INSTALL}/${PROJ_MAIN_NAME}/include"
        )
        
MESSAGE(" * Project ${PROJ_MAIN_NAME} done!")					# Out info
