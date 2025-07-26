cmake_minimum_required(VERSION 3.10)
project(MonsterEditor LANGUAGES CXX)

# Usar C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Procurar wxWidgets com todos os componentes usados
find_package(wxWidgets REQUIRED COMPONENTS core base adv xml xrc aui)

# Incluir automaticamente headers e flags do wxWidgets
include(${wxWidgets_USE_FILE})

# Pegar arquivos do projeto
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

# Garantir que os arquivos foram encontrados
if(NOT SOURCES)
    message(FATAL_ERROR "Nenhum arquivo .cpp encontrado na pasta src/")
endif()

# Criar o executável
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Adiciona o diretório include/ ao path de headers
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Linkar com as bibliotecas do wxWidgets e do sistema
target_link_libraries(${PROJECT_NAME}
    ${wxWidgets_LIBRARIES}
    comctl32
    uxtheme
    version
    shlwapi
    msimg32
    png
)

# Configurar saída dos binários
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# Instalação (opcional)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
