cmake_minimum_required(VERSION 3.25)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(fix_msvc)
include(cpp_novice_fetch_project_options)

project(cpp_novice LANGUAGES C CXX)

include(check_latest_cppstd)
include(cpp_novice_custom_project_options)
include(add_program)

# -----------------------------------------------------------------------------------------------------------------------
add_program_options(
  DEPENDENCIES

  LIBRARIES

  INCLUDES
  include
)

# ------------------------------------------------------------------------------------------------------------------------
add_program(oj-0-1
  oj-0-1.cpp
)
add_program(oj-0-2
  oj-0-2.cpp
)
add_program(oj-1-1
  oj-1-1.cpp
)
add_program(oj-1-2
  oj-1-2.cpp
)
add_program(claude-stairs-unlimited
  claude-stairs-unlimited.cpp
)
