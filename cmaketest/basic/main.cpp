#include <iostream>

int main(int argc, char** argv){
	std::cout << "Hello World" << std::endl;
	#if defined(DEFINITION_PHUONG)
	std::cout << "DEFINITION_PHUONG=" << DEFINITION_PHUONG << std::endl;
	#endif
	return 0;
}
//g++ -DDEFINITION_PHUONG"hello" -o main main.cpp
