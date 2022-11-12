#include <iostream>

double volOfShape(double a1, double a2, double a3, double a4)
{
	return  a1 * a2 * (a3 + a4 / 3);
}

int main()
{
	double a1, a2, a3, a4;
	std::cout << "Enter a1:" << std::endl;
	std::cin >> a1;
	std::cout << "Enter a2:" << std::endl;
	std::cin >> a2;
	std::cout << "Enter a3:" << std::endl;
	std::cin >> a3;
	std::cout << "Enter a4:" << std::endl;
	std::cin >> a4;

	double volume = volOfShape(a1, a2, a3, a4);
	std::cout << "Volume: " << volume << std::endl;

}