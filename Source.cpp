#include <iostream>
#include "CImage.h"

int main()
{
CImage im_1;
CImage im_2 (250,250);
CImage im_3(250, 500, 0);
//cout << "construit";
im_3.affiche();
//cout << "afficher ";
im_3.seuil(); //retunr CImage
cout << "bin ";
im_3.affiche_bin();
cout << "affiche bin";
im_3.converter().affiche_tab();
cout << "affiche int ";
im_3.converter().histogramme().affiche_tab();
cout << "ok";




	return 0;
}