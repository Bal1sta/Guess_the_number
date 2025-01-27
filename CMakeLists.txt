cmake_minimum_required(VERSION 3.10)

# Установка версии проекта и номера патча.
set(PATCH_VERSION "1" CACHE STRING "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})
project(Guess_the_number VERSION ${PROJECT_VERSION})

# Создание исполняемого файла.
add_executable(Guess_the_number main.cpp)

# Установка стандарта C++.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Правила установки.
install(TARGETS Guess_the_number DESTINATION bin)

# Конфигурация для CPack.
set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_NAME "Guess_the_number")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A simple number guessing game.")
set(CPACK_PACKAGE_VENDOR "Your Name or Company")
set(CPACK_PACKAGE_CONTACT "your.email@example.com")
set(CPACK_OUTPUT_FILE_PREFIX "${CMAKE_BINARY_DIR}/package")
include(CPack)
