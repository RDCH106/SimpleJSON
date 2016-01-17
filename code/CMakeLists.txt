# Header
#-----------------------------------------------------------------------#
SET(PROJ_MAIN_NAME "simpleJSON")
PROJECT(${PROJ_MAIN_NAME})
MESSAGE(" + Adding ${PROJ_NAME} ")				# In info

# Include directories with headers
#-----------------------------------------------------------------------#
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )		# This projects' includes

# Source, macro to find all files. If you add more, regenerate project
#-----------------------------------------------------------------------#
FILE(GLOB ${PROJ_MAIN_NAME}_HEADERS
    "include/*.h"
)

FILE(GLOB ${PROJ_MAIN_NAME}_SRC
    "src/*.cpp"
)

# Create Library
#-----------------------------------------------------------------------#
ADD_LIBRARY(${PROJ_MAIN_NAME} ${${PROJ_MAIN_NAME}_LIB_TYPE} ${${PROJ_MAIN_NAME}_HEADERS} ${${PROJ_MAIN_NAME}_SRC} )

# Link libraries with Project
#-----------------------------------------------------------------------#
#TARGET_LINK_LIBRARIES(${PROJ_NAME} dependencyName)

# Installation files in path 
#---------------------------------------------------#
INSTALL(TARGETS ${PROJ_MAIN_NAME}
        DESTINATION "${${PROJ_MAIN_NAME}_PATH_INSTALL}/${PROJ_MAIN_NAME}/lib"
        )
INSTALL(FILES ${${PROJ_MAIN_NAME}_HEADERS}
        DESTINATION "${${PROJ_MAIN_NAME}_PATH_INSTALL}/${PROJ_MAIN_NAME}/include"
        )

#PRINTBASICINFO(${PROJ_MAIN_NAME})						# Macro cmake_tools to print, uncomment to add info
MESSAGE(" - Project ${PROJ_MAIN_NAME} added!")					# Out info
