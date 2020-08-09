cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_VERBOSE_MAKEFILE on)
message("heap snapshot compile begin.....")
message(STATUS ${CMAKE_SOURCE_DIR})
message(STATUS ${PROJECT_SOURCE_DIR})

#add_definitions(-Wno-error)
# -DPLATFORM_SDK_VERSION
set(CMAKE_C_FLAGS "$ENV{CFLAGS} -Wno-error")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/../bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../lib)

set(libs ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${libs}")

include_directories(${CMAKE_SOURCE_DIR}/heapsnap/include)
#add_library(c_malloc_debug
#        SHARED
#        IMPORTED)
#set_target_properties(c_malloc_debug
#        PROPERTIES IMPORTED_LOCATION
#        ${CMAKE_SOURCE_DIR}/heapsnap/${ANDROID_ABI}/libc_malloc_debug.so)

set(SRCS
        ${CMAKE_SOURCE_DIR}/heapsnap/inject.c
        ${CMAKE_SOURCE_DIR}/heapsnap/process_util.c
        ${CMAKE_SOURCE_DIR}/heapsnap/ptrace_util.c)
add_executable(heap-snap ${SRCS})

add_executable(leak-test ${CMAKE_SOURCE_DIR}/heapsnap/leak_test.c)
#native-lib.cpp
add_library(
        heapsnap
        SHARED
        ${CMAKE_SOURCE_DIR}/heapsnap/heapsnap.cpp)

find_library(
              log-lib
              log )
target_link_libraries(
        heapsnap
        c_malloc_debug
        dl
        ${log-lib})
