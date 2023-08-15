cmake_minimum_required(VERSION 3.5)

project(08.Classes)

add_executable(structure structure.cpp
	netpbm.cpp)
set_target_properties(structure PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(structure_stream structure_stream.cpp)
set_target_properties(structure_stream PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(structure_operators structure_operators.cpp)
set_target_properties(structure_operators PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(structure_nested structure_nested.cpp)
set_target_properties(structure_nested PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(classes classes.cpp)
set_target_properties(classes PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(complex complex.cpp complex_main.cpp)
set_target_properties(complex PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)


