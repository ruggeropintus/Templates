CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(projectName)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Ofast -std=c++20 -lstdc++fs")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -std=c++20 -lstdc++fs")
## set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++20 -lstdc++fs")
## set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -lstdc++fs")
## set(CMAKE_VERBOSE_MAKEFILE ON)

############## Required Libraries

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake_modules" )
## set(CMAKE_AUTOMOC ON)

## find_package(Eigen3     REQUIRED)

############## Default target to build

if(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

MESSAGE("Compiled in ${CMAKE_BUILD_TYPE}")

SET(CMAKE_EXPORT_COMPILE_COMMANDS 1)
MESSAGE("Export compile commands: ${CMAKE_EXPORT_COMPILE_COMMANDS}")

message ("CMake C Flags pre: ${CMAKE_C_FLAGS}")
message ("CMake CXX Flags pre: ${CMAKE_CXX_FLAGS}")

############## Output to the "bin" and "lib" folders

SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )
SET( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib )
foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
	STRING( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
	SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/bin )
	SET( CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/lib )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

######## Includes for everybody ############

INCLUDE_DIRECTORIES( "${PROJECT_SOURCE_DIR}/src" )
# INCLUDE_DIRECTORIES( ${EIGEN3_INCLUDE_DIR} )

######## Install directories ############

## SET( INSTALL_INCLUDE_DIR /usr/local/include/vic/mlic )
## SET( INSTALL_LIB_DIR /usr/local/lib64 )
## SET( INSTALL_BIN_DIR /usr/local/bin )

MESSAGE("Install include dir: ${INSTALL_INCLUDE_DIR}")
MESSAGE("Install lib dir: ${INSTALL_LIB_DIR}")
MESSAGE("Install bin dir: ${INSTALL_BIN_DIR}")

##### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ##### 
##### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #####
##### @@@@@ LIBRARIES @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #####
##### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #####
##### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #####

#############################################################
##### LIBRARY NAME ##########################################
#############################################################

## ADD_LIBRARY( library_name # SHARED
##      ## src/base/tile.hpp
##      ## src/base/tile.cpp
## )
## 
## set_target_properties(library_name PROPERTIES LINKER_LANGUAGE CXX)
## ## target_compile_options(library_name PRIVATE -Werror -Wall -Wextra)
## 
## TARGET_LINK_LIBRARIES( library_name
##      ## ${EIGEN3_LIBRARIES}
## )
## 
## ## file(GLOB config_files "src/base/*.hpp")
## install (FILES ${config_files} DESTINATION ${INSTALL_INCLUDE_DIR})
## install (TARGETS library_name DESTINATION ${INSTALL_LIB_DIR})

##### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ##### 
##### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #####
##### @@@@@ APPS @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #####
##### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #####
##### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ #####

#############################################################
##### APP NAME ##############################################
#############################################################

## ADD_EXECUTABLE ( app_name
##      ## src/apps/apx_builder/main_apx_builder.cpp
## )
## 
## set_target_properties(app_name PROPERTIES LINKER_LANGUAGE CXX)
## 
## TARGET_LINK_LIBRARIES( app_name
##      ## ${EIGEN3_LIBRARIES}
## )
## 
## install (TARGETS app_name DESTINATION ${INSTALL_BIN_DIR})