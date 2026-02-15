cmake_minimum_required(VERSION 3.10)
project(Game)

set(CMAKE_CXX_STANDARD 17)

# Найти библиотеку SFML (замените на свою)
find_package(SFML 2.5 COMPONENTS graphics window audio system REQUIRED)

# Добавить исполняемый файл
add_executable(Game src/main.cpp)

add_custom_command(TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:Game>/resources
    COMMENT "Copying resources to output directory"
)

# Подключить заголовки и библиотеки SFML
target_link_libraries(Game sfml-graphics sfml-window sfml-audio sfml-system)

# Копировать ресурсы в папку сборки (опционально)
add_custom_command(TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:Game>/resources)
