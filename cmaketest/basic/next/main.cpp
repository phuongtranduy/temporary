#include <iostream>

int main(int argc, char** argv){
	std::cout << "Hello World" << std::endl;

	std::cout << "DEFINITION_PHUONG=" << DEFINITION_PHUONG << std::endl;
	
	return 0;
}
//g++ -DDEFINITION_PHUONG=\"SomeValue\" -o main main.cpp
/*
huongtran@phuongtranvbox:~/learningstudying/cmaketest/next/build<>$cat CMakeFiles/hello_world.dir/build.make  | grep -r DEFINITION_PHUONG
compile_commands.json:  "command": "/usr/bin/c++ -DDEFINITION_PHUONG=\\\"SomeValue\\\"   -o CMakeFiles/hello_world.dir/main.cpp.o -c /home/phuongtran/learningstudying/cmaketest/next/main.cpp",
grep: hello_world: binary file matches
CMakeFiles/hello_world.dir/flags.make:CXX_DEFINES = -DDEFINITION_PHUONG=\"SomeValue\"
grep: CMakeFiles/hello_world.dir/main.cpp.o: binary file matches


huongtran@phuongtranvbox:~/learningstudying/cmaketest/next/build<>$cat CMakeFiles/hello_world.dir/build.make  | grep -r DEFINITION_PHUONG
compile_commands.json:  "command": "/usr/bin/c++ -DDEFINITION_PHUONG=\"\\\"Some Value with space\\\"\"   -o CMakeFiles/hello_world.dir/main.cpp.o -c /home/phuongtran/learningstudying/cmaketest/next/main.cpp",
grep: hello_world: binary file matches
CMakeFiles/hello_world.dir/flags.make:CXX_DEFINES = -DDEFINITION_PHUONG="\"Some Value with space\""
grep: CMakeFiles/hello_world.dir/main.cpp.o: binary file matches
*/
