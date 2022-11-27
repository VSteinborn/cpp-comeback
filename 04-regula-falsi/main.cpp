#include <iostream>
#include <cmath>

double testFunction(double x){
	return (x+1)*(x-1);
}

double findLinearIntersection(double a, double b, double (*func)(double)){
	return a - ((func(a)*(b-a))/(func(b)-func(a)));
}

void updateInterval(double a, double b, double u, double* new_a, double* new_b, double (*func)(double)){
	if (func(a)*func(u) < 0){
		*new_b=u;
		*new_a=a;
	}
	else{
		*new_a=u;
		*new_b=b;
	}
}

int main(){
	double a, b, eps;
	int max_iter;
	std::cout << "Specify the interval [a,b] where to look for zeros in the function f=(x+1)(x-1):" << std::endl;
	std::cout << "a:" << std::endl;
	std::cin >> a;
	std::cout << "b:" << std::endl;
	std::cin >> b;
	std::cout << "The range is [" << a << "," << b <<"]" <<std::endl;
	std::cout << "Error tolerance epsilon:" << std::endl;
	std::cin >> eps;
	std::cout << "Maximum number of iterations:" << std::endl;
	std::cin >> max_iter;

	bool done_check = false;
	for(int i=0; i<(1+max_iter); i++){
		double u = findLinearIntersection(a, b, &testFunction);
		if (abs(testFunction(u)-0)<eps){
			std::cout << "Zero at: x=" << u << std::endl;
			std::cout << "Zero at: f(x)= " << testFunction(u) << std::endl;
			done_check = true;
			break;
		}
		updateInterval(a,b,u,&a,&b,&testFunction);
	}
	if (done_check==false){
	std::cout << "Reached Maximum number of iterations" << std::endl;
	}
}