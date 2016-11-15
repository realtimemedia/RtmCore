#############################################################
# CMake file - part of the Realtime Media project
#############################################################

#############################################################
# Define minimum required CMake version
#############################################################
cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

#############################################################
# Define project name
#############################################################
project(RtmCore)

#############################################################
# Define sources
#############################################################
set(RtmCore_SRCS
    src/librtmcore_global.h
)

##########################################################
# Create library
##########################################################
add_library(RtmCore ${RtmCore_SRCS})
add_library(Rtm::Core ALIAS RtmCore)

##########################################################
# Define dependencies
##########################################################
target_link_libraries(RtmCore
    PUBLIC
        Qt5::Core
)

##########################################################
# Define compile definitions
##########################################################
target_compile_definitions(RtmCore
    PRIVATE
        -DRTMCORE_LIBRARY
)

##########################################################
# Define compile features
##########################################################
target_compile_features(RtmCore
    PRIVATE
)

##########################################################
# Define include directories
##########################################################
target_include_directories(RtmCore
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

##########################################################
# Define properties
##########################################################
set_target_properties(RtmCore
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${RTM_RUNTIME_OUTPUT_DIRECTORY}
        LIBRARY_OUTPUT_DIRECTORY ${RTM_LIBRARY_OUTPUT_DIRECTORY}
        ARCHIVE_OUTPUT_DIRECTORY ${RTM_ARCHIVE_OUTPUT_DIRECTORY}
    VERSION ${RTMCORE_VERSION_STRING}
    SOVERSION ${RTMCORE_VERSION_MAJOR}
)


##########################################################
# Define install binary location
##########################################################
install(TARGETS RtmCore EXPORT RtmCoreConfig
    ARCHIVE  DESTINATION lib/static
    LIBRARY  DESTINATION lib
    RUNTIME  DESTINATION bin
)

##########################################################
# Define install headers location
##########################################################
install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/
    DESTINATION include/RtmCore
    FILES_MATCHING
        PATTERN "*.h"
        PATTERN "*_p.h" EXCLUDE
)

##########################################################
# Make the project importable from the install directory
##########################################################
install(EXPORT RtmCoreConfig DESTINATION share/RtmCore/cmake)

##########################################################
# Make the project importable from the build directory
##########################################################
export(TARGETS RtmCore FILE RtmCoreConfig.cmake)

##########################################################
# Load tests
##########################################################
add_subdirectory(test/auto)
