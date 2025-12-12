# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\OnlienMusicWidget_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\OnlienMusicWidget_autogen.dir\\ParseCache.txt"
  "OnlienMusicWidget_autogen"
  )
endif()
