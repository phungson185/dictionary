cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(dict)

set(CMAKE_C_STANDARD 99)
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif (NOT CMAKE_BUILD_TYPE)

include_directories(${PROJECT_SOURCE_DIR}/lib)
link_directories(${PROJECT_SOURCE_DIR}/lib/blib)

include_directories(${PROJECT_SOURCE_DIR}/cmake-btree/inc)
link_directories(${PROJECT_SOURCE_DIR}/cmake-btree/lib)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER} -rdynamic)

message(STATUS "Include: ${GTK3_INCLUDE_DIRS}\n LIB_DIR: ${GTK3_LIBRARY_DIRS} \n CFLAGS_OTHERS: ${GTK3_CFLAGS_OTHER} \n LIBS: ${GTK3_LIBRARIES}")

include_directories(${PROJECT_SOURCE_DIR}/igraph)

option(GPROF_FLAG "Bổ xung khóa để sử dụng với gprof" OFF)
option(USE_IGRAPH "Sử dụng igraph (xem hướng dẫn trong igraph.cmd)" ON)

if (GPROF_FLAG)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pg")
endif (GPROF_FLAG)
if (USE_IGRAPH)
  add_library(igraph STATIC IMPORTED)
  set_target_properties(igraph PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/binaries/libigraph.a)
  set(IGRAPH_LIBS igraph m)
endif (USE_IGRAPH)

add_executable(data data.c)
target_link_libraries(data ${GTK3_LIBRARIES} fdr bt)

add_executable(${PROJECT_NAME} dict.c ${PROJECT_SOURCE_DIR}/lib/btn_trans.c)
target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES} fdr bt)

#add_executable(bt ex/timduong.c)
#target_link_libraries(bt ${IGRAPH_LIBS} fdr)

