cmake_minimum_required (VERSION 3.18)

# Set sources
set(SRCS
  "main.cpp"
  "InputReader.cpp"
  "ProductId.cpp"
  "Range.cpp"
)

# Set up executable
add_executable(day2
  ${SRCS}
)

set_target_properties(day2
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${AOC_RUNTIME_OUTPUT_DIR}/Day2"
)

target_include_directories(day2
  PUBLIC
    "${AOC_SOURCE_DIR}/Day2"
)

target_link_libraries(day2
  PRIVATE
    ${AOC_COVERAGE_LIBS}
)
