cmake_minimum_required(VERSION 3.12)
project("TerminalTextureRendering" LANGUAGES "CXX")

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/source")

file(GLOB_RECURSE TEXTURE_GENERATION_SOURCES 
     CONFIGURE_DEPENDS 
     "${SRC_DIR}/*.cpp"
)

message(STATUS "DYN_FILES_FOUND: -> ${TEXTURE_GENERATION_SOURCES}")

if(TEXTURE_GENERATION_SOURCES)
    source_group(TREE "${SRC_DIR}" FILES ${TEXTURE_GENERATION_SOURCES})
    add_library("TerminalTextRendering" STATIC ${TEXTURE_GENERATION_SOURCES}
        source/headers/TEXTURE_IMPORTS.hpp
        source/modules/utility/declaration_checksum.cpp
        source/headers/CHECKSUM_TYPES.hpp)
else()
    message(FATAL_ERROR "No .cpp files matching expression pattern inside: ${SRC_DIR}")
endif()
