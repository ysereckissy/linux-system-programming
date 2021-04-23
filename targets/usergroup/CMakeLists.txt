add_executable(checkpassword)

target_sources(checkpassword
PRIVATE 
checkpassword.c
)

target_link_libraries(checkpassword
PRIVATE 
linux::system::programming
crypt
)