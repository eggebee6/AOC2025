cmake_minimum_required (VERSION 3.18)

# Set sources
set(SRCS
  "main.cpp"
  "Dialpad.cpp"
  "InputReader.cpp"
)

# Set up executable
add_executable(day1
  ${SRCS}
)

set_target_properties(day1
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${AOC_RUNTIME_OUTPUT_DIR}/Day1"
)

target_include_directories(day1
  PUBLIC
    "${AOC_SOURCE_DIR}/Day1"
)

target_link_libraries(day1
  PRIVATE
    ${AOC_COVERAGE_LIBS}
)
