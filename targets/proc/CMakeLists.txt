add_executable(changeenv)

target_sources(changeenv
PRIVATE
changeenv.c
)

target_link_libraries(changeenv
PRIVATE
linux::system::programming
)