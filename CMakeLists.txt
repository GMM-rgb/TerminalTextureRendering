cmake_minimum_required(VERSION 3.12)

project("TerminalTextureRendering" LANGUAGES "CXX")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/source")

# ── Library sources (everything under source/) ────────────────────────────────
file(GLOB_RECURSE TEXTURE_GENERATION_SOURCES
    CONFIGURE_DEPENDS
    "${SRC_DIR}/*.cpp"
)

if(TEXTURE_GENERATION_SOURCES)
    message(STATUS "DYN_FILES_FOUND: -> ${TEXTURE_GENERATION_SOURCES}")
else()
    message(FATAL_ERROR "No .cpp files found inside: ${SRC_DIR}")
endif()

source_group(TREE "${SRC_DIR}" FILES ${TEXTURE_GENERATION_SOURCES})

add_library("TerminalTextRendering" STATIC
    ${TEXTURE_GENERATION_SOURCES}
    source/headers/TEXTURE_IMPORTS.hpp
    source/headers/CHECKSUM_TYPES.hpp
)

target_include_directories("TerminalTextRendering" PUBLIC
    "${SRC_DIR}/headers"
)

# ── Test executable (test.cpp at root) ────────────────────────────────────────
set(TEST_SRC "${CMAKE_CURRENT_SOURCE_DIR}/test.cpp")

if(EXISTS "${TEST_SRC}")
    add_executable("TerminalTextRendering_Test" "${TEST_SRC}")

    target_link_libraries("TerminalTextRendering_Test" PRIVATE
        "TerminalTextRendering"
    )

    target_include_directories("TerminalTextRendering_Test" PRIVATE
        "${SRC_DIR}/headers"
    )
else()
    message(WARNING "test.cpp not found at ${TEST_SRC}, skipping test target")
endif()

# ── run_tool script: builds then runs the test binary ─────────────────────────
if(WIN32)
    set(LAUNCHER_EXTENSION "bat")
    set(SCRIPT_CONTENT
        "@echo off\n"
        "cmake --build \"%~dp0\" --target TerminalTextRendering_Test\n"
        "if %errorlevel% neq 0 exit /b %errorlevel%\n"
        "\"%~dp0TerminalTextRendering_Test.exe\" %*\n"
    )
else()
    set(LAUNCHER_EXTENSION "sh")
    set(SCRIPT_CONTENT
        "#!/bin/sh\n"
        "set -e\n"
        "SCRIPT_DIR=\"$(cd \"$(dirname \"$0\")\" && pwd)\"\n"
        "cmake --build \"$SCRIPT_DIR\" --target TerminalTextRendering_Test\n"
        "\"$SCRIPT_DIR/TerminalTextRendering_Test\" \"$@\"\n"
    )
endif()

file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/run_tool.${LAUNCHER_EXTENSION}" ${SCRIPT_CONTENT})

if(UNIX)
    file(CHMOD "${CMAKE_CURRENT_BINARY_DIR}/run_tool.${LAUNCHER_EXTENSION}"
        PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
        GROUP_READ GROUP_EXECUTE
        WORLD_READ WORLD_EXECUTE)
endif()
