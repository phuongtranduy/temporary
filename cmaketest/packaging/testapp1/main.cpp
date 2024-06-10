#include "basicmath.hpp"
int main()
{
    GetVersion();
    int sum = add(3,5);
    std::cout << "sum of 3 and 5 =" << sum << std::endl;

    return 0;
}
/**
 * 
 phuongtran@phuongtranvbox:~/learningstudying/cmaketest/packaging/testapp1/build<>$cmake ..
-- Configuring done
-- Generating done
-- Build files have been written to: /home/phuongtran/learningstudying/cmaketest/packaging/testapp1/build
phuongtran@phuongtranvbox:~/learningstudying/cmaketest/packaging/testapp1/build<>$make
Consolidate compiler generated dependencies of target testapp1
[100%] Built target testapp1
phuongtran@phuongtranvbox:~/learningstudying/cmaketest/packaging/testapp1/build<>$./testapp1 
LIB VERSION:1.0.0.3
sum of 3 and 5 =8
phuongtran@phuongtranvbox:~/learningstudying/cmaketest/packaging/testapp1/build<>$
 */