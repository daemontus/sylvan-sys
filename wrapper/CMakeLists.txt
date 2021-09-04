cmake_minimum_required(VERSION 3.1)

project(wrapper VERSION 1.6.1)
add_library(wrapper src/sylvan-wrapper.c)

enable_language(C CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

target_include_directories(wrapper PUBLIC ${SYLVAN}/include)
target_link_directories(wrapper PUBLIC ${SYLVAN}/lib)
target_link_libraries(wrapper PUBLIC sylvan)

install(TARGETS wrapper DESTINATION lib)
install(FILES src/sylvan-wrapper.h DESTINATION include)