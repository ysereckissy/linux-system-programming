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