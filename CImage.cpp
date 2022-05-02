#include "CImage.h"


CImage::CImage()
	:m_pTab(NULL), m_nNbRow(0), m_nNbCol(0), m_pBin(NULL)
{
}
CImage::~CImage()
{
	if (m_pTab != NULL) {
		for (int i = 0; i < m_nNbRow; ++i) {
			if (m_pTab[i] != NULL)
			{
				delete[] m_pTab[i];
			}
		}
		delete[] m_pTab;
	}

	// bin
	if (m_pBin != NULL) {
		for (int i = 0; i < m_nNbRow; ++i) {
			if (m_pBin[i] != NULL)
			{
				delete[] m_pBin[i];
			}
		}
		delete[] m_pBin;
	}
	// int 
	/*if (m_pDec != NULL) {
		for (int i = 0; i < m_nNbRow; ++i) {
			if (m_pDec[i] != NULL)
			{
				delete[] m_pDec[i];
			}
		}
		delete[] m_pDec;
	}*/
}

CImage::CImage(int Row, int Col)
	:m_pTab(NULL), m_nNbRow(Row), m_nNbCol(Col), m_pBin(NULL)
{
	if (m_nNbRow > 0) {
		m_pTab = new unsigned char* [m_nNbRow];
		if (m_nNbCol > 0)
		{
			for (int i = 0; i < m_nNbRow; ++i) {
				m_pTab[i] = new unsigned char[m_nNbCol];
			}
		}
	}
	for (int i = 0; i < m_nNbRow; ++i)
		for (int j = 0; j < m_nNbCol; j++)
			m_pTab[i][j] = rand() % 256;

}


void CImage::save (const char* pName)
{
	ofstream fs;                 
	fs.open(pName, ios::out);                 
	fs << "taille : " << endl;
	fs << "Row : " << m_nNbRow << endl;
	fs << "Col : " << m_nNbCol << endl;
	for (int i = 0; i < m_nNbRow; ++i)
		for (int j = 0; j < m_nNbCol; j++)
			fs << m_pTab[i][j];
	fs.close();                 
}

unsigned int** CImage::seuil()
{
	unsigned char** copy;
	int taille_x = 3;
	int taille_y = 3;
	if (m_nNbRow > 0) {
		m_pBin = new unsigned int* [m_nNbRow];
		if (m_nNbCol > 0)
		{
			for (int i = 0; i < m_nNbRow; ++i) {
				m_pBin[i] = new unsigned int[m_nNbCol];
			}
		}
	}
	// création copy
	if (m_nNbRow > 0) {
		copy = new unsigned char* [m_nNbRow + (taille_x - 1) / 2];
		if (m_nNbCol > 0)
		{
			for (int i = 0; i < m_nNbRow + (taille_x - 1) / 2; ++i) {
				copy[i] = new unsigned char[m_nNbCol + (taille_y - 1) / 2];
			}
		}
		// remplissage
		// full 0;
		for (int i = 0; i < m_nNbRow; ++i)
			for (int j = 0; j < m_nNbCol; j++)
				copy[i][j] = 0;
		for (int i = (taille_x - 1) / 2; i < m_nNbRow + (taille_x - 1) / 2; ++i)
			for (int j = (taille_y - 1) / 2; j < m_nNbCol + (taille_y - 1) / 2; j++)
				copy[i][j] = m_pTab[i - (taille_x - 1) / 2][j - (taille_x - 1) / 2];

	}


	int temp [8];

	for (int i = 0; i < m_nNbRow; ++i)
		for (int j = 0; j < m_nNbCol; j++)
		{
			for (int k = 0; k < taille_x; k++)
				for (int l = 0; l < taille_y; l++)
					//erreur sur les bords ??   ok
					//erreur pour j2 ok
				{
					if (k == 2 &&l == 2) l += 1;     // non responsive
					if (m_pTab[i - (taille_x-1)/2 + k][j - (taille_y - 1) / 2 + l] > m_pTab[i][j]) {
						temp [taille_x + taille_y] =  0;
					}
					else
					temp [taille_x + taille_y] = 1;  //pas dans le bon ordre
				}
			m_pBin[i][j] = temp[0] * pow (10, 7) + temp[1] * pow(10, 6) + temp[2] * pow(10, 5) + temp[3] * pow(10, 4) + temp[4] * pow(10, 3) + temp[5] * pow(10, 2) + temp[6] * pow(10, 1)+ temp[7];
		}
	return m_pBin;
}

