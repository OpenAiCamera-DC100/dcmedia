cmake_minimum_required(VERSION 3.8)

project(dcmedia)

set(DCMEDIA_LIBS
    ${CMAKE_SOURCE_DIR}/lib/libeasymedia.so
    ${CMAKE_SOURCE_DIR}/lib/libeasymedia.so.1
    ${CMAKE_SOURCE_DIR}/lib/libeasymedia.so.1.0.1
    ${CMAKE_SOURCE_DIR}/lib/libminimedia.so
    ${CMAKE_SOURCE_DIR}/lib/libdcmedia.so
)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION "include")
install(FILES ${DCMEDIA_LIBS} DESTINATION "lib")
