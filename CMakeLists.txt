cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(GehennaClient
        src/Main.cpp
        src/Game.h
        src/Game.cpp
        src/stateMachine/GameState.cpp
        src/stateMachine/GameState.h
        src/stateMachine/MainMenuState.cpp
        src/stateMachine/MainMenuState.h
        src/stateMachine/PauseState.cpp
        src/stateMachine/PauseState.h
        src/stateMachine/SettingsState.cpp
        src/stateMachine/SettingsState.h
        src/stateMachine/State.h
        src/stateMachine/StateMachine.cpp
        src/stateMachine/StateMachine.h
        src/gui/HUD.h
        src/entities/Entity.h
        src/entities/player/Player.h
        src/backend/AssetManager.cpp
        src/backend/AssetManager.h
        src/backend/ConnectionHandler.cpp
        src/backend/ConnectionHandler.h
        src/backend/InputHandler.h)

target_link_libraries(GehennaClient PRIVATE sfml-network sfml-graphics sfml-audio)

target_compile_features(GehennaClient PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
            TARGET GehennaClient
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:GehennaClient>
            VERBATIM)
endif()