CImage CImage::converter()
{
	CImage Dec(m_nNbRow, m_nNbRow);
		for (int i = 0; i < m_nNbRow; ++i)
			for (int j = 0; j < m_nNbCol; j++)
			{
				int decimalNumber = 0;
				int base = 1;
				int temp = m_pBin[i][j];
				while (temp) {
					int lastDigit = temp % 10;
					temp = temp / 10;
					Dec.m_pTab[i][j] += lastDigit * base;
					base = base * 2;
				}

				//dec[i][j] = 
			}
	return Dec;
}


CImage CImage::histogramme() {
	CImage hist(255, 1);
	for (int i = 0; i < m_nNbRow; ++i)
		for (int j = 0; j < m_nNbCol; j++)
			hist.m_pTab[m_pTab[i][j]] = 0;
	for (int i = 0; i < m_nNbRow; ++i)
		for (int j = 0; j < m_nNbCol; j++)
			hist.m_pTab[m_pTab[i][j]] += 1;
	return hist;
}


void CImage::affiche() {
	//COLORREF color(RGB(255, 255, 255)); // RGB(255, 0, 0) = rouge, RGB(0, 255, 0) = vert, RGB(0, 0, 255) = bleu 
	AllocConsole();
	HWND hWND = GetConsoleWindow();          // ou GetForegroundWindow() ou GetDesktopWindow()
	HDC hDC = GetDC(hWND);
	SetConsoleTitle(TEXT("Polytech Orléans"));
	int border_x = 200;
	int border_y = 100;
	//if (hWND != NULL) { SetWindowPos(hWND, 0, 0, 0, (m_nNbRow + 2 * border_y), (m_nNbCol + 2 * border_x), SWP_SHOWWINDOW | SWP_NOMOVE); }
	if (hWND != NULL) { SetWindowPos(hWND,0, 0, 0, (m_nNbCol + 2*border_x +40), (m_nNbRow + 2*border_y +100), SWP_SHOWWINDOW | SWP_NOMOVE); }  //largeur longueur
	COLORREF  color = RGB(0, 255, 0);
	for (int i = 0; i < m_nNbRow + 2*border_y +100; i++)
	{
		for (int j = 0; j < m_nNbCol + 2*border_x +40; j++)
		{

			SetPixel(hDC, j , i , color);
		}
	}
	//color = RGB(255, 0, 0);
	//SetPixel(hDC, 19, 19, color);
	for (int i = 0; i < m_nNbRow; i++)
	{
		for (int j = 0; j < m_nNbCol; j++)
		{
			int x = m_pTab[i][j];
			COLORREF  color = RGB(x, x, x);
			SetPixel(hDC, j+border_x, i+border_y, color);
		}
	}

	ReleaseDC(hWND, hDC);
	cin.ignore();

}






void CImage::affiche_tab() {
	for (int i = 0; i < m_nNbRow; i++)
	{
		for (int j = 0; j < m_nNbCol; j++)
		{
			cout << int (m_pTab[i][j]);
			cout << " ";
		}
		cout << endl;
	}

}

void CImage::affiche_bin() {
	for (int i = 0; i < m_nNbRow; i++)
	{
		for (int j = 0; j < m_nNbCol; j++)
		{
			cout << m_pBin[i][j];
			cout << " ";
		}
		cout << endl;
	}

}


CImage::CImage(int Row, int Col, int type)
	:m_pTab(NULL), m_nNbRow(Row), m_nNbCol(Col), m_pBin(NULL)
{
	if (m_nNbRow > 0) {
		m_pTab = new unsigned char* [m_nNbRow];
		if (m_nNbCol > 0)
		{
			for (int i = 0; i < m_nNbRow; ++i) {
				m_pTab[i] = new unsigned char[m_nNbCol];
			}
		}
	}
	for (int i = 0; i < m_nNbRow; i++)
		for (int j = 0; j < m_nNbCol; j++)
			m_pTab[i][j] = 0;

	/*/if (type == 1) {
		int n = 2 ; int y = m_nNbRow / 2;
		for (int i = 0; i < 0.5 * m_nNbCol; i++)
		{
			int j = 0.5 * (n - 1);
			for (int x = -j; x < j; x++)
			{
				m_pTab[x+y][i] = 255;
					
			}
			n + 2;
		}
			
	}*/

	if (type == 0) {
		int mir = 7;
		int couleur[7] = { 0, 42, 84, 126, 168, 210, 255 };
		for (int x = 0; x < m_nNbRow; x++) {
			for (int n = 0; n < mir; n++) {
				for (int y = n * (m_nNbCol / mir); y < (n + 1) * (m_nNbCol / mir); y++)
				{
					m_pTab[x][y] = couleur[n];
				}
			}
		}

	}
}





;

// vecteur de test 