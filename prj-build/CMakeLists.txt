# the name of the target operating system
SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_C_COMPILER "sdcc")
project(Examples)

# This is a simple build script for small simple projects.
# It is going to clean and rebuild everything to keep thigs simple
file(GLOB exfiles  
    "../prj-main/*.c" 
    "../prj-third-party-componets/*.h"
    "../prj-third-party-componets/*.c"
    "../prj-componets/*.h"
    "../prj-componets/*.c"
    "../*.h"
    "../*.c"
)

# Get main file to uses for naming generated output files
# Note: there should only be one "c" file in prj-main.

file(GLOB mainfile
    "../prj-main/*.c"
)
get_filename_component(mainname ${mainfile} NAME_WE)

##add_executable(testOLED-BangoodDevBoard ../testOLED-BangoodDevBoard.c ${exfiles})
##add_executable(testOLED-BangoodDevBoard ${exfiles})
add_executable(${mainname} ${exfiles})

# here is the target environment is located
# SET(CMAKE_FIND_ROOT_PATH  /usr/share/sdcc /home/alex/sdcc-install )
SET(CMAKE_FIND_ROOT_PATH  /usr/local/share/sdcc ../prj-third-party-componets ../prj-componets . )
include_directories( /usr/local/share/sdcc ../prj-third-party-componets ../prj-componets . )

# adjust the default behaviour of the FIND_XXX() commands:
# search headers and libraries in the target environment, search
# programs in the host environment
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
# SET(CMAKE_C_FLAGS                "-Wall -std=c99" CACHE STRING "c flags" )
SET(CMAKE_C_FLAGS  "-mmcs51  -D FOSC_160000" )
# SET(CMAKE_EXE_LINKER_FLAGS "-std=c++11" CACHE STRING "linker flags" )
SET(CMAKE_EXE_LINKER_FLAGS "--out-fmt-ihx" )

##SET(CMAKE_C_FLAGS_DEBUG          "-g")
##SET(CMAKE_C_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
##SET(CMAKE_C_FLAGS_RELEASE        "-O4 -DNDEBUG")
##SET(CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")
##SET(CMAKE_LINKER  "/usr/bin/llvm-ld-${CLANG_VERSION}" CACHE PATH "linker")
##++add_library(testOLED-BangoodDevBoard testOLED-BangoodDevBoard ${SOURCES})
##target_link_libraries( . )
##target_include_directories(  
##          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
##          )
include_directories( .. ../lib )

