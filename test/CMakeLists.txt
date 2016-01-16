# Header
#-----------------------------------------------------------------------#
SET(PROJ_NAME SimpleJSON_test)
PROJECT(${PROJ_NAME})
MESSAGE(" + Adding test ${PROJ_NAME} ")				# In info

# Include directories with headers
#-----------------------------------------------------------------------#
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )			# This project includes
INCLUDE_DIRECTORIES( ${${PROJ_MAIN_NAME}_PATH_MAIN}/code/include )


# Source, macro to find all files. If you add more, regenerate project
#-----------------------------------------------------------------------#
file(GLOB ${PROJ_NAME}_INCLUDE
   ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
   ${CMAKE_CURRENT_SOURCE_DIR}/include/*.rc
)

file(GLOB ${PROJ_NAME}_SRC
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

file(GLOB ${PROJ_NAME}_JSON
	${CMAKE_CURRENT_SOURCE_DIR}/test_cases/*.json
)

add_executable(${PROJ_NAME} ${${PROJ_NAME}_INCLUDE} ${${PROJ_NAME}_SRC} ${${PROJ_NAME}_JSON})

# Link libraries with Project
#-----------------------------------------------------------------------#
target_link_libraries( ${PROJ_NAME}
	SimpleJSON
)

MESSAGE(" - Project ${PROJ_NAME} added!")					# Out info