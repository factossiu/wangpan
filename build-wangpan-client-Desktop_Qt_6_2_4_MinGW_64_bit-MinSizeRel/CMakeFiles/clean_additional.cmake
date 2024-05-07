# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "MinSizeRel")
  file(REMOVE_RECURSE
  "CMakeFiles\\wangpan-client_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\wangpan-client_autogen.dir\\ParseCache.txt"
  "wangpan-client_autogen"
  )
endif()
