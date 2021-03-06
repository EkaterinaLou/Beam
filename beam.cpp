#include <iostream>
#include <iomanip>

using namespace std;



class MAP // имя класса
{
private:

	int** POLE;
	int N;
	int M;

public:
	MAP()
	{
		N = M = 7;
		POLE = new int* [N];
		for (int i = 0; i < 7; i++)
		{
			POLE[i] = new int[M];
		};
	}
	MAP(int n_size, int m_size)
	{
		N = n_size;
		M = m_size;
		POLE = new int* [N];
		for (int i = 0; i < N; i++)
		{
			POLE[i] = new int[M];
		};
	}
	~MAP()
	{
		for (int i = 0; i < N; i++)
		{
			delete POLE[i];
		}
		delete[]POLE;
	}
	////////////////////////////////////////////////////////
	void C()
	{
		cout << "Построение карты: " << endl << endl;
		/*POLE[M][N] = { {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {3}, {1}, {1}, {1}, {0}, {0}, {0}, {1}, {1}, {0}, {1}, {1}, {0}, {0}, {0}, {1}, {1}, {1}, {1}, {0}, {0}, {1}, {1}, {1}, {0}, {1}, {0},

		   {0}, {1}, {0}, {1}, {1}, {2}, {0},

		   {0}, {0}, {0}, {0}, {0}, {0}, {0} };*/
		POLE[0][0] = 51; POLE[0][1] = 51; POLE[0][2] = 51; POLE[0][3] = 51; POLE[0][4] = 51; POLE[0][5] = 51; POLE[0][6] = 51;
		POLE[1][0] = 51; POLE[1][1] = 49; POLE[1][2] = 50; POLE[1][3] = 50; POLE[1][4] = 50; POLE[1][5] = 51; POLE[1][6] = 51;
		POLE[2][0] = 51; POLE[2][1] = 50; POLE[2][2] = 50; POLE[2][3] = 51; POLE[2][4] = 50; POLE[2][5] = 50; POLE[2][6] = 51;
		POLE[3][0] = 51; POLE[3][1] = 50; POLE[3][2] = 50; POLE[3][3] = 50; POLE[3][4] = 50; POLE[3][5] = 50; POLE[3][6] = 51;
		POLE[4][0] = 51; POLE[4][1] = 50; POLE[4][2] = 50; POLE[4][3] = 50; POLE[4][4] = 51; POLE[4][5] = 50; POLE[4][6] = 51;
		POLE[5][0] = 51; POLE[5][1] = 50; POLE[5][2] = 50; POLE[5][3] = 50; POLE[5][4] = 50; POLE[5][5] = 0; POLE[5][6] = 51;
		POLE[6][0] = 51; POLE[6][1] = 51; POLE[6][2] = 51; POLE[6][3] = 51; POLE[6][4] = 51; POLE[6][5] = 51; POLE[6][6] = 51;
		///////////////////////////////////////
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				switch (POLE[i][j])
				{
				case 51:
				{
					cout << setw(3) << '#';
					break;
				}
				case 50:
				{
					cout << setw(3) << '.';
					break;
				}
				case 49:
				{
					cout << setw(3) << 'A';
					break;
				}
				case 0:
				{
					cout << setw(3) << 'B';
					break;
				}
				}
			}
			cout << endl;
		}
		//////////////////////////////////////////////////////////

		cout << endl;
	}
	////////////////////////////////////////////////////////////////
	void show()
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cout << POLE[i][j] << " ";
			}
			cout << endl;
		}
	}
	///////////////////////////////////////////////////////////////
	void light()
	{
		bool a = true;
		bool b = true;
		int d;
		int dx;
		int dy;
		int X2;
		int Y2;
		int X1;
		int Y1;
		int LIGHT[7][7];
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				LIGHT[i][j] = POLE[i][j];
			}
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				switch (POLE[i][j]) {
				case 49:
				{X1 = i;
				Y1 = j;
				break; }

				case 0:
				{X2 = i;
				Y2 = j;
				dx = X2 - X1;
				dy = Y2 - Y1;
				break; }
				}
			}
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				//while (b == true)
				//{
					//if ((POLE[i][j] != 49)&&(POLE[i][j] != -2))
					//{
						//break;
					//}
				if ((POLE[i][j] == 49) && (a == true))
				{
					X1 = i;
					Y1 = j;
					dx = X2 - X1;
					dy = Y2 - Y1;
					d = dx + dy;
					if ((POLE[i + 1][j] != 0) || (POLE[i + 1][j + 1] != 0) || (POLE[i][j + 1] != 0))
					{
						if ((POLE[i + 1][j] == 50) && (d >= (X2 - (i + 1)) + (Y2 - (j + 1))))
						{
							POLE[i + 1][j] = -2;
							d = (X2 - (i + 1)) + (Y2 - (j + 1));
							//break;
						}
						else
						{
							if ((POLE[i][j + 1] == 50) && (d >= (X2 - (i + 1)) + (Y2 - (j + 1))))
							{
								POLE[i][j + 1] = -2;
								d = (X2 - (i + 1)) + (Y2 - (j + 1));
								//break;
							}
							else
							{
								if ((POLE[i + 1][j + 1] == 50) && (d >= (X2 - (i + 1)) + (Y2 - (j + 1))))
								{
									POLE[i + 1][j + 1] = -2;
									d = (X2 - (i + 1)) + (Y2 - (j + 1));
									//break;
								}
							}
						}

					}
					else
					{
						if ((POLE[i + 1][j] == 0) || (POLE[i + 1][j + 1] == 0) || (POLE[i][j + 1] == 0))
						{
							cout << endl << endl << "End";
							b = false;
							//break;
						}
					}
					a = false;
				}
				else
				{
					if (POLE[i][j] == -2)
					{
						X1 = i;
						Y1 = j;
						dx = X2 - X1;
						dy = Y2 - Y1;
						d = dx + dy;
						if ((POLE[i + 1][j] != 0) || (POLE[i + 1][j + 1] != 0) || (POLE[i][j + 1] != 0))
						{
							if ((POLE[i + 1][j] == 50) && (d >= (X2 - (i + 1)) + (Y2 - (j + 1))))
							{
								POLE[i + 1][j] = -2;
								POLE[i][j] = -1;
								d = (X2 - (i + 1)) + (Y2 - (j + 1));
								//break;
							}
							else
							{
								if ((POLE[i][j + 1] == 50) && (d >= (X2 - (i + 1)) + (Y2 - (j + 1))))
								{
									POLE[i][j + 1] = -2;
									POLE[i][j] = -1;
									d = (X2 - (i + 1)) + (Y2 - (j + 1));
									//break;
								}
								else
								{
									if ((POLE[i + 1][j + 1] == 50) && (d >= (X2 - (i + 1)) + (Y2 - (j + 1))))
									{
										POLE[i + 1][j + 1] = -2;
										POLE[i][j] = -1;
										d = (X2 - (i + 1)) + (Y2 - (j + 1));
										//break;
									}
								}
							}

						}
						else
						{
							if ((POLE[i + 1][j] == 0) || (POLE[i + 1][j + 1] == 0) || (POLE[i][j + 1] == 0))
							{
								cout << endl << endl << "End";
								b = false;
								//break;
							}

						}
					}
					///else
					///{
						///if ((POLE[i + 1][j] == 51) && (POLE[i + 1][j + 1] == 51) && (POLE[i][j + 1] == 51))
						///{
							///b = false;
							///cout << endl << endl << "No End";
							//break;
						///}
						//else
						//{
							//break;
						//}
					///}


				}

				//}

			}
		}
		cout << endl;
		cout << endl;

		/// ////////////////////////////////////////////////

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				switch (POLE[i][j]) {
				case 51:
				{cout << setw(3) << '#';
				break; }

				case 50:
				{cout << setw(3) << '.';
				break; }

				case 49: {cout << setw(3) << 'A';
					break; }

				case 0: {cout << setw(3) << 'B';
					break; }

				case -1: {cout << setw(3) << '|';
					break; }
				case -2: {cout << setw(3) << '|';
					break; }
				}
			}
			cout << endl;
		}
		////////////////////////////////////////
	}
};


int main()
{
	setlocale(0, "");
	cout << endl;
	MAP c(7, 7);

	c.C();

	cout << "Массив для построения карты: " << endl << endl;
	c.show();

	cout << "Лучевой" << endl << endl;
	c.light();

	system("pause");
	return 0;
}