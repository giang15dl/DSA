#include "point.hpp"
int main(){
    Point a;
    Point b(1,2);

    Point c = b;
    Point d = b++;
    Point e = ++c;

    ++b;
    --b;

    return 0;
}