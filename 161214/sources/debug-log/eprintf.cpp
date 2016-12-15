/**
 * При компиляции с ключом -DDEBUG включается логирование.
 * Например: `g++ eprintf.cpp -DDEBUG -o eprintf`
 * При компиляции без ключа оно выключается.
 *
 * Так можно писать на контестах. В проектах стоит использовать
 * специальные библиотеки.
 */
#include<cstdio> 

/**
 * В качестве альтернативы можно раскомментировать эту строчку.
 * Ключ -DDEBUG - это то же самое, что написать #define DEBUG весь
 * в самом начале файла.
 */
// #define DEBUG
 
#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif

int main() {
    printf("Normal output\n");
	eprintf("Debug output\n");
	for (int i = 0; i < 2; i++) {
	    eprintf("Debug output in first loop (%d)\n", i);
	}
	#ifdef DEBUG
	// Так как при отсутствии флага вырезается только eprintf,
	// но не весь цикл вокруг него (хотя оптимизатор может догадаться,
	// если только внутри цикла не вызываются сложные функции),
	// то я обычно заключаю цикл в #ifdef DEBUG. Всё между
	// #ifdef DEBUG и #endif вырезается при отсутствии флага -DDEBUG
	for (int i = 0; i < 2; i++) {
	    eprintf("Debug output in second loop (%d)\n", i);
	}
	#endif

	#ifdef DEBUG
	// Также можно некоторые сложные инварианты проверять
	// только локально, но не на сервере при проверке.
	// Например, проверку ответа на запрос в дереве отрезков
	// можно написать "в лоб". Такие assert'ы и вычисления
	// удобно помещать внутрь #ifdef DEBUG..#endif
	assert(2 * 2 == 2 + 2);
	#endif
    return 0;
}
