add_executable(greetinfile)
target_sources(greetinfile
    PRIVATE
    greet-to-file.c
)

target_link_libraries(greetinfile
PRIVATE
linux::system::programming
)

add_subdirectory(fileio)
add_subdirectory(proc)
add_subdirectory(memalloc)
add_subdirectory(usergroup)
add_subdirectory(proccred)
add_subdirectory(time)