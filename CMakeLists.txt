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
ADD_LIBRARY(${PROJ_NAME} ${${PROJ_MAIN_NAME}_LIB_TYPE} ${${PROJ_NAME}_HEADERS} ${${PROJ_NAME}_SRC} )

# Installation files in path 
#---------------------------------------------------#
INSTALL(TARGETS ${PROJ_NAME}
        DESTINATION "${${PROJ_MAIN_NAME}_PATH_INSTALL}/${PROJ_NAME}/lib"
        )
INSTALL(FILES ${${PROJ_NAME}_HEADERS}
        DESTINATION "${${PROJ_MAIN_NAME}_PATH_INSTALL}/${PROJ_NAME}/include"
        )
        
#PRINTBASICINFO(${PROJ_NAME})
MESSAGE(" * Project ${PROJ_NAME} done!")					# Out info
