#pragma once
#include "core.h"

class PositionGenerator
{
public:
	PositionGenerator()
	{
		CurrentPos = new ChessPosition();
		Start = CurrentPos;
		GenerateNextLevel();
		//CurrentPos.BAttackedSquares;
	}
	void DiagnosticPrint()
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << CurrentPos->ChessBoard[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << CurrentPos->BAttackedSquares[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << CurrentPos->WAttackedSquares[i][j] << " ";
			}
			cout << endl;
		}
	}
	void GenerateNextLevel()
	{
		ChessPosition Positions = *CurrentPos; ///////////////////////////
		int xAsis, yAsis;
		int x, y;
		if (Positions.Turn)
		{
			for (int i = 0; i < 8; i++)
			{
				yAsis = i;
				for (int j = 0; j < 8; j++)
				{
					xAsis = j;
					switch (Positions.ChessBoard[i][j]) // Movement for White pieces.
					{
					case 'R':
						for (int x = xAsis + 1; x < 8; x++)
						{
							if (Positions.ChessBoard[i][x] > 91 || Positions.ChessBoard[i][x] == ' ')
							{
								AddNextMove(j, i, x, i);
							}
							else break;
							if (Positions.ChessBoard[i][x] != ' ') break;
						}
						for (int x = xAsis - 1; x >= 0; x--)
						{
							if (Positions.ChessBoard[i][x] > 91 || Positions.ChessBoard[i][x] == ' ')
							{
								AddNextMove(j, i, x, i);
							}
							else break;
							if (Positions.ChessBoard[i][x] != ' ') break;
						}
						for (int y = yAsis + 1; y < 8; y++)
						{
							if (Positions.ChessBoard[y][j] > 91 || Positions.ChessBoard[y][j] == ' ')
							{
								AddNextMove(j, i, j, y);
							}
							else break;
							if (Positions.ChessBoard[y][j] != ' ') break;
						}
						for (int y = yAsis - 1; y >= 0; y--)
						{
							if (Positions.ChessBoard[y][j] > 91 || Positions.ChessBoard[y][j] == ' ')
							{
								AddNextMove(j, i, j, y);
							}
							else break;
							if (Positions.ChessBoard[y][j] != ' ') break;
						}
						break;
					case 'N':
						if (yAsis + 2 < 8)
						{
							if (xAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis + 2][xAsis + 1] > 91 || Positions.ChessBoard[yAsis + 2][xAsis + 1] == ' ')
								{
									AddNextMove(j, i, xAsis + 1, yAsis + 2);
								}
							}
							if (xAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis + 2][xAsis - 1] > 91 || Positions.ChessBoard[yAsis + 2][xAsis - 1] == ' ')
								{
									AddNextMove(j, i, xAsis - 1, yAsis + 2);
								}
							}
						}
						if (yAsis - 2 >= 0)
						{
							if (xAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis - 2][xAsis + 1] > 91 || Positions.ChessBoard[yAsis - 2][xAsis + 1] == ' ')
								{
									AddNextMove(j, i, xAsis + 1, yAsis - 2);
								}
							}
							if (xAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis - 2][xAsis - 1] > 91 || Positions.ChessBoard[yAsis - 2][xAsis - 1] == ' ')
								{
									AddNextMove(j, i, xAsis - 1, yAsis - 2);
								}
							}
						}
						if (xAsis + 2 < 8)
						{
							if (yAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis + 1][xAsis + 2] > 91 || Positions.ChessBoard[yAsis + 1][xAsis + 2] == ' ')
								{
									AddNextMove(j, i, xAsis + 2, yAsis + 1);
								}
							}
							if (yAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis - 1][xAsis + 2] > 91 || Positions.ChessBoard[yAsis - 1][xAsis + 2] == ' ')
								{
									AddNextMove(j, i, xAsis + 2, yAsis - 1);
								}
							}
						}
						if (xAsis - 2 >= 8)
						{
							if (yAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis + 1][xAsis - 2] > 91 || Positions.ChessBoard[yAsis + 1][xAsis - 2] == ' ')
								{
									AddNextMove(j, i, xAsis - 2, yAsis + 1);
								}
							}
							if (yAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis - 1][xAsis - 2] > 91 || Positions.ChessBoard[yAsis - 1][xAsis - 2] == ' ')
								{
									AddNextMove(j, i, xAsis - 2, yAsis - 1);
								}
							}
						}
						break;
					case 'B':
						x = xAsis + 1;
						y = yAsis + 1;
						while (x < 8 && y < 8)
						{
							if (Positions.ChessBoard[y][x] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddNextMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x++;
							y++;
						}
						x = xAsis - 1;
						y = yAsis - 1;
						while (x >= 0 && y >= 0)
						{
							if (Positions.ChessBoard[y][x] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddNextMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x--;
							y--;
						}
						x = xAsis - 1;
						y = yAsis + 1;
						while (y < 8 && x >= 0)
						{
							if (Positions.ChessBoard[y][x] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddNextMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x--;
							y++;
						}
						x = xAsis + 1;
						y = yAsis - 1;
						while (y >= 0 && x < 8)
						{
							if (Positions.ChessBoard[y][x] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddNextMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x++;
							y--;
						}
						break;
					case 'Q':
						for (int x = xAsis + 1; x < 8; x++)
						{
							if (Positions.ChessBoard[i][x] > 91 || Positions.ChessBoard[i][x] == ' ')
							{
								AddNextMove(j, i, x, i);
							}
							else break;
							if (Positions.ChessBoard[i][x] != ' ') break;
						}
						for (int x = xAsis - 1; x >= 0; x--)
						{
							if (Positions.ChessBoard[i][x] > 91 || Positions.ChessBoard[i][x] == ' ')
							{
								AddNextMove(j, i, x, i);
							}
							else break;
							if (Positions.ChessBoard[i][x] != ' ') break;
						}
						for (int y = yAsis + 1; y < 8; y++)
						{
							if (Positions.ChessBoard[y][j] > 91 || Positions.ChessBoard[y][j] == ' ')
							{
								AddNextMove(j, i, j, y);
							}
							else break;
							if (Positions.ChessBoard[y][j] != ' ') break;
						}
						for (int y = yAsis - 1; y >= 0; y--)
						{
							if (Positions.ChessBoard[y][j] > 91 || Positions.ChessBoard[y][j] == ' ')
							{
								AddNextMove(j, i, j, y);
							}
							else break;
							if (Positions.ChessBoard[y][j] != ' ') break;
						}
						x = xAsis + 1;
						y = yAsis + 1;
						while (x < 8 && y < 8)
						{
							if (Positions.ChessBoard[y][x] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddNextMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x++;
							y++;
						}
						x = xAsis - 1;
						y = yAsis - 1;
						while (x >= 0 && y >= 0)
						{
							if (Positions.ChessBoard[y][x] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddNextMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x--;
							y--;
						}
						x = xAsis - 1;
						y = yAsis + 1;
						while (y < 8 && x >= 0)
						{
							if (Positions.ChessBoard[y][x] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddNextMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x--;
							y++;
						}
						x = xAsis + 1;
						y = yAsis - 1;
						while (y >= 0 && x < 8)
						{
							if (Positions.ChessBoard[y][x] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddNextMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x++;
							y--;
						}
						break;
					case 'K':
						if (i + 1 < 8)
						{
							if (j + 1 < 8)
							{
								if (Positions.ChessBoard[i + 1][j + 1] > 91 || Positions.ChessBoard[y][x] == ' ')
								{
									AddNextMove(j, i, j + 1, i + 1);
								}
								if (Positions.ChessBoard[i][j + 1] > 91 || Positions.ChessBoard[y][x] == ' ')
								{
									AddNextMove(j, i, j + 1, i);
								}
							}
							if (j - 1 >= 0)
							{
								if (Positions.ChessBoard[i + 1][j - 1] > 91 || Positions.ChessBoard[y][x] == ' ')
								{
									AddNextMove(j, i, j - 1, i + 1);
								}
							}
							if (Positions.ChessBoard[i + 1][j] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddNextMove(j, i, j, i + 1);
							}
						}
						if (i - 1 >= 0)
						{
							if (j - 1 >= 0)
							{
								if (Positions.ChessBoard[i - 1][j - 1] > 91 || Positions.ChessBoard[y][x] == ' ')
								{
									AddNextMove(j, i, j - 1, i - 1);
								}
								if (Positions.ChessBoard[i][j - 1] > 91 || Positions.ChessBoard[y][x] == ' ')
								{
									AddNextMove(j, i, j - 1, i);
								}
							}
							if (j + 1 < 8)
							{
								if (Positions.ChessBoard[i - 1][j + 1] > 91 || Positions.ChessBoard[y][x] == ' ')
								{
									AddNextMove(j, i, j + 1, i - 1);
								}
							}
							if (Positions.ChessBoard[i - 1][j] > 91 || Positions.ChessBoard[y][x] == ' ')
							{
								AddNextMove(j, i, j, i - 1);
							}
						}
						break;
					case 'P':
						if (yAsis == 6)
						{
							if (Positions.ChessBoard[yAsis - 1][xAsis] == ' ' && Positions.ChessBoard[yAsis - 2][xAsis] == ' ')
							{
								AddNextMove(j, i, j, i - 2);
							}
						}
						if (yAsis - 1 >= 0)
						{
							if (Positions.ChessBoard[yAsis - 1][xAsis] == ' ')
							{
								AddNextMove(j, i, j, i - 1);
							}
							if (xAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis - 1][xAsis + 1] > 91 && Positions.ChessBoard[yAsis - 1][xAsis + 1] != ' ')
								{
									AddNextMove(j, i, j + 1, i - 1);
								}
							}
							if (xAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis - 1][xAsis - 1] > 91 && Positions.ChessBoard[yAsis - 1][xAsis - 1] != ' ')
								{
									AddNextMove(j, i, j - 1, i - 1);
								}
							}
						}
						break;
					default:
						break;
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < 8; i++)
			{
				yAsis = i;
				for (int j = 0; j < 8; j++)
				{
					xAsis = j;
					switch (Positions.ChessBoard[i][j]) // Movement for Black pieces.
					{
					case 'r':
						for (int x = xAsis + 1; x < 8; x++)
						{
							if (Positions.ChessBoard[i][x] < 91)
							{
								AddNextMove(j, i, x, i);
							}
							else break;
							if (Positions.ChessBoard[i][x] != ' ') break;
						}
						for (int x = xAsis - 1; x >= 0; x--)
						{
							if (Positions.ChessBoard[i][x] < 91)
							{
								AddNextMove(j, i, x, i);
							}
							else break;
							if (Positions.ChessBoard[i][x] != ' ') break;
						}
						for (int y = yAsis + 1; y < 8; y++)
						{
							if (Positions.ChessBoard[y][j] < 91)
							{
								AddNextMove(j, i, j, y);
							}
							else break;
							if (Positions.ChessBoard[y][j] != ' ') break;
						}
						for (int y = yAsis - 1; y >= 0; y--)
						{
							if (Positions.ChessBoard[y][j] < 91)
							{
								AddNextMove(j, i, j, y);
							}
							else break;
							if (Positions.ChessBoard[y][j] != ' ') break;
						}
						break;
					case 'n':
						if (yAsis + 2 < 8)
						{
							if (xAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis + 2][xAsis + 1] < 91)
								{
									AddNextMove(j, i, xAsis + 1, yAsis + 2);
								}
							}
							if (xAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis + 2][xAsis - 1] < 91)
								{
									AddNextMove(j, i, xAsis - 1, yAsis + 2);
								}
							}
						}
						if (yAsis - 2 >= 0)
						{
							if (xAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis - 2][xAsis + 1] < 91)
								{
									AddNextMove(j, i, xAsis + 1, yAsis - 2);
								}
							}
							if (xAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis - 2][xAsis - 1] < 91)
								{
									AddNextMove(j, i, xAsis - 1, yAsis - 2);
								}
							}
						}
						if (xAsis + 2 < 8)
						{
							if (yAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis + 1][xAsis + 2] < 91)
								{
									AddNextMove(j, i, xAsis + 2, yAsis + 1);
								}
							}
							if (yAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis - 1][xAsis + 2] < 91)
								{
									AddNextMove(j, i, xAsis + 2, yAsis - 1);
								}
							}
						}
						if (xAsis - 2 >= 0)
						{
							if (yAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis + 1][xAsis - 2] < 91)
								{
									AddNextMove(j, i, xAsis - 2, yAsis + 1);
								}
							}
							if (yAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis - 1][xAsis - 2] < 91)
								{
									AddNextMove(j, i, xAsis - 2, yAsis - 1);
								}
							}
						}
						break;
					case 'b':

						x = xAsis + 1;
						y = yAsis + 1;
						while (x < 8 && y < 8)
						{
							if (Positions.ChessBoard[y][x] < 91)
							{
								AddNextMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x++;
							y++;
						}
						x = xAsis - 1;
						y = yAsis - 1;
						while (x >= 0 && y >= 0)
						{
							if (Positions.ChessBoard[y][x] < 91)
							{
								AddNextMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x--;
							y--;
						}
						x = xAsis - 1;
						y = yAsis + 1;
						while (y < 8 && x >= 0)
						{
							if (Positions.ChessBoard[y][x] < 91)
							{
								AddNextMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x--;
							y++;
						}
						x = xAsis + 1;
						y = yAsis - 1;
						while (y >= 0 && x < 8)
						{
							if (Positions.ChessBoard[y][x] < 91)
							{
								AddNextMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x++;
							y--;
						}
						break;
					case 'q':
						for (int x = xAsis + 1; x < 8; x++)
						{
							if (Positions.ChessBoard[i][x] < 91)
							{
								AddNextMove(j, i, x, i);
							}
							else break;
							if (Positions.ChessBoard[i][x] != ' ') break;
						}
						for (int x = xAsis - 1; x >= 0; x--)
						{
							if (Positions.ChessBoard[i][x] < 91)
							{
								AddNextMove(j, i, x, i);
							}
							else break;
							if (Positions.ChessBoard[i][x] != ' ') break;
						}
						for (int y = yAsis + 1; y < 8; y++)
						{
							if (Positions.ChessBoard[y][j] < 91)
							{
								AddNextMove(j, i, j, y);
							}
							else break;
							if (Positions.ChessBoard[y][j] != ' ') break;
						}
						for (int y = yAsis - 1; y >= 0; y--)
						{
							if (Positions.ChessBoard[y][j] < 91)
							{
								AddNextMove(j, i, j, y);
							}
							else break;
							if (Positions.ChessBoard[y][j] != ' ') break;
						}
						//int x, y;
						x = xAsis + 1;
						y = yAsis + 1;
						while (x < 8 && y < 8)
						{
							if (Positions.ChessBoard[y][x] < 91)
							{
								AddNextMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x++;
							y++;
						}
						x = xAsis - 1;
						y = yAsis - 1;
						while (x >= 0 && y >= 0)
						{
							if (Positions.ChessBoard[y][x] < 91)
							{
								AddNextMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x--;
							y--;
						}
						x = xAsis - 1;
						y = yAsis + 1;
						while (y < 8 && x >= 0)
						{
							if (Positions.ChessBoard[y][x] < 91)
							{
								AddNextMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x--;
							y++;
						}
						x = xAsis + 1;
						y = yAsis - 1;
						while (y >= 0 && x < 8)
						{
							if (Positions.ChessBoard[y][x] < 91)
							{
								AddNextMove(j, i, x, y);
							}
							else break;
							if (Positions.ChessBoard[y][x] != ' ') break;
							x++;
							y--;
						}
						break;
					case 'k':
						if (i + 1 < 8)
						{
							if (j + 1 < 8)
							{
								if (Positions.ChessBoard[i + 1][j + 1] < 91)
								{
									AddNextMove(j, i, j + 1, i + 1);
								}
								if (Positions.ChessBoard[i][j + 1] < 91)
								{
									AddNextMove(j, i, j + 1, i);
								}
							}
							if (j - 1 >= 0)
							{
								if (Positions.ChessBoard[i + 1][j - 1] < 91)
								{
									AddNextMove(j, i, j - 1, i + 1);
								}
							}
							if (Positions.ChessBoard[i + 1][j] < 91)
							{
								AddNextMove(j, i, j, i + 1);
							}
						}
						if (i - 1 >= 0)
						{
							if (j - 1 >= 0)
							{
								if (Positions.ChessBoard[i - 1][j - 1] < 91)
								{
									AddNextMove(j, i, j - 1, i - 1);
								}
								if (Positions.ChessBoard[i][j - 1] < 91)
								{
									AddNextMove(j, i, j - 1, i);
								}
							}
							if (j + 1 < 8)
							{
								if (Positions.ChessBoard[i - 1][j + 1] < 91)
								{
									AddNextMove(j, i, j + 1, i - 1);
								}
							}
							if (Positions.ChessBoard[i - 1][j] < 91)
							{
								AddNextMove(j, i, j, i - 1);
							}
						}
						break;
					case 'p':
						if (yAsis == 1)
						{
							if (Positions.ChessBoard[yAsis + 1][xAsis] == ' ' && Positions.ChessBoard[yAsis + 2][xAsis] == ' ')
							{
								AddNextMove(j, i, j, i + 2);
							}
						}
						if (yAsis + 1 < 8)
						{
							if (Positions.ChessBoard[yAsis + 1][xAsis] == ' ')
							{
								AddNextMove(j, i, j, i + 1);
							}
							if (xAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis + 1][xAsis + 1] < 91 && Positions.ChessBoard[yAsis + 1][xAsis + 1] != ' ')
								{
									AddNextMove(j, i, j + 1, i + 1);
								}
							}
							if (xAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis + 1][xAsis - 1] < 91 && Positions.ChessBoard[yAsis + 1][xAsis - 1] != ' ')
								{
									AddNextMove(j, i, j - 1, i + 1);
								}
							}
						}
						break;
					default:
						break;
					}
				}
			}
		}
	}
	bool KingCheck(ChessPosition CP)
	{
		int x, y;
		if (!CP.Turn)
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (CP.ChessBoard[i][j] == 'K')
					{
						for (int x = j + 1; x < 8; x++)
						{
							if (CP.ChessBoard[i][x] == 'q' || CP.ChessBoard[i][x] == 'r')
							{
								return true; //////////////////
							}
							else if (41 < CP.ChessBoard[i][x] < 91) break;
						}
						for (int x = j - 1; x >= 0; x--)
						{
							if (CP.ChessBoard[i][x] == 'q' || CP.ChessBoard[i][x] == 'r')
							{
								return true;
							}
							else if (41 < CP.ChessBoard[i][x] < 91) break;
						}
						for (int y = i + 1; y < 8; y++)
						{
							if (CP.ChessBoard[y][j] == 'q' || CP.ChessBoard[y][j] == 'r')
							{
								return true;
							}
							else if (41 < CP.ChessBoard[y][j] < 91) break;
						}
						for (int y = i - 1; y >= 0; y--)
						{
							if (CP.ChessBoard[y][j] == 'q' || CP.ChessBoard[y][j] == 'r')
							{
								return true;
							}
							else if (41 < CP.ChessBoard[y][j] < 91) break;
						}
						x = j + 1;
						y = i + 1;
						while (x < 8 && y < 8)
						{
							if (CP.ChessBoard[y][x] == 'q' || CP.ChessBoard[y][x] == 'b')
							{
								return true;
							}
							else if (41 < CP.ChessBoard[y][x] < 91) break;
							x++;
							y++;
						}
						x = j - 1;
						y = i - 1;
						while (x >= 0 && y >= 0)
						{
							if (CP.ChessBoard[y][x] == 'q' || CP.ChessBoard[y][x] == 'b')
							{
								return true;
							}
							else if (41 < CP.ChessBoard[y][x] < 91) break;
							x--;
							y--;
						}
						x = j - 1;
						y = i + 1;
						while (y < 8 && x >= 0)
						{
							if (CP.ChessBoard[y][x] == 'q' || CP.ChessBoard[y][x] == 'b')
							{
								return true;
							}
							else if (41 < CP.ChessBoard[y][x] < 91) break;
							x--;
							y++;
						}
						x = j + 1;
						y = i - 1;
						while (y >= 0 && x < 8)
						{
							if (CP.ChessBoard[y][x] == 'q' || CP.ChessBoard[y][x] == 'b')
							{
								return true;
							}
							else if (41 < CP.ChessBoard[y][x] < 91) break;
							x++;
							y--;
						}
						if (i + 2 < 8)
						{
							if (j + 1 < 8)
							{
								if (CP.ChessBoard[i + 2][j + 1] == 'n')
								{
									return true;
								}
							}
							if (j - 1 >= 0)
							{
								if (CP.ChessBoard[i + 2][j - 1] == 'n')
								{
									return true;
								}
							}
						}
						if (i - 2 >= 0)
						{
							if (j + 1 < 8)
							{
								if (CP.ChessBoard[i - 2][j + 1] == 'n')
								{
									return true;
								}
							}
							if (j - 1 >= 0)
							{
								if (CP.ChessBoard[i - 2][j - 1] == 'n')
								{
									return true;
								}
							}
						}
						if (j + 2 < 8)
						{
							if (i + 1 < 8)
							{
								if (CP.ChessBoard[i + 1][j + 2] == 'n')
								{
									return true;
								}
							}
							if (i - 1 >= 0)
							{
								if (CP.ChessBoard[i - 1][j + 2] == 'n')
								{
									return true;
								}
							}
						}
						if (j - 2 >= 0)
						{
							if (i + 1 < 8)
							{
								if (CP.ChessBoard[i + 1][j - 2] == 'n')
								{
									return true;
								}
							}
							if (i - 1 >= 0)
							{
								if (CP.ChessBoard[i - 1][j - 2] == 'n')
								{
									return true;
								}
							}
						}
						if (i > 1)
						{
							if (j < 7)
							{
								if (CP.ChessBoard[i - 1][j + 1] == 'p')
								{
									return true;
								}
							}
							if (j > 0)
							{
								if (CP.ChessBoard[i - 1][j - 1] == 'p')
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (CP.ChessBoard[i][j] == 'k')
					{
						for (int x = j + 1; x < 8; x++)
						{
							if (CP.ChessBoard[i][x] == 'Q' || CP.ChessBoard[i][x] == 'R')
							{
								return true; //////////////////
							}
							else if (CP.ChessBoard[i][x] > 91) break;
						}
						for (int x = j - 1; x >= 0; x--)
						{
							if (CP.ChessBoard[i][x] == 'Q' || CP.ChessBoard[i][x] == 'R')
							{
								return true;
							}
							else if (CP.ChessBoard[i][x] > 91) break;
						}
						for (int y = i + 1; y < 8; y++)
						{
							if (CP.ChessBoard[y][j] == 'Q' || CP.ChessBoard[y][j] == 'R')
							{
								return true;
							}
							else if (CP.ChessBoard[y][j] > 91) break;
						}
						for (int y = i - 1; y >= 0; y--)
						{
							if (CP.ChessBoard[y][j] == 'Q' || CP.ChessBoard[y][j] == 'R')
							{
								return true;
							}
							else if (CP.ChessBoard[y][j] > 91) break;
						}
						x = j + 1;
						y = i + 1;
						while (x < 8 && y < 8)
						{
							if (CP.ChessBoard[y][x] == 'Q' || CP.ChessBoard[y][x] == 'B')
							{
								return true;
							}
							else if (CP.ChessBoard[y][x] > 91) break;
							x++;
							y++;
						}
						x = j - 1;
						y = i - 1;
						while (x >= 0 && y >= 0)
						{
							if (CP.ChessBoard[y][x] == 'Q' || CP.ChessBoard[y][x] == 'B')
							{
								return true;
							}
							else if (CP.ChessBoard[y][x] > 91) break;
							x--;
							y--;
						}
						x = j - 1;
						y = i + 1;
						while (y < 8 && x >= 0)
						{
							if (CP.ChessBoard[y][x] == 'Q' || CP.ChessBoard[y][x] == 'B')
							{
								return true;
							}
							else if (CP.ChessBoard[y][x] > 91) break;
							x--;
							y++;
						}
						x = j + 1;
						y = i - 1;
						while (y >= 0 && x < 8)
						{
							if (CP.ChessBoard[y][x] == 'Q' || CP.ChessBoard[y][x] == 'B')
							{
								return true;
							}
							else if (CP.ChessBoard[y][x] > 91) break;
							x++;
							y--;
						}
						if (i + 2 < 8)
						{
							if (j + 1 < 8)
							{
								if (CP.ChessBoard[i + 2][j + 1] == 'N')
								{
									return true;
								}
							}
							if (j - 1 >= 0)
							{
								if (CP.ChessBoard[i + 2][j - 1] == 'N')
								{
									return true;
								}
							}
						}
						if (i - 2 >= 0)
						{
							if (j + 1 < 8)
							{
								if (CP.ChessBoard[i - 2][j + 1] == 'N')
								{
									return true;
								}
							}
							if (j - 1 >= 0)
							{
								if (CP.ChessBoard[i - 2][j - 1] == 'N')
								{
									return true;
								}
							}
						}
						if (j + 2 < 8)
						{
							if (i + 1 < 8)
							{
								if (CP.ChessBoard[i + 1][j + 2] == 'N')
								{
									return true;
								}
							}
							if (i - 1 >= 0)
							{
								if (CP.ChessBoard[i - 1][j + 2] == 'N')
								{
									return true;
								}
							}
						}
						if (j - 2 >= 0)
						{
							if (i + 1 < 8)
							{
								if (CP.ChessBoard[i + 1][j - 2] == 'N')
								{
									return true;
								}
							}
							if (i - 1 >= 0)
							{
								if (CP.ChessBoard[i - 1][j - 2] == 'N')
								{
									return true;
								}
							}
						}
						if (i < 7)
						{
							if (j < 7)
							{
								if (CP.ChessBoard[i + 1][j + 1] == 'P')
								{
									return true;
								}
							}
							if (j > 0)
							{
								if (CP.ChessBoard[i + 1][j - 1] == 'P')
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
		return false;
	}
	void AddNextMove(int x, int y, int x1, int y1) ///////////////////////////////////// No check on checked king.
	{
		ChessPosition tempPos = *CurrentPos;
		tempPos.ChessBoard[y1][x1] = tempPos.ChessBoard[y][x];
		tempPos.ChessBoard[y][x] = ' ';
		if (CurrentPos->Turn) tempPos.Turn = false;
		else tempPos.Turn = true;
		if (!KingCheck(tempPos))
		{
			tempPos.NextPositions.clear();
			string a = { char(x + 97), char(8 - y + 48), char(x1 + 97), char(8 - y1 + 48) };
			tempPos.LastMove = a;
			tempPos.PreviousPosition = CurrentPos;
			CurrentPos->NextPositions.emplace_back(tempPos);
		}

	}
	string GetMove()  //////////////////////////////////////
	{
		if (CurrentPos->NextPositions.size() == 0) // If there are no next positions those needs to be calculated
		{
			GenerateNextLevel();
		}
		string tempMove;
		if (CurrentPos->NextPositions.size() > 0)
		{
			srand(time(NULL));
			auto r = rand() % CurrentPos->NextPositions.size();
			tempMove = CurrentPos->NextPositions[r].LastMove;
			//CurrentPos = &CurrentPos->NextPositions[r];
			//CurrentPos->LastMove = tempMove;
			//CurrentPos->NextPositions.clear();
		}
		return tempMove;
	}
	void Move(string Move)
	{
		if (CurrentPos->NextPositions.size() == 0) // If there are no next positions those needs to be calculated
		{
			GenerateNextLevel();
		}
		for (int i = 0; i < CurrentPos->NextPositions.size(); i++) // Searching for legal move
		{
			if (CurrentPos->NextPositions[i].LastMove == Move)
			{
				CurrentPos = &CurrentPos->NextPositions[i];
				return;
			}
		}
			//CurrentPos.ChessBoard[7 - (Move[3] - 49)][Move[2] - 97] = CurrentPos.ChessBoard[7 - (Move[1] - 49)][Move[0] - 97];
			//CurrentPos.ChessBoard[7 - (Move[1] - 49)][Move[0] - 97] = ' ';
			//CurrentPos.Turn = 0;
	}
	void Reset()
	{
		CurrentPos = Start;
	}
	~PositionGenerator()
	{

	}

private:
	ChessPosition* CurrentPos,* Start;
};