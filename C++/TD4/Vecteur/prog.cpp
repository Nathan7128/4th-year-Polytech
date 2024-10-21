#include "vecteur.hpp"

int main()
{
	Vecteur v1(3), v2(3), v3(3);
	float res;

	cin >> v1 >> v2;

	cout << "v1 et v2" << endl;
	cout << v1 << endl << endl << v2 << endl << endl;

	v3 = v1;
	cout << "v3 = v1" << endl;
	cout << v3 << endl << endl;

	v3 = v1 + v2;
	cout << "v1 + v2" << endl;
	cout << v3 << endl << endl;

	v3 = v1 - v2;
	cout << "v1 - v2" << endl;
	cout << v3 << endl << endl;

	res = v1 * v2;
	cout << "v1 * v2" << endl;
	cout << res << endl << endl;

	cout << "v1 == v2" << endl;
	cout << (v1 == v2) << endl << endl;

	cout << "v1 != v2" << endl;
	cout << (v1 != v2) << endl << endl;

	v3 = v1;
	cout << "v3 = v1" << endl;
	cout << (v1 == v3) << endl << endl;

	v3[2] = 15;
	cout << "v3[2] = 15" << endl;
	cout << (v3) << endl << endl;

	return 0;
}