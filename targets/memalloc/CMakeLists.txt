add_executable(freeandbreak)

target_sources(freeandbreak
PRIVATE 
freeandbreak.c
)

target_link_libraries(freeandbreak
PRIVATE 
linux::system::programming
)