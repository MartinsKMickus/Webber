#include "Generator.h"


	PositionGenerator::PositionGenerator()
	{
		CurrentPos = new ChessPosition();
		Start = CurrentPos;
		ReferencePos = CurrentPos;
		GenerateNextLevel();
		//CurrentPos.BAttackedSquares;
	}
	void PositionGenerator::DiagnosticPrint()
	{
		cout << endl;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << CurrentPos->ChessBoard[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		/*for (int i = 0; i < 8; i++)
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
		}*/
	}
	void PositionGenerator::GenerateNextLevel()
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
						if (xAsis - 2 >= 0)
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
						if (Positions.WC)
						{
							if (Positions.ChessBoard[7][1] == ' ' && Positions.ChessBoard[7][2] == ' ' && Positions.ChessBoard[7][3] == ' ')
							{
								AddNextMoveCas(2);
							}
						}
						if (Positions.Wc)
						{
							if (Positions.ChessBoard[7][6] == ' ' && Positions.ChessBoard[7][5] == ' ')
							{
								AddNextMoveCas(3);
							}
						}
						if (i + 1 < 8)
						{
							if (j + 1 < 8)
							{
								if (Positions.ChessBoard[i + 1][j + 1] > 91 || Positions.ChessBoard[i + 1][j + 1] == ' ')
								{
									AddNextMove(j, i, j + 1, i + 1);
								}
							}
							if (j - 1 >= 0)
							{
								if (Positions.ChessBoard[i + 1][j - 1] > 91 || Positions.ChessBoard[i + 1][j - 1] == ' ')
								{
									AddNextMove(j, i, j - 1, i + 1);
								}
							}
							if (Positions.ChessBoard[i + 1][j] > 91 || Positions.ChessBoard[i + 1][j] == ' ')
							{
								AddNextMove(j, i, j, i + 1);
							}
						}
						if (i - 1 >= 0)
						{
							if (j - 1 >= 0)
							{
								if (Positions.ChessBoard[i - 1][j - 1] > 91 || Positions.ChessBoard[i - 1][j - 1] == ' ')
								{
									AddNextMove(j, i, j - 1, i - 1);
								}
							}
							if (j + 1 < 8)
							{
								if (Positions.ChessBoard[i - 1][j + 1] > 91 || Positions.ChessBoard[i - 1][j + 1] == ' ')
								{
									AddNextMove(j, i, j + 1, i - 1);
								}
							}
							if (Positions.ChessBoard[i - 1][j] > 91 || Positions.ChessBoard[i - 1][j] == ' ')
							{
								AddNextMove(j, i, j, i - 1);
							}
						}
						if (j + 1 < 8)
						{
							if (Positions.ChessBoard[i][j + 1] > 91 || Positions.ChessBoard[i][j + 1] == ' ')
							{
								AddNextMove(j, i, j + 1, i);
							}
						}
						if (j - 1 >= 0)
						{
							if (Positions.ChessBoard[i][j - 1] > 91 || Positions.ChessBoard[i][j - 1] == ' ')
							{
								AddNextMove(j, i, j - 1, i);
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
						if (yAsis > 1)
						{
							if (Positions.ChessBoard[yAsis - 1][xAsis] == ' ')
							{
								AddNextMove(j, i, j, i - 1);
							}
							if (xAsis + 1 < 8)
							{
								if (Positions.ChessBoard[yAsis - 1][xAsis + 1] > 91 && Positions.ChessBoard[yAsis - 1][xAsis + 1] != ' ') //////////////////
								{
									AddNextMove(j, i, j + 1, i - 1);
								}
								if (Positions.EnPass)
								{
									if (yAsis == 3 && Positions.ChessBoard[yAsis][xAsis + 1] > 91)
									{
										AddNextMoveEnPassant(j, i, j + 1, i - 1);
									}
								}
							}
							if (xAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis - 1][xAsis - 1] > 91 && Positions.ChessBoard[yAsis - 1][xAsis - 1] != ' ') /////////////////
								{
									AddNextMove(j, i, j - 1, i - 1);
								}
								if (Positions.EnPass)
								{
									if (yAsis == 3 && Positions.ChessBoard[yAsis][xAsis - 1] > 91)
									{
										AddNextMoveEnPassant(j, i, j - 1, i - 1);
									}
								}
							}
						}
						if (yAsis == 1)
						{
							if (Positions.ChessBoard[yAsis - 1][xAsis] == ' ')
							{
								AddNextMoveProm(j, i, j, i - 1, 'Q');
								AddNextMoveProm(j, i, j, i - 1, 'R');
								AddNextMoveProm(j, i, j, i - 1, 'B');
								AddNextMoveProm(j, i, j, i - 1, 'N');
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
						if (Positions.BC)
						{
							if (Positions.ChessBoard[0][1] == ' ' && Positions.ChessBoard[0][2] == ' ' && Positions.ChessBoard[0][3] == ' ')
							{
								AddNextMoveCas(0);
							}
						}
						if (Positions.Bc)
						{
							if (Positions.ChessBoard[0][6] == ' ' && Positions.ChessBoard[0][5] == ' ')
							{
								AddNextMoveCas(1);
							}
						}
						if (i + 1 < 8)
						{
							if (j + 1 < 8)
							{
								if (Positions.ChessBoard[i + 1][j + 1] < 91)
								{
									AddNextMove(j, i, j + 1, i + 1);
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
						if (j + 1 < 8)
						{
							if (Positions.ChessBoard[i][j + 1] < 91)
							{
								AddNextMove(j, i, j + 1, i);
							}
						}
						if (j - 1 >= 0)
						{
							if (Positions.ChessBoard[i][j - 1] < 91)
							{
								AddNextMove(j, i, j - 1, i);
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
						if (yAsis < 6)
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
								if (Positions.EnPass)
								{
									if (yAsis == 4 && Positions.ChessBoard[yAsis][xAsis + 1] < 91 && Positions.ChessBoard[yAsis][xAsis + 1] != ' ')
									{
										AddNextMoveEnPassant(j, i, j + 1, i + 1);///////////////////////////// En passant
									}
								}
							}
							if (xAsis - 1 >= 0)
							{
								if (Positions.ChessBoard[yAsis + 1][xAsis - 1] < 91 && Positions.ChessBoard[yAsis + 1][xAsis - 1] != ' ')
								{
									AddNextMove(j, i, j - 1, i + 1);
								}
								if (Positions.EnPass)
								{
									if (yAsis == 4 && Positions.ChessBoard[yAsis][xAsis - 1] < 91 && Positions.ChessBoard[yAsis][xAsis - 1] != ' ')
									{
										AddNextMoveEnPassant(j, i, j - 1, i + 1);
									}
								}
							}
						}
						if (yAsis == 6)
						{
							if (Positions.ChessBoard[yAsis + 1][xAsis] == ' ')
							{
								AddNextMoveProm(j, i, j, i + 1, 'q');
								AddNextMoveProm(j, i, j, i + 1, 'r');
								AddNextMoveProm(j, i, j, i + 1, 'b');
								AddNextMoveProm(j, i, j, i + 1, 'n');
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
	bool PositionGenerator::KingCheck(ChessPosition CP, int j = -1, int i = -1)
	{
		int x, y;
		if (!CP.Turn)
		{
			if (j == -1 || i == -1)
			{
				i = CP.WKing[0];
				j = CP.WKing[1];
			}
			//for (int i = 0; i < 8; i++)
			//{
				//for (int j = 0; j < 8; j++)
				//{
					//if (CP.ChessBoard[i][j] == 'K')
					//{
						for (x = j + 1; x < 8; x++)
						{
							if (CP.ChessBoard[i][x] == 'q' || CP.ChessBoard[i][x] == 'r')
							{
								return true; //////////////////
							}
							else if (CP.ChessBoard[i][x] != ' ') break;
						}
						for (x = j - 1; x >= 0; x--)
						{
							if (CP.ChessBoard[i][x] == 'q' || CP.ChessBoard[i][x] == 'r')
							{
								return true;
							}
							else if (CP.ChessBoard[i][x] != ' ') break;
						}
						for (y = i + 1; y < 8; y++)
						{
							if (CP.ChessBoard[y][j] == 'q' || CP.ChessBoard[y][j] == 'r')
							{
								return true;
							}
							else if (CP.ChessBoard[y][j] != ' ') break;
						}
						for (y = i - 1; y >= 0; y--)
						{
							if (CP.ChessBoard[y][j] == 'q' || CP.ChessBoard[y][j] == 'r')
							{
								return true;
							}
							else if (CP.ChessBoard[y][j] != ' ') break;
						}
						x = j + 1;
						y = i + 1;
						while (x < 8 && y < 8)
						{
							if (CP.ChessBoard[y][x] == 'q' || CP.ChessBoard[y][x] == 'b')
							{
								return true;
							}
							else if (CP.ChessBoard[y][x] != ' ') break;
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
							else if (CP.ChessBoard[y][x] != ' ') break;
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
							else if (CP.ChessBoard[y][x] != ' ') break;
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
							else if (CP.ChessBoard[y][x] != ' ') break;
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
						if (i + 1 < 8) ///////////////////////////////////////////////////////////////////////
						{
							if (j + 1 < 8)
							{
								if (CP.ChessBoard[i + 1][j + 1] == 'k')
								{
									return true;
								}
								if (CP.ChessBoard[i][j + 1] == 'k')
								{
									return true;
								}
							}
							if (j - 1 >= 0)
							{
								if (CP.ChessBoard[i + 1][j - 1] == 'k')
								{
									return true;
								}
							}
							if (CP.ChessBoard[i + 1][j] == 'k')
							{
								return true;
							}
						}
						if (i - 1 >= 0)
						{
							if (j - 1 >= 0)
							{
								if (CP.ChessBoard[i - 1][j - 1] == 'k')
								{
									return true;
								}
								if (CP.ChessBoard[i][j - 1] == 'k')
								{
									return true;
								}
							}
							if (j + 1 < 8)
							{
								if (CP.ChessBoard[i - 1][j + 1] == 'k')
								{
									return true;
								}
							}
							if (CP.ChessBoard[i - 1][j] == 'k')
							{
								return true;
							}
						}
					//}
				//}
			//}
		}
		else
		{
		if (j == -1 || i == -1)
		{
			i = CP.BKing[0];
			j = CP.BKing[1];
		}
			//for (int i = 0; i < 8; i++)
			//{
				//for (int j = 0; j < 8; j++)
				//{
					//if (CP.ChessBoard[i][j] == 'k')
					//{
						for (x = j + 1; x < 8; x++)
						{
							if (CP.ChessBoard[i][x] == 'Q' || CP.ChessBoard[i][x] == 'R')
							{
								return true; //////////////////
							}
							else if (CP.ChessBoard[i][x] != ' ') break;
						}
						for (x = j - 1; x >= 0; x--)
						{
							if (CP.ChessBoard[i][x] == 'Q' || CP.ChessBoard[i][x] == 'R')
							{
								return true;
							}
							else if (CP.ChessBoard[i][x] != ' ') break;
						}
						for (y = i + 1; y < 8; y++)
						{
							if (CP.ChessBoard[y][j] == 'Q' || CP.ChessBoard[y][j] == 'R')
							{
								return true;
							}
							else if (CP.ChessBoard[y][j] != ' ') break;
						}
						for (y = i - 1; y >= 0; y--)
						{
							if (CP.ChessBoard[y][j] == 'Q' || CP.ChessBoard[y][j] == 'R')
							{
								return true;
							}
							else if (CP.ChessBoard[y][j] != ' ') break;
						}
						x = j + 1;
						y = i + 1;
						while (x < 8 && y < 8)
						{
							if (CP.ChessBoard[y][x] == 'Q' || CP.ChessBoard[y][x] == 'B')
							{
								return true;
							}
							else if (CP.ChessBoard[y][x] != ' ') break;
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
							else if (CP.ChessBoard[y][x] != ' ') break;
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
							else if (CP.ChessBoard[y][x] != ' ') break;
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
							else if (CP.ChessBoard[y][x] != ' ') break;
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
						if (i + 1 < 8)
						{
							if (j + 1 < 8)
							{
								if (CP.ChessBoard[i + 1][j + 1] == 'K')
								{
									return true;
								}
								if (CP.ChessBoard[i][j + 1] == 'K')
								{
									return true;
								}
							}
							if (j - 1 >= 0)
							{
								if (CP.ChessBoard[i + 1][j - 1] == 'K')
								{
									return true;
								}
							}
							if (CP.ChessBoard[i + 1][j] == 'K')
							{
								return true;
							}
						}
						if (i - 1 >= 0)
						{
							if (j - 1 >= 0)
							{
								if (CP.ChessBoard[i - 1][j - 1] == 'K')
								{
									return true;
								}
								if (CP.ChessBoard[i][j - 1] == 'K')
								{
									return true;
								}
							}
							if (j + 1 < 8)
							{
								if (CP.ChessBoard[i - 1][j + 1] == 'K')
								{
									return true;
								}
							}
							if (CP.ChessBoard[i - 1][j] == 'K')
							{
								return true;
							}
						}
					//}
				//}
			//}
		}
		return false;
	}
	void PositionGenerator::AddNextMove(int x, int y, int x1, int y1)
	{
		ChessPosition tempPos = *CurrentPos;
		char Fig = tempPos.ChessBoard[y1][x1];
		tempPos.ChessBoard[y1][x1] = tempPos.ChessBoard[y][x];
		switch (Fig)
		{
		case 'Q':
			tempPos.valuation -= 90;
			break;
		case 'R':
			tempPos.valuation -= 50;
			break;
		case 'B':
			tempPos.valuation -= 30;
			break;
		case 'N':
			tempPos.valuation -= 30;
			break;
		case 'P':
			tempPos.valuation -= 10;
			break;
		case 'q':
			tempPos.valuation += 90;
			break;
		case 'r':
			tempPos.valuation += 50;
			break;
		case 'b':
			tempPos.valuation += 30;
			break;
		case 'n':
			tempPos.valuation += 30;
			break;
		case 'p':
			tempPos.valuation += 10;
			break;
		default:
			break;
		}
		if (tempPos.ChessBoard[y][x] == 'r') //////////////////////// Can be placed in special function
		{
			
			if (x == 0 && y == 0)
			{
				tempPos.BC = false;
			}
			if (x == 7 && y == 0)
			{
				tempPos.Bc = false;
			}
		}
		else if (tempPos.ChessBoard[y][x] == 'R') //////////////////////// Can be placed in special function
		{
			if (x == 0 && y == 7)
			{
				tempPos.WC = false;
			}
			if (x == 7 && y == 7)
			{
				tempPos.Wc = false;
			}
		}
		tempPos.ChessBoard[y][x] = ' ';
		tempPos.EnPass = false;
		if (tempPos.ChessBoard[y1][x1] == 'k') //////////////////////// Can be placed in special function
		{
			tempPos.BKing[0] = y1;
			tempPos.BKing[1] = x1;
			tempPos.BC = false;
			tempPos.Bc = false;
		}
		else if (tempPos.ChessBoard[y1][x1] == 'K') //////////////////////// Can be placed in special function
		{
			tempPos.WKing[0] = y1;
			tempPos.WKing[1] = x1;
			tempPos.WC = false;
			tempPos.Wc = false;
		}
		else if ((y - y1 == 2 || y - y1 == -2) && (tempPos.ChessBoard[y1][x1] == 'p' || tempPos.ChessBoard[y1][x1] == 'P'))
		{
			tempPos.EnPass = true;
		}
		//if (CurrentPos->Turn) tempPos.Turn = false; ////////////////////////////////////////////
		tempPos.Turn = !CurrentPos->Turn;
		if (!KingCheck(tempPos)) // Check if king is in check.
		{
			tempPos.NextPositions.clear();
			string a = { char(x + 97), char(8 - y + 48), char(x1 + 97), char(8 - y1 + 48) };
			tempPos.LastMove = a;
			tempPos.PreviousPosition = CurrentPos;
			CurrentPos->NextPositions.emplace_back(tempPos);
		}
	}
	/// <summary>
	/// 
	/// </summary>
	/// <param name="opt">0 - Black Long, 1 - Black Short, 2 - White Long, 3 - White Short</param>
	void PositionGenerator::AddNextMoveCas(int opt)
	{
		
		int RX, RY, KX, KY, RXTo, RYTo, KXTo, KYTo;
		string Move;
		ChessPosition tempPos = *CurrentPos;
		tempPos.Turn = !CurrentPos->Turn;
		if (KingCheck(tempPos)) return;
		switch (opt)
		{
		case 0:
			RX = 0, RY = 0, KX = 4, KY = 0, RXTo = 3, RYTo = 0, KXTo = 2, KYTo = 0;
			Move = "e8c8";
			if (KingCheck(tempPos, 1, 0)) return;
			if (KingCheck(tempPos, 3, 0)) return;
			tempPos.BC = false;
			tempPos.Bc = false;
			tempPos.BKing[0] = 0;
			tempPos.BKing[1] = 2;
			break;
		case 1:
			RX = 7, RY = 0, KX = 4, KY = 0, RXTo = 5, RYTo = 0, KXTo = 6, KYTo = 0;
			Move = "e8g8";
			if (KingCheck(tempPos, 5, 0)) return;
			tempPos.BC = false;
			tempPos.Bc = false;
			tempPos.BKing[0] = 0;
			tempPos.BKing[1] = 6;
			break;
		case 2:
			RX = 0, RY = 7, KX = 4, KY = 7, RXTo = 3, RYTo = 7, KXTo = 2, KYTo = 7;
			Move = "e1c1";
			if (KingCheck(tempPos, 1, 7)) return;
			if (KingCheck(tempPos, 3, 7)) return;
			tempPos.WC = false;
			tempPos.Wc = false;
			tempPos.WKing[0] = 7;
			tempPos.WKing[1] = 2;
			break;
		case 3:
			RX = 7, RY = 7, KX = 4, KY = 7, RXTo = 5, RYTo = 7, KXTo = 6, KYTo = 7;
			Move = "e1g1";
			if (KingCheck(tempPos, 5, 7)) return;
			tempPos.WC = false;
			tempPos.Wc = false;
			tempPos.WKing[0] = 7;
			tempPos.WKing[1] = 6;
			break;
		default:
			return;
		}
		 ///////////////////////////////////////////
		if (KingCheck(tempPos)) return;
		tempPos.ChessBoard[RYTo][RXTo] = tempPos.ChessBoard[RY][RX];
		tempPos.ChessBoard[RY][RX] = ' ';
		tempPos.ChessBoard[KYTo][KXTo] = tempPos.ChessBoard[KY][KX];
		tempPos.ChessBoard[KY][KX] = ' ';
		tempPos.NextPositions.clear();
		tempPos.LastMove = Move;
		tempPos.PreviousPosition = CurrentPos;
		CurrentPos->NextPositions.emplace_back(tempPos);
	}
	void PositionGenerator::AddNextMoveEnPassant(int x, int y, int x1, int y1)
	{
		ChessPosition tempPos = *CurrentPos;
		tempPos.ChessBoard[y1][x1] = tempPos.ChessBoard[y][x];
		tempPos.ChessBoard[y][x] = ' ';
		if (tempPos.ChessBoard[y][x1] == 'p')
		{
			tempPos.valuation += 10;
		}
		else
		{
			tempPos.valuation -= 10;
		}
		tempPos.ChessBoard[y][x1] = ' ';
		tempPos.EnPass = false;
		if (CurrentPos->Turn) tempPos.Turn = false; ////////////////////////////////////////////
		else tempPos.Turn = true;
		if (!KingCheck(tempPos)) // Check if king is in check.
		{
			tempPos.NextPositions.clear();
			string a = { char(x + 97), char(8 - y + 48), char(x1 + 97), char(8 - y1 + 48) };
			tempPos.LastMove = a;
			tempPos.PreviousPosition = CurrentPos;
			CurrentPos->NextPositions.emplace_back(tempPos);
		}
	}
	void PositionGenerator::AddNextMoveProm(int x, int y, int x1, int y1, char Fig)
	{
		ChessPosition tempPos = *CurrentPos;
		tempPos.ChessBoard[y1][x1] = Fig;
		tempPos.ChessBoard[y][x] = ' ';
		if (CurrentPos->Turn)
		{
			tempPos.Turn = false; ////////////////////////////////////////////
			Fig += 32;
			switch (Fig)
			{
			case 'Q':
				tempPos.valuation += 80;
				break;
			case 'R':
				tempPos.valuation += 40;
				break;
			case 'B':
				tempPos.valuation += 20;
				break;
			case 'N':
				tempPos.valuation += 20;
				break;
			case 'q':
				tempPos.valuation -= 80;
				break;
			case 'r':
				tempPos.valuation -= 40;
				break;
			case 'b':
				tempPos.valuation -= 20;
				break;
			case 'n':
				tempPos.valuation -= 20;
				break;
			default:
				break;
			}
		}
		else tempPos.Turn = true;
		if (!KingCheck(tempPos)) // Check if king is in check.
		{
			tempPos.NextPositions.clear();
			string a = { char(x + 97), char(8 - y + 48), char(x1 + 97), char(8 - y1 + 48), Fig };
			tempPos.LastMove = a;
			tempPos.PreviousPosition = CurrentPos;
			CurrentPos->NextPositions.emplace_back(tempPos);
		}
	}
	string PositionGenerator::GetMove()  //////////////////////////////////////
	{
		if (CurrentPos->NextPositions.size() == 0) // If there are no next positions those needs to be calculated
		{
			GenerateNextLevel();
			if (CurrentPos->NextPositions.size() == 0) return "bad";
		}
		vector<string> Bmoves;
		int Val = CurrentPos->NextPositions[0].valuation;
		if (CurrentPos->Turn)
		{
			for (int i = 0; i < CurrentPos->NextPositions.size(); i++)
			{
				if (Val < CurrentPos->NextPositions[i].valuation)
				{
					Val = CurrentPos->NextPositions[i].valuation;
				}
			}	
		}
		else
		{
			for (int i = 0; i < CurrentPos->NextPositions.size(); i++)
			{
				if (Val > CurrentPos->NextPositions[i].valuation)
				{
					Val = CurrentPos->NextPositions[i].valuation;
				}
			}
		}
		for (int i = 0; i < CurrentPos->NextPositions.size(); i++)
		{
			if (Val == CurrentPos->NextPositions[i].valuation)
			{
				Bmoves.emplace_back(CurrentPos->NextPositions[i].LastMove);
			}
		}
		srand(time(NULL));
		auto r = rand() % Bmoves.size();
		return Bmoves[r];
		/*if (CurrentPos->NextPositions.size() > 0)
		{
			srand(time(NULL));
			auto r = rand() % CurrentPos->NextPositions.size();
			tempMove = CurrentPos->NextPositions[r].LastMove;
		}*/
	}
	void PositionGenerator::Move(string Move)
	{
		if (CurrentPos->NextPositions.size() == 0) // If there are no next positions those needs to be calculated
		{
			GenerateNextLevel();
		}
		if (CurrentPos->Purged)
		{
			CurrentPos->NextPositions.clear();
			GenerateNextLevel();
			CurrentPos->Purged = false;
		}
		for (int i = 0; i < CurrentPos->NextPositions.size();) // Searching for legal move
		{
			if (CurrentPos->NextPositions[i].LastMove != Move)
			{
				CurrentPos->NextPositions.erase(CurrentPos->NextPositions.begin() + i);
				//CurrentPos = &CurrentPos->NextPositions[i];
				//ReferencePos = CurrentPos;
				//return;
			}
			else
			{
				i++;
			}
		}
		CurrentPos->Purged = true;
		CurrentPos = &CurrentPos->NextPositions[0];
		ReferencePos = CurrentPos;
		return;
		/*if (CurrentPos->NextPositions[0].LastMove == Move)
		{
			CurrentPos = &CurrentPos->NextPositions[0];
			return;
		}*/
	}
	void PositionGenerator::SyncAnalyzeMove()
	{
		CurrentPos = ReferencePos;
	}
	bool PositionGenerator::CheckAnalyzeSync()
	{
		if (CurrentPos == ReferencePos) return true;
		else return false;
	}
	void PositionGenerator::Reset()
	{
		CurrentPos = Start;
	}
	PositionGenerator::~PositionGenerator()
	{

	}
	