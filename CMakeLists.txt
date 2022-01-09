cmake_minimum_required(VERSION 3.5)

# Название проекта
project(Template)

# Переменная с именем исполняемого файла
set(EXECUTABLE ${PROJECT_NAME})

# Язык C и C++
enable_language(CXX C)

# Добавление файлов исъодного кода
add_executable(
    ${EXECUTABLE} 
    Example/Src/main.cpp
    Example/Src/NandExample.cpp
    dhara/error.c
    dhara/journal.c
    dhara/map.c
    dhara/APP/user_nandio.c
    dhara/APP/dhara_nandio.cpp
)

# Директории с *.h файлами
include_directories(
    Example/Inc
    dhara
    dhara/App
)

# Флаги компиляции
add_compile_options(
    $<$<COMPILE_LANGUAGE:CXX>:
    -fno-rtti 
    -fno-exceptions 
    $<$<CONFIG:Debug>:
    -Og>
    $<$<CONFIG:Release>:
    -Os>> 
    $<$<COMPILE_LANGUAGE:C>:
    $<$<CONFIG:Debug>:
    -Og>
    $<$<CONFIG:Release>:
    -Os>>
)


# # Пример подключения библиотек
# # Для Windows
# if (WIN32)
#     # Подключение библиотек
#     target_link_libraries(
#         ${EXECUTABLE}  
#         PUBLIC
#         ws2_32
#         wsock32
#         pthread
#     )
# endif ()

# # Для Linux
# if (UNIX)
#     target_link_libraries(
#         ${EXECUTABLE}  
#         PUBLIC
#         pthread
#     )
# endif ()

                    