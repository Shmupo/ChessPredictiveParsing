# ChessPredictiveParsing
Get valid chess piece moves using predictive parsing.

Working prototype.

CHESS BOARD :
[2,1] [3,1] [4,1] [5,1] [6,1] [4,1] [3,1] [2,1] 
[1,1] [1,1] [1,1] [1,1] [1,1] [1,1] [1,1] [1,1]
[0,0] [0,0] [0,0] [0,0] [0,0] [0,0] [0,0] [0,0]
[0,0] [0,0] [0,0] [0,0] [0,0] [0,0] [0,0] [0,0]
[0,0] [0,0] [0,0] [0,0] [0,0] [0,0] [0,0] [0,0]
[0,0] [0,0] [0,0] [0,0] [0,0] [0,0] [0,0] [0,0]
[1,2] [1,2] [1,2] [1,2] [1,2] [1,2] [1,2] [1,2]
[2,2] [3,2] [4,2] [5,2] [6,2] [4,2] [3,2] [2,2]

Structures : 
Piece {None, Pawn, Rook, Knight, Bishop, Queen, King};
Color {None, White, Black};

To read the board, each box is a chess piece and their color according to the piece and color structures.
For example, [3,1] means a Knight since 3 is the third index of the Piece array, and 1 is the color White because it is index 1 in the Color array. 

To insert your own custom board, you will have to create the board manually using the rules above and set the board object inside of the Chess_Engine.cpp file to it.

To generate the valid moves of a piece, use generateWordsRecursive in the Chess_Engine.cpp file.

Below is how to use it :
  generateWordsRecursive(std::string currentWord, int tableRow, std::vector<std::vector<std::string>>* table, std::map<char, int>* rows, int pieceRow, int pieceCol, Color myColor) {
  
  INFO : moves are a string of directions, either u (up), d (down), l (left), r (right), for example, rrdl is right right down left. 
  this is used all pieces except for the pawn and king

  Parameters : 
  currentWord - the current moves performed by a piece. Usually leave this blank when you are not querying for valid moved mid-move.
  tableRow - the starting row in the predictive parsing table of the pieice, usually leave this at 0, which is the starting path of the table. Only change this if the piece is mid move, then you must trace the table to find the row it should be on.
  table - reference to the table for a specific piece, see Chess_Parsing_Tables.cpp for a list of tables.
  pieceRow, pieceCol - the row and column a piece is in, starting at 0
  myColor - the color of the piece, either Color::White or Color::Black

Currently, the knight piece does not correctly validate moves and may return an invalid, but proper, move.

The Chess_Parsing_Tables.cpp contains the parsing tables used.

Every piece except the king and pawn utilize the parsing tables.

To run, install all cpp files and run the main.cpp.
To get the moves of a piece, change the generateWordsRecursive parameters to suit your needs.
