#pragma once

#include <iostream>
#include <fstream>
#include <windows.h>
#include <math.h>

using namespace std;


class CImage
{
private:
	unsigned char** m_pTab;
	int m_nNbRow;
	int m_nNbCol;
	unsigned int** m_pBin;
	//unsigned char** m_pDec;
public:
	CImage();
	~CImage();
	CImage(int, int);
	CImage(int, int, int);
	void save(const char *);
	unsigned int** seuil();
	CImage converter();
	CImage histogramme();
	void affiche();
	void affiche_tab();
	void affiche_bin();
};









/*

e) Ajouter � votre classe une m�thode permettant d��tablir un seuil dans le voisinage 3*3 de
chaque case avec la valeur centrale. Lorsque la valeur de case centrale est sup�rieure � la valeur
du voisin, �crivez "0". Sinon, �crivez "1". Cela donne un nombre binaire � 8 chiffres. Cette
m�thode renvoie un tableau qui stocke la chaine binaire pour chaque case
----------------------------------------------------------------
f) Ajouter � votre classe une m�thode permettant de convertir le tableau qui stocke les nombres
binaires en un tableau des nombres d�cimaux.
----------------------------------------------------------------
g) Ajouter � votre classe une m�thode nomm�e Histogramme permettant de calculer le nombre
d�occurrence de chaque nombre d�cimal dans le tableau pr�c�dent. Cette m�thode renvoie un
tableau d�une seule dimension correspondant � l'histogramme.
----------------------------------------------------------------
h) Sauvegarder le tableau renvoy� par la m�thode Histogramme sous Excel avec une m�thode
nomm�e SaveHist.

cr�er une interface grafique
*/


/*
1 page de garde
1bis remerciment
2 somaire auto
3 intro /contexte
4 cahier des charges /positionnement du travail
5 liste des taches            /  temps
6 planning previsionnel       /  mesures        / cout
raisonable : taches -> temps
temps -> liste des taches raisonables qui peuvent �tres faits 

7 planning r�alis�   (maj) 
expliquer les diff�rence majeur 

8 solution apport�s
9 vecteur de test
10 resultat
11 perspective
12 conclusion 


ppt
vid�o 30s -> 1m 30
*/