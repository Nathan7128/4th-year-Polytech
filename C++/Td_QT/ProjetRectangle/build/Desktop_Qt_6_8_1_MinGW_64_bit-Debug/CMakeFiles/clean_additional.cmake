# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ProjetRectangle_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ProjetRectangle_autogen.dir\\ParseCache.txt"
  "ProjetRectangle_autogen"
  )
endif()
