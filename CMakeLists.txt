cmake_minimum_required( VERSION 2.8 )
project( Function-Curves-Loader )

set( CMAKE_C_STANDARD 99 )
set( CMAKE_C_STANDARD_REQUIRED ON )

set( LIBRARY_DIR ${CMAKE_CURRENT_LIST_DIR} CACHE PATH "Relative or absolute path to directory where built shared libraries will be placed" )

include( ${CMAKE_CURRENT_LIST_DIR}/curves/CMakeLists.txt )
include( ${CMAKE_CURRENT_LIST_DIR}/data_io/CMakeLists.txt )

add_library( CurvesLoader SHARED ${CMAKE_CURRENT_LIST_DIR}/curve_loader.c )
set_target_properties( CurvesLoader PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_DIR} )
target_include_directories( CurvesLoader PUBLIC ${CMAKE_CURRENT_LIST_DIR} )
target_compile_definitions( CurvesLoader PUBLIC -DDEBUG )
target_link_libraries( CurvesLoader DataIOJSON FunctionCurves )
