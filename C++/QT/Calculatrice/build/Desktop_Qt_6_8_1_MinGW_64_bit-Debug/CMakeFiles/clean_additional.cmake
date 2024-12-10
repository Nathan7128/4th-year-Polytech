# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Calculatrice_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Calculatrice_autogen.dir\\ParseCache.txt"
  "Calculatrice_autogen"
  )
endif()
