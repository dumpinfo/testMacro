#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define Debug(...) printf(__VA_ARGS__)

#define PP_NARG(...) PP_NARG_(__VA_ARGS__, PP_RSEQ_N())
#define PP_NARG_(...) PP_ARG_N(__VA_ARGS__)
#define PP_ARG_N( \
        _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
        _11,_12,_13,_14,_15,_16, N, ...) N
#define PP_RSEQ_N() \
        16,15,14,13,12,11,10, \
        9,8,7,6,5,4,3,2,1,0


int main()
{   
	cout << (PP_NARG(1, 2, 3, 4, 1, 1)) << endl;
    cout << __LINE__ <<"\n";
    cout <<__FILE__  <<"\n";
    cout <<__DATE__ <<"\n";
    cout <<__TIME__  <<"\n";
    cout <<__TIMESTAMP__  <<"\n";
    cout <<__STDC__  <<"\n";
    cout <<__cplusplus  <<"\n";
	return 1;
}

