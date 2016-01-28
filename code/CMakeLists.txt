# Header
#-----------------------------------------------------------------------#
SET(PROJ_NAME "simpleJSON")
PROJECT(${PROJ_NAME})
MESSAGE(" + Adding ${PROJ_NAME} ")				# In info

# Include directories with headers
#-----------------------------------------------------------------------#
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )		# This projects' includes

# Source, macro to find all files. If you add more, regenerate project
#-----------------------------------------------------------------------#
FILE(GLOB ${PROJ_NAME}_HEADERS
    "include/*.h"
)

FILE(GLOB ${PROJ_NAME}_SRC
    "src/*.cpp"
)

# Create Library
#-----------------------------------------------------------------------#
ADD_LIBRARY(${PROJ_NAME} ${${PROJ_NAME}_LIB_TYPE} ${${PROJ_NAME}_HEADERS} ${${PROJ_NAME}_SRC} )

# Link libraries with Project
#-----------------------------------------------------------------------#
#TARGET_LINK_LIBRARIES(${PROJ_NAME} dependencyName)

# Installation files in path
#---------------------------------------------------#
INSTALL(TARGETS ${PROJ_NAME}
        DESTINATION "${${PROJ_MAIN_NAME}_PATH_INSTALL}/${PROJ_NAME}/lib"
        )
INSTALL(FILES ${${PROJ_NAME}_HEADERS}
        DESTINATION "${${PROJ_MAIN_NAME}_PATH_INSTALL}/${PROJ_NAME}/include"
        )

#PRINTBASICINFO(${PROJ_NAME})						# Macro cmake_tools to print, uncomment to add info
MESSAGE(" - Project ${PROJ_NAME} added!")					# Out info
