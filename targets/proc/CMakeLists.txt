#--------------------------------------------------------------------------
# Targets Definition
#--------------------------------------------------------------------------
add_executable(memsegment)
add_executable(changeenv)
add_executable(longjmp)

#--------------------------------------------------------------------------
# Adding source to targets
#--------------------------------------------------------------------------
target_sources(memsegment
PRIVATE
memsegment.c
)

target_sources(changeenv
PRIVATE
changeenv.c
)

target_sources(longjmp
PRIVATE
longjump.c
)
#--------------------------------------------------------------------------
# Linking libraries to targets
#--------------------------------------------------------------------------
target_link_libraries(memsegment
PRIVATE
linux::system::programming
)
target_link_libraries(changeenv
PRIVATE
linux::system::programming
)
target_link_libraries(longjmp
PRIVATE
linux::system::programming
)