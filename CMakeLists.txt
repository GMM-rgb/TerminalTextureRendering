# cmake_minimum_required(VERSION 3.12)
# project("TerminalTextureRendering" LANGUAGES "CXX")

# # Force an explicit, absolute local directory path assignment
# set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/source")

# set(TEXTURE_GENERATION_SOURCES
#     "${SRC_DIR}/texture_core.cpp"
#     "${SRC_DIR}/modules/texture_importing.cpp"
#     "${SRC_DIR}/modules/texture_instance_generation.cpp"
# )

# # The output variable name MUST be unquoted to assign properly
# file(GLOB_RECURSE TEXTURE_GENERATION_SOURCES CONFIGURE_DEPENDS "${SRC_DIR}/*.cpp")

# message(STATUS "PROJECT ROOT:         -> ${CMAKE_SOURCE_DIR}")
# message(STATUS "VERIFIED SOURCE LIST: -> ${TEXTURE_GENERATION_SOURCES}")

# # if(TEXTURE_GENERATION_HEADERS)
# #     source_group(TREE "${SRC_DIR}" FILES ${TEXTURE_GENERATION_HEADERS})
# #     add_library("TerminalTextRendering" STATIC ${TEXTURE_GENERATION_HEADERS})
# # else()
# #     message(FATAL_ERROR "No .cpp files found inside: ${SRC_DIR}. Build halted.")
# # endif()

# source_group(TREE "${SRC_DIR}" FILES ${TEXTURE_GENERATION_SOURCES})
# add_library("TerminalTextRendering" STATIC ${TEXTURE_GENERATION_SOURCES})

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
        source/headers/TEXTURE_IMPORTS.hpp)
else()
    message(FATAL_ERROR "No .cpp files matching expression pattern inside: ${SRC_DIR}")
endif()
