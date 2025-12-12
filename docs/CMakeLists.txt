cmake_minimum_required(VERSION 3.18)

# Add styling for Doxygen
FetchContent_Declare(
    doxygen-awesome-css
    URL https://github.com/jothepro/doxygen-awesome-css/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(doxygen-awesome-css)

# Set option values for Doxyfile template
FetchContent_GetProperties(doxygen-awesome-css SOURCE_DIR DOXY_OPT_HTML_EXTRA_STYLESHEET)

set(DOXY_OPT_PROJECT_NAME "${AOC_NAME}")
set(DOXY_OPT_PROJECT_BRIEF "${AOC_DESCRIPTION}")

set(DOXY_OPT_INPUT "${AOC_SOURCE_DIR} \\\n${AOC_DOCS_DIR} \\\nREADME.md")
set(DOXY_OPT_OUTPUT_DIRECTORY "${AOC_DOCS_OUTPUT_DIR}")

# Generate Doxyfile from template
set(DOXYFILE_TEMPLATE "${AOC_DOCS_DIR}/Doxyfile.template")
set(DOXYFILE_OUT "${AOC_DOCS_DIR}/Doxyfile")

configure_file(${DOXYFILE_TEMPLATE} ${DOXYFILE_OUT} @ONLY)
