add_executable(proccred)

target_sources(proccred
PRIVATE 
idshow.c
)

target_link_libraries(proccred
PRIVATE 
linux::system::programming
user::group
)