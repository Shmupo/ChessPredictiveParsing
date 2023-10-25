#pragma once

enum class Piece {None, Pawn, Rook, Knight, Bishop, Queen, King};
enum class Color {None, White, Black};
enum class Moves {Up, Down, Left, Right, UpLeft, UpRight, DownLeft, DownRight, Attack};

struct Square {
    Piece piece;
    Color color;
};

// used to record moves
// keep attack default to false
// -1 row/col value is for invalid move
struct Coord{
    int row = -1;
    int col = -1;
    bool attack = false;
};