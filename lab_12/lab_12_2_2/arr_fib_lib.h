#ifndef __ARR__FIBB__LIB__H__
#define __ARR__FIBB__LIB__H__

#include <stdio.h>

#ifdef EXPORTS
#define FUNC_DLL __declspec(dllexport)
#else
#define FUNC_DLL __declspec(dllimport)
#endif

#define FUNC_DECL __cdecl

FUNC_DLL int* FUNC_DECL fib_arr(int *arr, int n);

#endif
