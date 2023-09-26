# Static

nm ./CMakeFiles/static_library_usage.dir/main.cpp.o
nm ./lib/CMakeFiles/sumLib.dir/sum.cpp.o

# Dynamic

nm ./CMakeFiles/dynamic_library_usage.dir/main.cpp.o
nm ./lib/CMakeFiles/sumLib.dir/sum.cpp.o

# Linux
ldd ./dynamic_library_usage
#MacOS
otool -L ./dynamic_library_usage 