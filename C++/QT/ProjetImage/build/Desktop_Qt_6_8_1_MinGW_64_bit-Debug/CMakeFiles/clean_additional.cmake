# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ProjetImage_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ProjetImage_autogen.dir\\ParseCache.txt"
  "ProjetImage_autogen"
  )
endif()
