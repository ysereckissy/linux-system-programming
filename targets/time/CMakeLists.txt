add_executable(calendartime)

target_sources(calendartime
PRIVATE 
calendartime.c
)

target_link_libraries(calendartime
PRIVATE
linux::system::programming
)
