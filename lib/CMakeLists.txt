add_library(${CMAKE_PROJECT_NAME}_lib OBJECT)
add_library(linux::system::programming ALIAS ${CMAKE_PROJECT_NAME}_lib)

target_sources(${CMAKE_PROJECT_NAME}_lib
PRIVATE
error_functions.c
get_num.c
)

set_target_properties(${CMAKE_PROJECT_NAME}_lib
PROPERTIES
-std c99
)

target_include_directories(${CMAKE_PROJECT_NAME}_lib
PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}
)
