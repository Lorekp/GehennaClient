# GehennaClient

A C++17/SFML prototype for the Gehenna game client. It provides a window, stack-based screen navigation, cached graphics assets, and an experimental TCP connection/authentication flow. The current project is a client foundation: it does not yet implement a playable game.

## Current functionality

- An 800 × 600 window with Start Game, Settings, and Quit menu actions.
- A game-state placeholder that opens a pause menu with Escape; the pause menu supports resume, settings, and return to the main menu.
- Font and texture caches backed by SFML resources.
- A background connection attempt with exponential retry delays, key-based authentication, and console message exchange after authentication.

The Settings screen displays Volume and Resolution labels but only Back is interactive. Video loading/playback methods are empty. Player, HUD, and input-handler declarations are scaffolding; gameplay update and rendering are empty. Network messages are not connected to gameplay.

## Build and run

Requirements: CMake 3.28 or newer, Git, a C++17 compiler, and a compatible build tool. CMake fetches SFML from its `2.6.x` branch, so configuration needs network access and does not pin an immutable dependency revision. Windows is the most direct path because authentication-file lookup uses a Windows-style relative path. Other platforms also need SFML's native development dependencies and path adjustments.

From the repository root, a single-configuration Ninja build is:

```sh
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

Keep the repository root as the working directory so the bundled font can be found. On Windows PowerShell, launch with:

```powershell
.\build\bin\GehennaClient.exe
```

Use a new build directory: the committed `cmake-build-debug/` contains machine-specific generated files. CMake copies the OpenAL DLL on Windows, but does not stage the font or authentication file.

Starting the application also starts its network connection worker. Before running, configure `IPADDRESS` and `PORT` in `src/backend/ConnectionHandler.cpp` for a server you control. The server implementation is not included here. The client reads one authentication-key line from `data/key.txt`, sends it as an SFML packet string, and waits for an `authenticated` response before starting console send/receive loops. Use a separately provisioned development key. This prototype has no TLS transport or complete connection shutdown/recovery handling.

## Source layout

| Path | Responsibility |
| --- | --- |
| `src/Main.cpp`, `src/Game.*` | Entry point, window, event/update/render loop |
| `src/stateMachine/` | State interface, stack navigation, menu/game/pause/settings screens |
| `src/backend/AssetManager.*` | Font and texture caching |
| `src/backend/ConnectionHandler.*` | TCP connection, authentication, console messaging |
| `src/entities/`, `src/gui/`, `src/backend/InputHandler.h` | Unimplemented gameplay interfaces |
| `resource/fonts/` | Menu font asset |

## Validation and dependencies

There is no project test suite or CI workflow in this snapshot, and CMake defines no test target. A manual smoke check would cover menu navigation, Escape-to-pause, return-to-menu, and authentication against a controlled compatible server.

SFML supplies graphics, windowing, networking, and audio functionality. Its implementation and generated build products are third-party dependencies, not GehennaClient's own game engine. The repository also includes Bebas Neue Regular. No project-level license or font license notice is included in this snapshot; clarify distribution terms and preserve applicable dependency notices before redistribution.
