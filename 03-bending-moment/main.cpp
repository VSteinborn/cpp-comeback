#include <iostream>
#include <cmath>

double calcOmega1(double length1, double x){
	return (x/length1) - pow(x/length1,2);
}

double calcOmega2(double length1, double length2, double x){
	return (x-length1)/length2 - pow((x-length1)/length2, 2);
}

double calcMb(double q1, double q2, double length1, double length2, double j){
	return ((q1*pow(length1,3)+q2*pow(length2,3)*j)/(8*(length1+length2*j)));
}

double calcj(double momentOfInertiay1, double momentOfInertiay2){
	return momentOfInertiay1/momentOfInertiay2;
}

double calcLength1My(double Mb, double length1, double q1, double omega1, double x){
	return Mb*(x/length1)-(q1*pow(length1,2)/2)*omega1;
}

double calcLength2My(double Mb, double length1, double length2, double q2, double omega2, double x){
	return Mb*(1-((x-length1)/length2))-(q2*pow(length2,2)/2)*omega2;
}

int main()
{

	double length1, length2, momentOfInertiay1, momentOfInertiay2, q1, q2, x;
	int i_limit;
	std::cout << "length 1 [m]:" << std::endl;
	std::cin >> length1;
	std::cout << "length 2 [m]:" << std::endl;
	std::cin >> length2;
	std::cout << "moment of inertia Iy1 [m^4]:" << std::endl;
	std::cin >> momentOfInertiay1;
	std::cout << "moment of inertia Iy2 [m^4]:" << std::endl;
	std::cin >> momentOfInertiay2;
	std::cout << "load q1 [kN/m]:" << std::endl;
	std::cin >> q1;
	std::cout << "load q2 [kN/m]:" << std::endl;
	std::cin >> q2;
	std::cout << "number of samples [-]:" << std::endl;
	std::cin >> i_limit;

	std::cout << "Result:" << std::endl;
	double j = calcj(momentOfInertiay1, momentOfInertiay2);
	double Mb = calcMb(q1, q2, length1, length2, j);
	for(int i=0; i<(1+i_limit); i++){
		double x = (length1+length2)*i/i_limit;

		if (x<=(length1)){
			double omega1 = calcOmega1(length1, x);
			double My = calcLength1My(Mb, length1, q1, omega1, x);
			std::cout << "x = " << i << ": M(x) [kNm] = " << My << std::endl;
		}
		else{
			double omega2 = calcOmega2(length1, length2, x);
			double My = calcLength2My(Mb, length1, length2, q2, omega2, x);
			std::cout << "x = " << i << ": M(x) [kNm] = " << My << std::endl;
		}


	}
}