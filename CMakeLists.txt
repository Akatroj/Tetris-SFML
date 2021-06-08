cmake_minimum_required(VERSION 3.17)
project(Tetris)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tetris src/main.cpp src/Game/Pieces/Piece.cpp src/Game/Pieces/Piece.h src/Game/Block.cpp src/Game/Block.h src/Game/Board.cpp src/Game/Board.h src/Game/utils/BoardCoordinates.cpp src/Game/utils/BoardCoordinates.h src/Game/Pieces/LinePiece.h src/Game/utils/AssetsManager.cpp src/Game/utils/AssetsManager.h src/Game/Pieces/LPiece.h src/Game/Pieces/JPiece.h src/Game/Pieces/TPiece.h src/Game/Pieces/SPiece.h src/Game/Pieces/ZPiece.h src/Game/Pieces/OPiece.h src/Game/Game.cpp src/Game/Game.h src/Game/utils/PieceProjection.cpp src/Game/utils/PieceProjection.h src/Game/Pieces/PieceTypes.h src/Game/utils/PieceMover.cpp src/Game/utils/PieceMover.h src/Game/utils/PieceGenerator.cpp src/Game/utils/PieceGenerator.h src/Game/Pieces/FakePiece.cpp src/Game/Pieces/FakePiece.h src/Game/utils/PieceHolder.cpp src/Game/utils/PieceHolder.h src/Game/utils/Score.cpp src/Game/utils/Score.h)

include_directories(headers /usr/include c:/SFML/include)

set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Tetris ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
