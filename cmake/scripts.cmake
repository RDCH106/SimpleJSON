# --------------------------------------------------------------
# Indicate CMake 2.7 and above that we don't want to mix relative
#  and absolute paths in linker lib lists.
# Run "cmake --help-policy CMP0003" for more information.
# --------------------------------------------------------------
IF(COMMAND cmake_policy)
  #cmake_policy(SET CMP0003 NEW)
ENDIF()

# 1º Select only one target to compile the code, easier for cross-compiling
# Try to auto detect and set the target parameter
# ------------------------------------------------------------------------------------------------------
SET(TARGET_PLATFORM CACHE STRING "TARGET_NONE")
SET_PROPERTY(CACHE TARGET_PLATFORM PROPERTY STRINGS "TARGET_NONE" "TARGET_ANDROID" "TARGET_WIN32" "TARGET_LINUX" "TARGET_IOS" "TARGET_APPLE")	# List with targets types

MESSAGE("* Autodetecting platform . . .")

IF(NOT CMAKE_TOOLCHAIN_FILE)
  IF(WIN32)
    MESSAGE("     Win32 detected.")
    SET(TARGET_PLATFORM TARGET_WIN32 CACHE STRING "Target Platform" FORCE)
  ELSEIF(APPLE)
    MESSAGE("     APPLE detected.")
    SET(TARGET_PLATFORM TARGET_APPLE CACHE STRING "Target Platform" FORCE)
  ELSE(WIN32)
    MESSAGE("     Linux detected.")
    SET(TARGET_PLATFORM TARGET_LINUX CACHE STRING "Target Platform" FORCE)
  ENDIF(WIN32)
ELSE()
  IF(APPLE)
    MESSAGE("     iOS detected.")
    SET(TARGET_PLATFORM TARGET_IOS CACHE STRING "Target Platform" FORCE)
  ELSE(APPLE)
    MESSAGE("     Android detected.")
    SET(TARGET_PLATFORM TARGET_ANDROID CACHE STRING "Target Platform" FORCE)
  ENDIF(APPLE)
ENDIF()
MESSAGE("")

