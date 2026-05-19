cmake_minimum_required(VERSION 3.12)
project("TerminalTextureRendering.dir" LANGUAGES "CXX")
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
        source/headers/CHECKSUM_TYPES.hpp
        source/headers/hcp.hpp
    )

    if(WIN32)
        set(LAUNCHER_EXTENSION "bat")
        set(SCRIPT_CONTENT "@echo off\ncmake -P \"${CMAKE_CURRENT_SOURCE_DIR}/TestingCommandLine.cmake\" %*")
    else()
        set(LAUNCHER_EXTENSION "sh")
        set(SCRIPT_CONTENT "#!/bin/sh\ncmake -P \"${CMAKE_CURRENT_SOURCE_DIR}/TestingCommandLine.cmake\" \"$@\"")
    endif()

    file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/run_tool.${LAUNCHER_EXTENSION}" "${SCRIPT_CONTENT}")
else()
    message(FATAL_ERROR "No .cpp files matching expression pattern inside: ${SRC_DIR}")
endif()
