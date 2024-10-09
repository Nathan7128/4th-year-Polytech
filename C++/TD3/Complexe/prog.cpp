#include "complexe.hpp"

int main()
{
    Complexe c(5.3, 0.8);
    cout << c.module() << endl;
    c.conjugue();
    cout << c.module() << endl;
}