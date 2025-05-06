add_library(TapeInteractor
    FileHandler.cpp
    FileHandler.h
    InputGenerator.cpp
    InputGenerator.h
    OutputReader.cpp
    OutputReader.h
    MenuManager.cpp
    MenuManager.h
    TapeInteractor.cpp
    TapeInteractor.h
)

target_include_directories(TapeInteractor
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(TapeInteractorApp main.cpp)
target_link_libraries(TapeInteractorApp PRIVATE TapeInteractor)

# Создаем директорию SharedData в директории с исполняемыми файлами
add_custom_command(TARGET TapeInteractorApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>/SharedData"
) 