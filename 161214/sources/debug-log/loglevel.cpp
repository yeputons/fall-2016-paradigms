/**
 * При компиляции с ключом -DLOG=xxx включается логирование уровня xxx.
 * Например: `g++ loglevel.cpp -DLOG=1 -o loglevel`
 * При компиляции без ключа оно выключается.
 *
 * Так можно писать на контестах. В проектах стоит использовать
 * специальные библиотеки.
 */
#include<cstdio> 

#ifdef LOG
#define eprintf(lev, ...) if (lev <= LOG) { fprintf(stderr, __VA_ARGS__); }
#else
#define eprintf(...)
#endif

int main() {
    printf("Normal output\n");
	eprintf(1, "Debug output level 1\n");
	for (int i = 0; i < 2; i++) {
	    eprintf(2, "Debug output of level 2 in first loop (%d)\n", i);
	}
	#if LOG >= 3
	for (int i = 0; i < 2; i++) {
	    eprintf(3, "Debug output of level 3 in second loop (%d)\n", i);
	}
	#endif
    return 0;
}
