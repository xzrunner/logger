cmake_minimum_required(VERSION 3.8)

project(logger)

################################################################################
# Source groups
################################################################################
set(Headers
    "fault.h"
    "global.h"
    "logger.h"
    "printer.h"
)
source_group("Headers" FILES ${Headers})

set(Sources
    "fault.c"
    "global.cpp"
    "logger.c"
    "printer.cpp"
)
source_group("Sources" FILES ${Sources})

set(ALL_FILES
    ${Headers}
    ${Sources}
)

include_directories(${CMAKE_SOURCE_DIR})

add_library(logger STATIC ${ALL_FILES})
