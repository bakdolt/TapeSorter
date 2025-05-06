add_library(TapeSorter
    Tape.h
    FileTape.cpp
    FileTape.h
    TapeSorter.cpp
    TapeSorter.h
    DelayConfig.cpp
    DelayConfig.h
)

target_include_directories(TapeSorter
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(TapeSorterApp main.cpp)
target_link_libraries(TapeSorterApp PRIVATE TapeSorter)

# Создаем директорию SharedData в директории с исполняемыми файлами
add_custom_command(TARGET TapeSorterApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>/SharedData"
) 