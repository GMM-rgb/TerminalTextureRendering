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
        source/headers/CHECKSUM_TYPES.hpp
    )

    # target_include_directories("TerminalTextRendering" PUBLIC "${SRC_DIR}/headers")
    # file(GLOB TESTING_FILE_COMMAND CONFIGURE_DEPENDS "test.cpp")
    # add_executable("TestingCommandLine" ${TESTING_FILE_COMMAND})
    # target_link_libraries("TestingCommandLine" PRIVATE "TerminalTextRendering")
    #
    # if(MSVC)
    # # Statically links the Visual C++ runtime library (/MT)
    # set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    # else()
    # # Statically links libgcc and libstdc++ for GCC/Clang (Linux/MinGW)
    # target_link_options("TestingCommandLine" PRIVATE "-static")
    # endif()
    #
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
