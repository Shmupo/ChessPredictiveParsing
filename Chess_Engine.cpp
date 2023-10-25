#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <stack>

#include "Chess_Structures.cpp"
#include "Chess_Parsing_Tables.cpp"

// basic chess engine for displaying a chess board
// rules enforced by Chess_Manager.cpp

class ChessEngine {
    public:
        ChessEngine() {
            resetBoard();
        }

        // Sets the board to start positions
        // whiteBottom == true if white starts on the bottom
        void resetBoard(bool whiteBottom = true) {
            Piece pieceOrder[] = {Piece::Rook, Piece::Knight, Piece::Bishop, Piece::Queen, Piece::King, Piece::Bishop, Piece::Knight, Piece::Rook};

            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    
                    if(i == 1 || i == 6) {
                        // setting pawns and pawn color
                        board[i][j].piece = Piece::Pawn;
                        if (whiteBottom) {
                            board[i][j].color = (i == 1) ? Color::Black : Color::White;
                        }
                        else {
                            board[i][j].color = (i == 6) ? Color::Black : Color::White;
                        }
                    }
                    else if (i == 0 || i == 7) {
                        board[i][j].piece = pieceOrder[j];

                        if (whiteBottom) {
                            board[i][j].color = (i == 0) ? Color::Black : Color::White;
                        }
                        else {
                            board[i][j].color = (i == 7) ? Color::Black : Color::White;
                        }

                    }
                    else {
                        board[i][j].piece = Piece::None;
                        board[i][j].color = Color::None;
                    }
                }
            }

        }

        std::vector<Coord> getMoves(int row, int col, bool isBottomSpawned) {
            Square square = board[row][col];

            std::vector<Coord> output;
            
            if (square.piece == Piece::Pawn) {
                getPawnMoves(row, col, isBottomSpawned);
            }
            else if (square.piece == Piece::King) {

            }
            else if (square.piece != Piece::None) {

                switch (square.piece) {
                    case Piece::Rook:

                        break;
                    case Piece::Bishop:
                        
                        break;
                    case Piece::Knight: 

                        break;
                    case Piece::Queen: 

                        break;
                    default:
                        std::cout << "Error." << std::endl;
                }
            }
            else {
                std::cout << "No piece selected." << std::endl;
            }

            return output;
        }

        // gets moves of a pawn that either starts at the bottom or top
        std::vector<Coord> getPawnMoves(int row, int col, bool isBottomSpawned) {
            std::vector<Coord> output;

            int forwardDirection = isBottomSpawned ? -1 : 1;

            // checking the front spaces
            if (row + forwardDirection >= 0 && row + forwardDirection < 8 &&
                board[row + forwardDirection][col].piece == Piece::None) {
                Coord front1;
                front1.row = row + forwardDirection;
                front1.col = col;
                output.push_back(front1);

                if ((isBottomSpawned && row == 6) || (!isBottomSpawned && row == 1) &&
                    board[row + 2 * forwardDirection][col].piece == Piece::None) {
                    Coord front2;
                    front2.row = row + 2 * forwardDirection;
                    front2.col = col;
                    output.push_back(front2);
                }
            }

            // checking corners for attacks
            Color oppositeColor = (board[row][col].color == Color::White) ? Color::Black : Color::White;
            if (row + forwardDirection >= 0 && row + forwardDirection < 8) {
                // checking left corner
                if (col > 0 && board[row + forwardDirection][col - 1].color == oppositeColor) {
                    Coord leftCorner;
                    leftCorner.row = row + forwardDirection;
                    leftCorner.col = col - 1;
                    leftCorner.attack = true;
                    output.push_back(leftCorner);
                }
                // checking right corner
                if (col < 7 && board[row + forwardDirection][col + 1].color == oppositeColor) {
                    Coord rightCorner;
                    rightCorner.row = row + forwardDirection;
                    rightCorner.col = col + 1;
                    rightCorner.attack = true;
                    output.push_back(rightCorner);
                }
            }

            return output; // Return the vector of valid moves
        }

        // needs to do checks for whether the square is under attack or not
        std::vector<Coord> getKingMoves(int row, int col) {
            std::vector<Coord> output;
            
            return output;
        }

    // generates paths for all possible moves of a given piece using parsing tables
    // requires the position of the piece
    // the starting currentWord is different according to the first letter of each table
    void generateWordsRecursive(std::string currentWord, int tableRow, std::vector<std::vector<std::string>>* table, std::map<char, int>* rows, int pieceRow, int pieceCol, Color myColor) {
        for (int col = 0; col < (*table)[tableRow].size(); ++col) {
            std::string transition = (*table)[tableRow][col];

            if (transition != "") {
                if (transition == "$") {
                    // add to moves
                    std::cout << currentWord << std::endl;
                    // need to check for attacks here and then stop loop when attack target is reached
                }
                else {
                    std::string newWord = currentWord + transition;
                    Coord target = wordToCoord(newWord, pieceRow, pieceCol, myColor);

                    // checkMoveRange will not return true for ally-occupied squares because wordToCoord returns coordinate of -1, -1
                    // need to make exception for knight piece
                    if (checkMoveRange(target)) {
                        char nextRowSymbol = newWord.back();
                        newWord.pop_back();
                        generateWordsRecursive(newWord, (*rows)[nextRowSymbol], table, rows, pieceRow, pieceCol, myColor);
                    }
                }
            }
        }

    }

    // returns a -1, -1 coordinate if the square is occupied by an ally piece
    Coord wordToCoord (std::string move, int row, int col, Color myColor) {
        for (int i = 0; i < move.length(); ++i) {
            // branchless programming :)
            row -= (move[i] == 'u');
            row += (move[i] == 'd');
            col += (move[i] == 'r');
            col -= (move[i] == 'l');
        }

        Color targetColor = board[row][col].color;
        
        Coord output;
        output.row = row;
        output.col = col;

        if (targetColor == myColor) {
            output.row = -1;
            output.col = -1;
        }
        else if (targetColor != Color::None) {
            output.attack = true;
        }

        return output;
    }

    // returns true if the move is in range
    bool checkMoveRange(Coord coordinate) {
        if (coordinate.row >= 0 && coordinate.row <= 7 && coordinate.col >= 0 && coordinate.col <= 7) return true;
        else return false;
    }

    void test() {
        generateWordsRecursive("", 0, &knightTable, &knightRows, 0, 0, Color::White);
    }

    // for terminal display only
    void printBoard() {
        for (int i = 7; i >= 0; --i) {
            for (int j = 0; j < 8; ++j) {
                std::cout << "[" << static_cast<int>(board[i][j].piece) << "," << static_cast<int>(board[i][j].color) << "] ";
            }
            std::cout << std::endl;
        }
    }

    private:
        Square board[8][8]; 
        bool whiteBottom = true;
};