cmake_minimum_required(VERSION 3.10)

# Установка версии проекта и номера патча.
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})
project(Guess_the_number VERSION ${PROJECT_VERSION})

# Создание исполняемого файла.
add_executable(Guess_the_number main.cpp)

# Установка стандарта C++.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Установка флагов компилятора в зависимости от платформы.
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")    
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif()

# Правила установки.
install(TARGETS Guess_the_number DESTINATION bin)

# Конфигурация для CPack.
set(CPACK_GENERATOR "ZIP;DEB")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_NAME "Guess_the_number")
set(CPACK_PACKAGE_DESCRIPTION "Описание вашего проекта")
set(CPACK_PACKAGE_VENDOR "Ваше имя или компания")
set(CPACK_PACKAGE_CONTACT "Ваш контактный email")
include(CPack)