# 2º Configuration custom build type
# ------------------------------------------------------------------------------------------------------
SET(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
IF(DEFINED CMAKE_BUILD_TYPE AND CMAKE_VERSION VERSION_GREATER "2.8")
  SET_PROPERTY(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${CMAKE_CONFIGURATION_TYPES})
ENDIF()

# 3º Configuration custom type configuration, git status(Shared, static)
# ------------------------------------------------------------------------------------------------------
SET(${PROJ_MAIN_NAME}_LIB_TYPE "STATIC" CACHE STRING "Type of lib")
SET_PROPERTY(CACHE ${PROJ_MAIN_NAME}_LIB_TYPE PROPERTY STRINGS "SHARED" "STATIC")

# 4º Configuration default CMake options
# ------------------------------------------------------------------------------------------------------
SET(LIBRARY_OUTPUT_PATH 	${PROJECT_BINARY_DIR}/bin 	CACHE PATH "Library output" FORCE)
SET(EXECUTABLE_OUTPUT_PATH 	${PROJECT_BINARY_DIR}/bin 	CACHE PATH "Executable output" FORCE)
SET(CMAKE_DEBUG_POSTFIX )                                   # No postfix

# 5º Add these standard paths to the search paths for FIND_LIBRARY
# to find libraries from these locations first
# ------------------------------------------------------------------------------------------------------
 if(UNIX AND NOT ANDROID)
   if(X86_64 OR CMAKE_SIZEOF_VOID_P EQUAL 8)
     if(EXISTS /lib64)
       list(APPEND CMAKE_LIBRARY_PATH /lib64)
     else()
       list(APPEND CMAKE_LIBRARY_PATH /lib)
     endif()
     if(EXISTS /usr/lib64)
       list(APPEND CMAKE_LIBRARY_PATH /usr/lib64)
     else()
       list(APPEND CMAKE_LIBRARY_PATH /usr/lib)
     endif()
   elseif(X86 OR CMAKE_SIZEOF_VOID_P EQUAL 4)
     if(EXISTS /lib32)
       list(APPEND CMAKE_LIBRARY_PATH /lib32)
     else()
       list(APPEND CMAKE_LIBRARY_PATH /lib)
     endif()
     if(EXISTS /usr/lib32)
       list(APPEND CMAKE_LIBRARY_PATH /usr/lib32)
     else()
       list(APPEND CMAKE_LIBRARY_PATH /usr/lib)
     endif()
   endif()
 endif()

# 5º Support C++11 crossplatform
# ------------------------------------------------------------------------------------------------------
 macro(CHECK_FOR_CXX11_COMPILER _VAR)
    message(STATUS "Checking for C++11 compiler")
    set(${_VAR})
    if((MSVC AND (MSVC10 OR MSVC11 OR MSVC12)) OR
       (CMAKE_COMPILER_IS_GNUCXX AND NOT ${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 4.6) OR
       (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND NOT ${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 3.1))
        message(STATUS "Checking for C++11 compiler - available")
		# Add C++11 support
		SET(${_VAR} TRUE)
    else()
        message(STATUS "Checking for C++11 compiler - unavailable")
		# Add C++11 support
		SET(${_VAR} FALSE)
    endif()
endmacro()

# Sets the appropriate flag to enable C++11 support
macro(ENABLE_CXX11)
    # Compiler-specific C++11 activation.
	IF("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
		SET(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} ")
		IF(NOT (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 4.7 OR
			CMAKE_CXX_COMPILER_VERSION VERSION_EQUAL 4.7 OR
			DEFINED CMAKE_TOOLCHAIN_FILE))
			MESSAGE("${PROJECT_NAME} requires g++ 4.7 or greater, your version is ${CMAKE_CXX_COMPILER_VERSION}")
		ELSE()
			MESSAGE("${PROJECT_NAME} GNU compiler use C++11")
		ENDIF()
	elseif ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libstdc++")
		find_package(LLVM REQUIRED CONFIG)
		MESSAGE("${PROJECT_NAME} Clang compiler use C++11")
	else ()
		MESSAGE("${PROJECT_NAME} c++11 works")
	endif ()
endmacro()

macro(ENABLE_SSE)
	IF("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -msse2")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse2")
	elseif (MSVC)
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /arch:SSE2")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /arch:SSE2")
	endif()
endmacro()

MACRO(PRINTADVANCEDINFO PROJ_NAME)
  # INFO
  #---------------------------------------------------
  MESSAGE("")
  MESSAGE("* Project: "  			${PROJ_NAME} )
  MESSAGE("*-----------------------------------------------------------------------------------*" )
  MESSAGE("")
  MESSAGE("  Platform: ")
  MESSAGE("  -------------------------------------------------------------------------------")
  MESSAGE("	Host: "             ${CMAKE_HOST_SYSTEM_NAME} ${CMAKE_HOST_SYSTEM_VERSION} ${CMAKE_HOST_SYSTEM_PROCESSOR})
  MESSAGE("	CrossCompiling: "         ${CMAKE_CROSSCOMPILING})
  IF(CMAKE_CROSSCOMPILING)
    MESSAGE("	Target: "         	${CMAKE_SYSTEM_NAME} ${CMAKE_SYSTEM_VERSION} ${CMAKE_SYSTEM_PROCESSOR})
  ENDIF()
  MESSAGE("")
  MESSAGE("  General Options:" )
  MESSAGE("  -------------------------------------------------------------------------------")
  MESSAGE("	CMake: "            ${CMAKE_VERSION})
  MESSAGE("	CMake generator: "  ${CMAKE_GENERATOR})
  MESSAGE("	CMake build tool: " ${CMAKE_BUILD_TOOL})
  IF(MSVC)
    MESSAGE("	MSVC: "           ${MSVC_VERSION})
  ENDIF()
  IF(CMAKE_GENERATOR MATCHES Xcode)
    MESSAGE("	Xcode: "          ${XCODE_VERSION})
  ENDIF()
  IF(NOT CMAKE_GENERATOR MATCHES "Xcode|Visual Studio")
    MESSAGE("	Configuration:"  ${CMAKE_BUILD_TYPE})
  ENDIF()
  MESSAGE("	Custom platform name: "		${TARGET_PLATFORM_NAME} )
  MESSAGE("	Build Configurations: "		${CMAKE_CONFIGURATION_TYPES} )
  MESSAGE("	Build type: "			${CMAKE_BUILD_TYPE} )
  MESSAGE("	Verbose mode: "			${CMAKE_VERBOSE} )
  MESSAGE("	Target Name: "			${TARGET_PLATFORM} )
  MESSAGE("")
  MESSAGE("  Paths " )
  MESSAGE("  -------------------------------------------------------------------------------")
  MESSAGE("	Root: "				${${PROJ_NAME}_PATH_MAIN} )
  MESSAGE("	Data: "				${${PROJ_NAME}_PATH_DATA} )
  MESSAGE("	Libs: "				${${PROJ_NAME}_PATH_LIBS} )
  MESSAGE("	Installation: "			${${PROJ_NAME}_PATH_INSTALL} )
  MESSAGE("	Executable: "			${EXECUTABLE_OUTPUT_PATH} )
  MESSAGE("	Binary: "				${PROJECT_BINARY_DIR} )
  MESSAGE("")

  MESSAGE("  Project Bool Options " )
  MESSAGE("  -------------------------------------------------------------------------------")
  MESSAGE("	Samples: "			${${PROJECT_NAME}_BUILD_SAMPLES} )
  MESSAGE("	Docs: "				${${PROJECT_NAME}_BUILD_DOCS} )
  MESSAGE("")

  # ========================== C/C++ options ==========================
  MESSAGE("  C/C++:")
  MESSAGE("  -------------------------------------------------------------------------------")
  MESSAGE("	Precompiled headers:"     PCHSupport_FOUND AND ENABLE_PRECOMPILED_HEADERS THEN YES ELSE NO)
  MESSAGE("	Built as dynamic libs?:" BUILD_SHARED_LIBS THEN YES ELSE NO)
  MESSAGE("	C++ Compiler:"           CMAKE_COMPILER_IS_GNUCXX THEN "${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_ARG1} (ver ${CMAKE_GCC_REGEX_VERSION})" ELSE "${CMAKE_CXX_COMPILER}" )
  MESSAGE("	C++ flags (Release):"    ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE})
  MESSAGE("	C++ flags (Debug):"      ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG})
  MESSAGE("	C Compiler:"             ${CMAKE_C_COMPILER} ${CMAKE_C_COMPILER_ARG1})
  MESSAGE("	C flags (Release):"      ${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_RELEASE})
  MESSAGE("	C flags (Debug):"        ${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_DEBUG})
  MESSAGE("	Linker flags exe (Release):" ${CMAKE_EXE_LINKER_FLAGS} ${CMAKE_EXE_LINKER_FLAGS_RELEASE})
  MESSAGE("	Linker flags exe (Debug):"   ${CMAKE_EXE_LINKER_FLAGS} ${CMAKE_EXE_LINKER_FLAGS_DEBUG})
  MESSAGE("	Linker flags shared (Release):" ${CMAKE_SHARED_LINKER_FLAGS} ${CMAKE_SHARED_LINKER_FLAGS_RELEASE})
  MESSAGE("	Linker flags shared (Debug):"   ${CMAKE_SHARED_LINKER_FLAGS} ${CMAKE_SHARED_LINKER_FLAGS_DEBUG})
  MESSAGE("")

  # ========================== Android details ==========================
IF(TARGET_PLATFORM STREQUAL TARGET_ANDROID)
    MESSAGE("  Android: ")
    MESSAGE("  -------------------------------------------------------------------------------")
    MESSAGE("	Android ABI:" ${ANDROID_ABI})
    MESSAGE("	Native API level:" android-${ANDROID_NATIVE_API_LEVEL})
    MESSAGE("	SDK target:" "${ANDROID_SDK_TARGET}")
    MESSAGE("	Android NDK:" "${ANDROID_NDK} (toolchain: ${ANDROID_TOOLCHAIN_NAME})")
    MESSAGE("")
ENDIF(TARGET_PLATFORM STREQUAL TARGET_ANDROID)

  # ========================== iOS details ==========================
IF( TARGET_PLATFORM_NAME STREQUAL iOS )
  MESSAGE("  iOS: ")
  MESSAGE("  -------------------------------------------------------------------------------")
  MESSAGE("	Platform:"    		${IOS_PLATFORM} )
  MESSAGE("	SDK Root:"    		${CMAKE_IOS_SDK_ROOT} )
  MESSAGE("	Architectures:"    		${CMAKE_OSX_ARCHITECTURES} )
  MESSAGE("	Deployment Target:"    	${CMAKE_OSX_DEPLOYMENT_TARGET} )
  MESSAGE("    	Framework Search Path:"	    	${CMAKE_FRAMEWORK_PATH} )
  MESSAGE("	OSX SYSROOT:"	    	${CMAKE_OSX_SYSROOT} )
  MESSAGE("")
ENDIF()

  MESSAGE("")
  MESSAGE("   ***********************************************************************************************")
  MESSAGE("")
  MESSAGE("     oooOOOOOOOOOOO    Piperoman 2010-2016     ${PROJ_NAME}  ")
  MESSAGE("     o   ____          :::::::::::::::::: :::::::::::::::::: __|-----|__")
  MESSAGE("     Y_,_|[]| --++++++ |[][][][][][][][]| |[][][][][][][][]| |  [] []  |")
  MESSAGE("    {|_|_|__|;|______|;|________________|;|________________|;|_________|;")
  MESSAGE("     /oo--OO   oo  oo   oo oo      oo oo   oo oo      oo oo   oo     oo")
  MESSAGE("  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+")
  MESSAGE("")
  MESSAGE("   ***********************************************************************************************")
  MESSAGE("")

ENDMACRO()

MACRO(PRINTBASICINFO PROJ_NAME)
# Test printing
MESSAGE(" ")
MESSAGE("--- Project: ${PROJ_NAME} information ------------------------------------------")
MESSAGE("--------------------------------------------------------------------------------")
MESSAGE("*** Include directories:")
  # Include DIRECTORIES
  GET_PROPERTY(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
  FOREACH(dir ${dirs})
    MESSAGE(" * '${dir}'")
  ENDFOREACH()

MESSAGE("--------------------------------------------------------------------------------")
MESSAGE("*** Link directories:")
  # Link DIRECTORIES
  GET_PROPERTY(targetdirlinks DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY LINK_DIRECTORIES)
  FOREACH(linkdir ${targetdirlinks})
    MESSAGE(" * '${linkdir}'")
  ENDFOREACH()

MESSAGE("--------------------------------------------------------------------------------")
MESSAGE("*** Link libraries:")
  # Linking against
  GET_TARGET_PROPERTY(libtargets ${PROJ_NAME} LINK_LIBRARIES)
  FOREACH(libtarget ${libtargets})
    MESSAGE(" * '${libtarget}'")
  ENDFOREACH()

MESSAGE("--------------------------------------------------------------------------------")
MESSAGE(" ")
ENDMACRO()
