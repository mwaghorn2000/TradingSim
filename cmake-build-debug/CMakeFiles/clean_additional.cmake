# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/TradingSim_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/TradingSim_autogen.dir/ParseCache.txt"
  "TradingSim_autogen"
  )
endif()
