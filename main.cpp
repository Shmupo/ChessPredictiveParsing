#include "Chess_Engine.cpp"

int main() {
    ChessEngine chess;
    chess.printBoard();

    /*
    HOW TO USE
    generateWordsRecursive(std::string currentWord, int tableRow, std::vector<std::vector<std::string>>* table, std::map<char, int>* rows, int pieceRow, int pieceCol, Color myColor) {
    
    INFO : moves are a string of directions, either u (up), d (down), l (left), r (right), for example, rrdl is right right down left. 
    this is used all pieces except for the pawn and king
    bugged for the knight piece

    Parameters : 
    currentWord - the current moves performed by a piece. Usually leave this blank when you are not querying for valid moved mid-move.
    tableRow - the starting row in the predictive parsing table of the pieice, usually leave this at 0, which is the starting path of the table. Only change this if the piece is mid move, then you must trace the table to find the row it should be on.
    table - reference to the table for a specific piece, see Chess_Parsing_Tables.cpp for a list of tables.
    pieceRow, pieceCol - the row and column a piece is in, starting at 0
    myColor - the color of the piece, either Color::White or Color::Black
    */

    chess.generateWordsRecursive("", 0, &bishopTable, &bishopRows, 0, 6, Color::White);

    return 0;
}