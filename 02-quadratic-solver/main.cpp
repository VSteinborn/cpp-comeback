#include <iostream>
#include <cmath>

double calcDiscriminant(double a, double b, double c)
{
	double numerator = b*b-4*a*c;
	double denominator = 4*a*a;
	return numerator/denominator;
}

int main(){
	double a, b, c;
	std::cout << "Enter a:\n";
	std::cin >> a; 
	std::cout << "Enter b:\n";
	std::cin >> b; 
	std::cout << "Enter c:\n";
	std::cin >> c; 

	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
			{
				std::cout << "All values of x are solutions\n";
			}
			else
			{
				std::cout << "No values of x are solutions\n";
			}

		}
		else
		{
			double solution = -c/b;
			std::cout << "Real solution: " << solution << std::endl;
		}

	}
	else
	{
		double discriminant = calcDiscriminant(a, b, c);

		if (discriminant < 0)
		{
			double realSolution = -b/(2*a);
			double imaginarySolution = sqrt(-discriminant);
			std::cout << "Two complex solutions: " << realSolution << " +/- i " << imaginarySolution << std::endl;

		}
		else if (discriminant > 0) {

			double solutionPart1 = -b/(2*a);
			double solutionPart2 = sqrt(discriminant);
			std::cout << "Two real solutions: " << solutionPart1 << " +/- " << solutionPart2 << std::endl;

		}
		else {
			double solution = -b/(2*a);
			std::cout << "Real solution: " << solution << std::endl;
		}
	}


}