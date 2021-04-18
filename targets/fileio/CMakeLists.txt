#--------------------------------------------------------------------------
# define executables
#---------------------------------------------------------------------------
add_executable(filecopy)
add_executable(fileseek)
add_executable(teeio)

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