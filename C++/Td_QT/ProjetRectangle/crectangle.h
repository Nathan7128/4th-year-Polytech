#ifndef CRECTANGLE_H
#define CRECTANGLE_H



#include <QPainter>



class CRectangle
{
private:
    int x;
    int y;
    int largeur;
    int hauteur;
public:
    CRectangle();
    CRectangle(int x, int y, int l, int h);
    void deplacer(int dx, int dy);
    void deplacerDe(int dx, int dy);
    void dessiner(QPainter * p);
};



#endif // CRECTANGLE_H
