
#include "includes/Fixed.hpp"

#define SECTION(title) std::cout << "\n\033[1;36m===== " << title << " =====\033[0m\n" << std::endl

int main(void)
{
    SECTION("CONSTRUCTEURS & FORME CANONIQUE");
    {
        std::cout << "--- Constructeur par défaut ---" << std::endl;
        Fixed a;
        std::cout << "a = " << a << " (attendu : 0)" << std::endl;

        std::cout << "\n--- Constructeur depuis int ---" << std::endl;
        Fixed b(42);
        std::cout << "b = " << b << " (attendu : 42)" << std::endl;

        std::cout << "\n--- Constructeur depuis float ---" << std::endl;
        Fixed c(3.14f);
        std::cout << "c = " << c << " (attendu : ~3.14)" << std::endl;

        std::cout << "\n--- Constructeur de copie ---" << std::endl;
        Fixed d(c);
        std::cout << "d = " << d << " (attendu : ~3.14)" << std::endl;

        std::cout << "\n--- Opérateur d'assignation ---" << std::endl;
        Fixed e;
        e = b;
        std::cout << "e = " << e << " (attendu : 42)" << std::endl;

        std::cout << "\n--- Destructeurs (à la sortie du scope) ---" << std::endl;
    }

    SECTION("CONVERSIONS toFloat() ET toInt()");
    {
        Fixed a(42.42f);
        std::cout << "a = " << a << std::endl;
        std::cout << "a.toFloat() = " << a.toFloat() << " (attendu : ~42.42)" << std::endl;
        std::cout << "a.toInt()   = " << a.toInt()   << " (attendu : 42)" << std::endl;

        Fixed b(-7.5f);
        std::cout << "\nb = " << b << std::endl;
        std::cout << "b.toFloat() = " << b.toFloat() << " (attendu : -7.5)" << std::endl;
        std::cout << "b.toInt()   = " << b.toInt()   << " (attendu : -8 ou -7 selon implémentation)" << std::endl;
    }

    SECTION("OPERATEURS DE COMPARAISON");
    {
        Fixed a(10);
        Fixed b(20);
        Fixed c(10);

        std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
        std::cout << "a <  b : " << (a < b)  << " (attendu : 1)" << std::endl;
        std::cout << "a >  b : " << (a > b)  << " (attendu : 0)" << std::endl;
        std::cout << "a <= c : " << (a <= c) << " (attendu : 1)" << std::endl;
        std::cout << "a >= c : " << (a >= c) << " (attendu : 1)" << std::endl;
        std::cout << "a == c : " << (a == c) << " (attendu : 1)" << std::endl;
        std::cout << "a != b : " << (a != b) << " (attendu : 1)" << std::endl;
        std::cout << "a == b : " << (a == b) << " (attendu : 0)" << std::endl;
    }

    SECTION("OPERATEURS ARITHMETIQUES");
    {
        Fixed a(10);
        Fixed b(3);

        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "a + b = " << (a + b) << " (attendu : 13)" << std::endl;
        std::cout << "a - b = " << (a - b) << " (attendu : 7)"  << std::endl;
        std::cout << "a * b = " << (a * b) << " (attendu : 30)" << std::endl;
        std::cout << "a / b = " << (a / b) << " (attendu : ~3.33)" << std::endl;

        std::cout << "\n--- Avec des floats ---" << std::endl;
        Fixed x(5.5f);
        Fixed y(2.0f);
        std::cout << "x = " << x << ", y = " << y << std::endl;
        std::cout << "x * y = " << (x * y) << " (attendu : 11)" << std::endl;
        std::cout << "x / y = " << (x / y) << " (attendu : 2.75)" << std::endl;
    }

    SECTION("INCREMENT / DECREMENT");
    {
        Fixed a;
        std::cout << "a = " << a << " (initial)" << std::endl;
        std::cout << "++a = " << ++a << " (pré-incrément, attendu : 0.00390625)" << std::endl;
        std::cout << "a   = " << a   << std::endl;
        std::cout << "a++ = " << a++ << " (post-incrément, retourne ancien : 0.00390625)" << std::endl;
        std::cout << "a   = " << a   << " (incrémenté : 0.0078125)" << std::endl;

        std::cout << "\n--- Décrément ---" << std::endl;
        std::cout << "--a = " << --a << " (pré-décrément, attendu : 0.00390625)" << std::endl;
        std::cout << "a   = " << a   << std::endl;
        std::cout << "a-- = " << a-- << " (post-décrément, retourne ancien)" << std::endl;
        std::cout << "a   = " << a   << " (décrémenté : 0)" << std::endl;
    }

    SECTION("MIN / MAX (versions non-const)");
    {
        Fixed a(10);
        Fixed b(20);

        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "Fixed::min(a, b) = " << Fixed::min(a, b) << " (attendu : 10)" << std::endl;
        std::cout << "Fixed::max(a, b) = " << Fixed::max(a, b) << " (attendu : 20)" << std::endl;
    }

    SECTION("MIN / MAX (versions const)");
    {
        Fixed const a(42);
        Fixed const b(7);

        std::cout << "a = " << a << ", b = " << b << " (tous deux const)" << std::endl;
        std::cout << "Fixed::min(a, b) = " << Fixed::min(a, b) << " (attendu : 7)"  << std::endl;
        std::cout << "Fixed::max(a, b) = " << Fixed::max(a, b) << " (attendu : 42)" << std::endl;
    }

    SECTION("TEST DU SUJET (officiel)");
    {
        Fixed a;
        Fixed const b(Fixed(5.05f) * Fixed(2));

        std::cout << "a       = " << a << std::endl;
        std::cout << "++a     = " << ++a << std::endl;
        std::cout << "a       = " << a << std::endl;
        std::cout << "a++     = " << a++ << std::endl;
        std::cout << "a       = " << a << std::endl;
        std::cout << "b       = " << b << std::endl;
        std::cout << "max(a,b)= " << Fixed::max(a, b) << std::endl;

        std::cout << "\n(Sortie attendue par le sujet :" << std::endl;
        std::cout << "0\n0.00390625\n0.00390625\n0.00390625\n0.0078125\n10.1016\n10.1016)" << std::endl;
    }

    SECTION("FIN DES TESTS");

    return 0;
}