#pragma once

#include <string>
#include <vector>
#include <map>

// uses predictive parsing table to validate and get moves
// useful for generating future moves
// no 'language' for king and pawns, these pieces have very limited moves.

// columns and rows are labeled by comments
// "" = invalid, $ = terminate

// BISHOP PIECE
std::vector<std::vector<std::string>> bishopTable = {
     /* up right down left terminate */
/* E */ { "uX", "", "dY", "", "" },
/* X */ { "", "rA", "lB", "", "" },
/* A */ { "uM", "", "", "", "$" },
/* B */ { "uN", "", "", "", "$" },
/* M */ { "", "rA", "", "", ""},
/* N */ { "", "", "", "lB", ""},
/* Y */ { "", "rJ", "", "lK", ""},
/* J */ { "", "", "dU", "", "$"},
/* U */ { "", "rJ", "", "", ""},
/* K */ { "", "", "dV", "", "$"},
/* V */ { "", "", "", "lK", ""},
};

// row names for tables
std::map<char, int> bishopRows = { {'E', 0}, {'X', 1}, {'A', 2}, {'B', 3}, 
        {'M', 4}, {'N', 5}, {'Y', 6}, {'J', 7}, {'U', 8}, {'K', 9}, {'V', 10} };

// ROOK PIECE
std::vector<std::vector<std::string>> rookTable = {
/* A */ {"uH" , "rK", "dY", "lZ", ""},
/* H */ {"uH" , "", "", "", "$"},
/* K */ {"" , "rK", "", "", "$"},
/* Y */ {"" , "", "dY", "", "$"},
/* Z */ {"" , "", "", "lZ", "$"},
};

std::map<char, int> rookRows = { {'A', 0}, {'H', 1}, {'K', 2}, {'Y', 3}, {'Z', 4} };

// KNIGHT PIECE
std::vector<std::vector<std::string>> knightTable = {
/* A */ { "uG", "rK", "dH", "lJ", "" },
/* G */ { "uQ", "", "", "", "" },
/* H */ { "", "", "dQ", "", "" },
/* Q */ { "", "rV", "", "lV", "" },
/* J */ { "", "", "", "lS", "" },
/* K */ { "", "rS", "", "", "" },
/* S */ { "uV", "", "dV", "", "" },
/* V */ { "", "", "", "", "$" },
};

std::map<char, int> knightRows = { {'A', 0}, {'G', 1}, {'H', 2}, {'Q', 3}, {'J', 4}, 
        {'K', 5}, {'S', 6}, {'V', 7} };

// QUEEN PIECE
std::vector<std::vector<std::string>> queenTable = {
/* A */ { "uE", "rQ", "dF", "lT", ""},
/* E */ { "uZ", "rS", "", "iT", "$"},
/* Z */ { "uQ", "", "", "", "$"},
/* S */ { "uK", "", "", "", "$"},
/* K */ { "", "rS", "", "", ""},
/* T */ { "uJ", "", "", "", "$"},
/* J */ { "", "", "", "lT", ""},
/* Q */ { "", "rQ", "", "", "$"},
/* T */ { "", "", "", "lT", "$"},
/* F */ { "", "rM", "dX", "lN", "$"},
/* X */ { "", "", "dX", "", "$"},
/* M */ { "", "", "dO", "", "$"},
/* O */ { "", "rM", "", "", ""},
/* N */ { "", "", "dP", "", "$"},
/* P */ { "", "", "", "lN", ""},
};

std::map<char, int> queenRows = { {'A', 0}, {'E', 1}, {'Z', 2}, {'S', 3}, {'K', 4}, {'T', 5}, 
        {'J', 6}, {'Q', 7}, {'T', 8}, {'F', 9}, {'X', 10}, {'X', 11}, {'M', 12}, {'O',13}, 
        {'N', 14}, {'P', 15} };

// column names + index map for all tables
std::map<char, int> legend = { {'u', 0}, {'r',1}, {'d', 2}, {'l', 3}, {'$', 4} }; 