#include "Fraction.h"

int main() {
    Fraction f1(2, 3);
    Fraction f2(3, 4);

    f1.afficherFraction();
    f2.afficherFraction();

    f1.addition(f2);
    f1.afficherFraction();

    f2.multiplication(f1);
    f2.afficherFraction();

    return 0;
}