
#include <iostream>
#include "Vecteur3D.h"
#include "Vecteur3DT.h"
#include "MatriceT.h"

int main()
{

	std::cout << "***********Ensemble d'instructions A****************" << std::endl;
	int tab1[3] = { 1, 4, 5 };
	Vecteur3D v1(tab1);
	Vecteur3D v2(7, 4, 1);
	Vecteur3D v3(v2);
	std::cout << "v1: (" << v1.x() << "," << v1.y() << "," << v1.z() << ")" << std::endl;
	std::cout << "v2: " << v2 << std::endl;
	std::cout << "v3: " << v3 << std::endl;
	std::cout << "v2 egal v3: " << (v2 == v3) << std::endl;
	v2.x() = 8;
	v2.y() = 7;
	v2.z() = 4;
	std::cout << "v2 different v3: " << (v2 != v3) << std::endl;
	std::cout << "v2: " << v2 << std::endl;
	v1 = v2 + v3;
	std::cout << "v1: " << v1 << std::endl;
	v1 = v2 - v3;
	std::cout << "v1: " << v1 << std::endl;
	v1 = v2 * 7;
	std::cout << "v1: " << v1 << std::endl;
	v1 = v2 * v3;
	std::cout << "v1: " << v1 << std::endl;

	std::cout << "***********Ensemble d'instructions B****************" << std::endl;
	int tab2[3] = { 1, -4, 5 };
	Vecteur3DT<int> vt1(tab2);
	Vecteur3DT<int> vt2(-7, 4, -1);
	Vecteur3DT<int> vt3(vt2);
	std::cout << "vt1: (" << vt1.x() << "," << vt1.y() << "," << vt1.z() << ")" << std::endl;
	std::cout << "vt2: " << vt2 << std::endl;
	std::cout << "vt3: " << vt3 << std::endl;
	std::cout << "vt2 egal vt3: " << (vt2 == vt3) << std::endl;
	vt2.x() = -8;
	vt2.y() = 7;
	vt2.z() = -4;
	std::cout << "vt2 different vt3: " << (vt2 != vt3) << std::endl;
	std::cout << "vt2: " << vt2 << std::endl;
	vt1 = vt2 + vt3;
	std::cout << "vt1: " << vt1 << std::endl;
	vt1 = vt2 - vt3;
	std::cout << "vt1: " << vt1 << std::endl;
	vt1 = vt2 * 7;
	std::cout << "vt1: " << vt1 << std::endl;
	vt1 = vt2 * vt3;
	std::cout << "vt1: " << vt1 << std::endl;


	std::cout << "***********Ensemble d'instructions C****************" << std::endl;
	float tab3[3] = { -1.44f, 4.28f, -5.67f };
	Vecteur3DT<float> vt4(tab3);
	Vecteur3DT<float> vt5(7.34f, -4.97f, 1.125f);
	Vecteur3DT<float> vt6(vt5);
	std::cout << "vt4: (" << vt4.x() << "," << vt4.y() << "," << vt4.z() << ")" << std::endl;
	std::cout << "vt5: " << vt5 << std::endl;
	std::cout << "vt6: " << vt6 << std::endl;
	std::cout << "vt5 egal vt6: " << (vt5 == vt6) << std::endl;
	vt5.x() = 8.63f;
	vt5.y() = -7.41f;
	vt5.z() = -4.78f;
	std::cout << "vt5 different vt6: " << (vt5 != vt6) << std::endl;
	std::cout << "vt5: " << vt5 << std::endl;
	vt4 = vt5 + vt6;
	std::cout << "vt4: " << vt4 << std::endl;
	vt4 = vt5 - vt6;
	std::cout << "vt4: " << vt4 << std::endl;
	vt4 = vt5 * 7;
	std::cout << "vt4: " << vt4 << std::endl;
	vt4 = vt5 * vt6;
	std::cout << "vt4: " << vt4 << std::endl;

	std::cout << "***********Ensemble d'instructions D****************" << std::endl;
	int tab4[20] = { 1, 4, 7, 8, 5, 2, 9, 6, 3, 1, 4, 7, 8, 5, 2, 9, 6, 3, 1, 4 };
	MatriceT<int> mt1(4, 5, tab4);
	int tab5[15] = { 5, 7, 9, 6, 4, 1, 8, 7, 6, 4, 7, 8, 4, 5, 6 };
	MatriceT<int> mt2(5, 3, tab5);
	MatriceT<int> mt3(mt2);
	std::cout << "mt1 partielle :" << mt1[0][0] << " " << mt1[0][1] << " " << mt1[0][2] << std::endl;
	std::cout << "mt2 :" << mt2 << std::endl;
	std::cout << "mt3 :" << mt3 << std::endl;
	std::cout << "mt2 egal mt3 :" << (mt2 == mt3) << std::endl;
	mt2[4][2] = 7;
	std::cout << "mt2 different mt3 :" << (mt2 != mt3) << std::endl;
	std::cout << "mt2 :" << mt2 << std::endl;
	MatriceT<int> mt4;
	mt4 = mt2 + mt3;
	std::cout << "mt4 :" << mt4 << std::endl;
	mt4 = mt2 - mt3;
	std::cout << "mt4 :" << mt4 << std::endl;
	mt4 = mt2 * 2;
	std::cout << "mt4 :" << mt4 << std::endl;
	mt4 = mt1 * mt2;
	std::cout << "mt4 :" << mt4 << std::endl;

	std::cout << "***********Ensemble d'instructions E****************" << std::endl;
	double tab6[20] = { 1.4, -4.6, -7.7, -8.85, 5.41, -2.87, 9.82, 6.14, 3.47, -1.13, 4.45, 7.78, 8.12, -5.14, 2.45, 9.58, 6.45, 3.19, 1.43, -4.7 };
	MatriceT<double> mt5(4, 5, tab6);
	double tab7[15] = { 5.45, 7.47, -9.73, -6.8, -4.4, -1.62, 8.14, -7.96, -6.85, -4.91, 7.8, 8.41, -4.14, -5.7, -6.4 };
	MatriceT<double> mt6(5, 3, tab7);
	MatriceT<double> mt7(mt6);
	std::cout << "mt5 partielle :" << mt5[0][0] << " " << mt5[0][1] << " " << mt5[0][2] << std::endl;
	std::cout << "mt6 :" << mt6 << std::endl;
	std::cout << "mt7 :" << mt7 << std::endl;
	std::cout << "mt6 egal mt7 :" << (mt6 == mt7) << std::endl;
	mt6[4][2] = -7.4;
	std::cout << "mt6 different mt7:" << (mt6 != mt7) << std::endl;
	std::cout << "mt6 :" << mt6 << std::endl;
	MatriceT<double> mt8;
	mt8 = mt6 + mt7;
	std::cout << "mt8 :" << mt8 << std::endl;
	mt8 = mt6 - mt7;
	std::cout << "mt8 :" << mt8 << std::endl;
	mt8 = mt6 * 2;
	std::cout << "mt8 :" << mt8 << std::endl;
	mt8 = mt5* mt6;
	std::cout << "mt8 :" << mt8 << std::endl;

	std::cout << "***********Ensemble d'instructions F****************" << std::endl;
	Vecteur3DT<float> tab8[6] = { Vecteur3DT<float>(1.2f, -2.4f, 3.84f), Vecteur3DT<float>(4.84f, -8.75f, -3.85f), Vecteur3DT<float>(-1.89f, 2.75f, -3.78f),
	Vecteur3DT<float>(9.55f, 2.47f, 3.1f), Vecteur3DT<float>(-7.85f, -2.75f, -3.74f), Vecteur3DT<float>(7.91f, 2.12f, -6.12f)};
	MatriceT<Vecteur3DT<float>> mt9(2, 3, tab8);
	Vecteur3DT<float> tab9[6] = { Vecteur3DT<float>(-8.45f, 4.74f, 12.8f), Vecteur3DT<float>(-6.74f, 14.85f, 7.12f), Vecteur3DT<float>(-12.99f, -2.82f, -3.16f),
	Vecteur3DT<float>(1.67f, 7.77f, 9.85f), Vecteur3DT<float>(8.79f, -7.96f, -8.23f), Vecteur3DT<float>(-7.91f, 4.78f, 7.49f) };

	MatriceT<Vecteur3DT<float>> mt10(3, 2, tab9);
	MatriceT<Vecteur3DT<float>> mt11(mt10);

	std::cout << "mt9 partielle :" << mt9[0][0] << " " << mt9[0][1] << " " << mt9[0][2] << std::endl;
	std::cout << "mt10 :" << mt10 << std::endl;
	std::cout << "mt11 :" << mt11 << std::endl;

	std::cout << "mt10 egal mt11 :" << (mt10 == mt11) << std::endl;
	mt10[2][1] = Vecteur3DT<float>(-8.91f, 5.78f, 8.49f);
	std::cout << "mt10 different mt11:" << (mt10 != mt11) << std::endl;
	std::cout << "mt10 :" << mt10 << std::endl;
	MatriceT<Vecteur3DT<float>> mt12;
	mt12 = mt10 + mt11;
	std::cout << "mt12 :" << mt12 << std::endl;
	mt12 = mt10 - mt11;
	std::cout << "mt12 :" << mt12 << std::endl;
	mt12 = mt10 * Vecteur3DT<float>(2.0f, 4.5f, 6.7f);;
	std::cout << "mt12 :" << mt12 << std::endl;
	mt12 = mt9* mt10;
	std::cout << "mt12 :" << mt12 << std::endl;

	return 0;
}