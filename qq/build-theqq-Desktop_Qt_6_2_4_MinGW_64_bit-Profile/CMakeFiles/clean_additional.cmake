# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "RelWithDebInfo")
  file(REMOVE_RECURSE
  "CMakeFiles\\theqq_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\theqq_autogen.dir\\ParseCache.txt"
  "theqq_autogen"
  )
endif()
