#include "crectangle.h"

CRectangle::CRectangle() {
    x=0;
    y=0;
    largeur=0;
    hauteur=0;
}

CRectangle::CRectangle(int x, int y, int l, int h) {
    this->x=x;
    this->y=y;
    this->largeur=l;
    this->hauteur=h;
}

void CRectangle::deplacer(int dx, int dy) {
    x=dx;
    y=dy;
}

void CRectangle::deplacerDe(int dx, int dy) {
    x+=dx;
    y+=dy;
}

void CRectangle::dessiner(QPainter * p) {
    p->setPen( QPen(Qt::black, 1) );
    p->drawRect( x, y, largeur, hauteur );
    p->fillRect( x+1, y+1, largeur-1, hauteur-1, QBrush(Qt::green) );
}
