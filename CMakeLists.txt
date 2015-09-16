cmake_minimum_required(VERSION 2.8.0)

# Header
#-----------------------------------------------------------------------#
SET(PROJ_NAME SimpleJSON)
PROJECT(${PROJ_NAME})

INCLUDE_DIRECTORIES("code/include")

# Source, macro to find all files. If you add more, regenerate project
#-----------------------------------------------------------------------#
FILE(GLOB ${PROJ_NAME}_SRC
    "code/src/*.cpp"
)
FILE(GLOB ${PROJ_NAME}_HEADERS
    "code/include/*.h"
)

# Create Library
#-----------------------------------------------------------------------#
ADD_LIBRARY(${PROJ_NAME} STATIC ${${PROJ_NAME}_HEADERS} ${${PROJ_NAME}_SRC} )

MESSAGE(" * Project ${PROJ_NAME} done!")					# Out info
