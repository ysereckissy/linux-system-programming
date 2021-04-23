add_library(usergroup OBJECT)
add_library(user::group ALIAS usergroup)

target_sources(usergroup
PRIVATE
usergroup_functions.c
)

target_link_libraries(usergroup
PRIVATE 
linux::system::programming
)

target_include_directories(usergroup
PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}
)