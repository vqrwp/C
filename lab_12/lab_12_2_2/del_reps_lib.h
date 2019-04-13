#ifndef __DEL__REPS__LIB__H__
#define __DEL__REPS__LIB__H__

#include <stdio.h>

#ifdef EXPORTS
#define FUNC_DLL __declspec(dllexport)
#else
#define FUNC_DLL __declspec(dllimport)
#endif

#define FUNC_DECL __cdecl

FUNC_DLL int FUNC_DECL del_reps(const int *arr, int n, int *new_arr);

#endif
