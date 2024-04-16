cmake_minimum_required(VERSION 2.8)
file (GLOB SOURCE *.cpp)
file (GLOB HEADER *.h)


project("yahtzee")

add_executable("${PROJECT_NAME}" ${SOURCE} ${HEADER})

#install(TARGETS "${PROJECT_NAME}" DESTINATION bin) #$(CMAKE_INSTALL_PREFIX)/bin
#install(FILES "yahtzee.cpp" DESTINATION src) #$(CMAKE_INSTALL_PREFIX)/src


add_subdirectory(Tests)