#--------------------------------------------------------------------------
# define executables
#---------------------------------------------------------------------------
add_executable(filecopy)
add_executable(fileseek)
add_executable(teeio)
add_executable(rawcopy)
add_executable(readv)

#---------------------------------------------------------------------------
# Add source files to executables
#---------------------------------------------------------------------------
target_sources(filecopy
PRIVATE
copy.c
)

target_sources(fileseek
PRIVATE
seek_io.c
)

target_sources(teeio
PRIVATE
teeio.c
)

target_sources(rawcopy
PRIVATE
rawcopy.c
)

target_sources(readv
PRIVATE
t_readv.c
)
#-------------------------------------------------------------------------------
# Link libraries
#--------------------------------------------------------------------------------
target_link_libraries(filecopy
PRIVATE
linux::system::programming
)
target_link_libraries(fileseek
PRIVATE
linux::system::programming
)

target_link_libraries(teeio
PRIVATE
linux::system::programming
)

target_link_libraries(rawcopy
PRIVATE
linux::system::programming
)

target_link_libraries(readv
PRIVATE
linux::system::programming
)