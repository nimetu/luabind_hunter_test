cmake_minimum_required(VERSION 3.10)

INCLUDE("${CMAKE_CURRENT_LIST_DIR}/cmake/HunterGate.cmake")
HunterGate(
  URL "https://github.com/cpp-pm/hunter/archive/v0.23.321.tar.gz"
  SHA1 "5e53cbb0429037ea8e2592bfd92704b8ff3ab492"
  FILEPATH "${CMAKE_CURRENT_LIST_DIR}/cmake/HunterConfig.cmake"
  )

PROJECT(test_class)

HUNTER_ADD_PACKAGE(Lua)
HUNTER_ADD_PACKAGE(luabind)

FIND_PACKAGE(Lua CONFIG REQUIRED)

include("${LUABIND_ROOT}/lib/CMake/Luabind/FindLuabind.cmake")

SET(TARGET "test_class")
SET(SRC    "test_class.cpp")
ADD_EXECUTABLE(${TARGET} ${SRC})

TARGET_LINK_LIBRARIES(${TARGET} ${LUABIND_LIBRARIES} Lua::lua_lib)

TARGET_INCLUDE_DIRECTORIES(${TARGET} PRIVATE "${LUA_ROOT}/include")
TARGET_INCLUDE_DIRECTORIES(${TARGET} PRIVATE "${LUABIND_ROOT}/include/luabind")

