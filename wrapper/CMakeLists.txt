cmake_minimum_required(VERSION 3.14)

project(wrapper VERSION 1.7.1)
add_library(wrapper src/sylvan-wrapper.c)

enable_language(C CXX)

# Dependencies
include(FetchContent)
FetchContent_Declare(
    lace
    GIT_REPOSITORY https://github.com/trolando/lace.git
    GIT_TAG        v1.3.1
)
FetchContent_MakeAvailable(lace)

# Dependencies
include(FetchContent)
FetchContent_Declare(
    sylvan
    GIT_REPOSITORY https://github.com/trolando/sylvan.git
    GIT_TAG        v1.7.1
)
FetchContent_MakeAvailable(sylvan)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

#target_include_directories(wrapper PUBLIC ${SYLVAN}/src)
#target_link_directories(wrapper PUBLIC ${SYLVAN}/build/src)
#target_link_libraries(wrapper PUBLIC sylvan)

#target_include_directories(wrapper PUBLIC ${SYLVAN}/build/build/_deps/lace-src/src)
#target_include_directories(wrapper PUBLIC ${SYLVAN}/build/build/_deps/lace-build)
#target_link_directories(wrapper PUBLIC ${SYLVAN}/build/build/_deps/lace-build)
#target_link_libraries(wrapper PUBLIC lace)

target_link_libraries(wrapper PUBLIC lace sylvan)

install(TARGETS wrapper sylvan lace
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include
        )
#install(TARGETS sylvan DESTINATION lib)
#install(TARGETS lace DESTINATION lib)
#install(FILES src/sylvan-wrapper.h DESTINATION include)
#install(FILES sylvan/src/sylvan-wrapper.h DESTINATION include)