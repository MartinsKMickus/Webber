#pragma once
#include <iostream>
#include <vector>
#include <future>
#include <thread>
#include <Windows.h>

using namespace std;

//char ChessBoard[8][8] = { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
//
//						  'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
//
//						  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
//
//						  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
//
//						  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
//
//						  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
//
//						  'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
//
//						  'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' };


//char WQueen = 'Q', WQueen = 'Q', WQueen = 'Q', WQueen = 'Q', WQueen = 'Q', WQueen = 'Q', WQueen = 'Q', WQueen = 'Q', WQueen = 'Q', WQueen = 'Q', WQueen = 'Q', WQueen = 'Q', ;
struct ChessPosition
{
	char ChessBoard[8][8] = { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',

							  'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',

							  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',

							  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',

							  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',

							  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',

							  'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',

							  'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' };

	bool WAttackedSquares[8][8] = { 0, 0, 0, 0, 0, 0, 0, 0,
								   0, 0, 0, 0, 0, 0, 0, 0,
								   0, 0, 0, 0, 0, 0, 0, 0,
								   0, 0, 0, 0, 0, 0, 0, 0,
								   0, 0, 0, 0, 0, 0, 0, 0,
								   1, 1, 1, 1, 1, 1, 1, 1,
								   1, 1, 1, 1, 1, 1, 1, 1,
								   0, 1, 1, 1, 1, 1, 1, 0 }, ///////////////// Will not be used.

		BAttackedSquares[8][8] = { 0, 1, 1, 1, 1, 1, 1, 0,
								   1, 1, 1, 1, 1, 1, 1, 1,
								   1, 1, 1, 1, 1, 1, 1, 1,
								   0, 0, 0, 0, 0, 0, 0, 0,
								   0, 0, 0, 0, 0, 0, 0, 0,
								   0, 0, 0, 0, 0, 0, 0, 0,
								   0, 0, 0, 0, 0, 0, 0, 0,
								   0, 0, 0, 0, 0, 0, 0, 0 }, ///////////////// Will not be used.
		BInCheck = 0, WInCheck = 0, Turn = 1;
	vector<ChessPosition> NextPositions;
	ChessPosition* PreviousPosition = NULL;
	string LastMove;
	int valuation = 0, WKing[2] = { 7,4 }, BKing[2] = { 0,4 };
	bool WC = true, Wc = true, BC = true, Bc = true, EnPass = false;
};