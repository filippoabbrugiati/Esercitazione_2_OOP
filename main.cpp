#include <iostream>
#include "complex_number.hpp"
#include <cmath>

int main()
{
	using cpx = complex_number<double>;
	
	cpx c1(1,2);
	cpx c2(0,-3);
	cpx c3(-1,6);
	cpx c4(M_PI,M_E);
	cpx c5(-7,-7.908986546564);
	double x = 5.089;
	
	std::cout << c1 <<std::endl;
	std::cout << c2 <<std::endl;
	std::cout << c3 <<std::endl;
	std::cout << c4 <<std::endl;
	std::cout << c5 << std::endl;
	std::cout << c1+c2 <<std::endl;
	std::cout << c4+x << std::endl;
	std::cout << x+c4 << std::endl;
	std ::cout << c1*x <<std::endl;
	std ::cout << x*c1 <<std::endl;
	std::cout << c4.im() << std::endl;
	std::cout << c4.conj() << std::endl;
	std::cout << (x+c4).conj() << std::endl;
	std::cout << c5.conj() + c5.re() * x << std::endl;
	return 0;
}