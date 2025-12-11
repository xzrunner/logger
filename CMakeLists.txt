cmake_minimum_required(VERSION 3.16)

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

add_library(${PROJECT_NAME} STATIC ${ALL_FILES})
