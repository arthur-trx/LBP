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

e) Ajouter à votre classe une méthode permettant d’établir un seuil dans le voisinage 3*3 de
chaque case avec la valeur centrale. Lorsque la valeur de case centrale est supérieure à la valeur
du voisin, écrivez "0". Sinon, écrivez "1". Cela donne un nombre binaire à 8 chiffres. Cette
méthode renvoie un tableau qui stocke la chaine binaire pour chaque case
----------------------------------------------------------------
f) Ajouter à votre classe une méthode permettant de convertir le tableau qui stocke les nombres
binaires en un tableau des nombres décimaux.
----------------------------------------------------------------
g) Ajouter à votre classe une méthode nommée Histogramme permettant de calculer le nombre
d’occurrence de chaque nombre décimal dans le tableau précèdent. Cette méthode renvoie un
tableau d’une seule dimension correspondant à l'histogramme.
----------------------------------------------------------------
h) Sauvegarder le tableau renvoyé par la méthode Histogramme sous Excel avec une méthode
nommée SaveHist.

créer une interface grafique
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
temps -> liste des taches raisonables qui peuvent étres faits 

7 planning réalisé   (maj) 
expliquer les différence majeur 

8 solution apportés
9 vecteur de test
10 resultat
11 perspective
12 conclusion 


ppt
vidéo 30s -> 1m 30
*/