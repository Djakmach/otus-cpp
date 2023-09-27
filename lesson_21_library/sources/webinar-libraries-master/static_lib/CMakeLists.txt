cmake_minimum_required(VERSION 3.5)

project(static_library_usage)

add_subdirectory(lib)

add_executable(static_library_usage
	main.cpp
)

target_link_libraries(static_library_usage     	# линкуем библиотеку sumLib к проекту static_library_usage
	PRIVATE
	sumLib
)
target_include_directories(static_library_usage		# для #include .h без пути
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/lib
)

# target_link_directories							# указания директорий, в которых следует искать библиотеки при связывании (линковке) цели (target).