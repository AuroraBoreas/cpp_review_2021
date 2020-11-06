#include <iostream>
#include "safe.h"
using namespace std;

int main()
{
    Castle treasure;
    //treasure.topSecret = 1; // base cls, private
    //treasure.secret = 2; // base cls, protected
    //treasure.setTopSecret(5); // base cls, protected
    treasure.noSecret = 10; // base cls, public

    return 0;
}
