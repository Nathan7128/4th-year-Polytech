# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CalculatriceEtat_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CalculatriceEtat_autogen.dir\\ParseCache.txt"
  "CalculatriceEtat_autogen"
  )
endif()
