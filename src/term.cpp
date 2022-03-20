#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <termios.h>

#include "term.hpp"

struct termios saved_attributes;

void set_input_mode()
{
	struct termios tattr;
	/* проверяем, что вводим с терминала */
	if (!isatty(0)) {
	fprintf(stderr, "Not a terminal.\n");
	exit(1);
	}
	/* считываем текущий режим работы терминала */
	tcgetattr(0, &saved_attributes);
	memcpy(&tattr, &saved_attributes, sizeof(tattr));
	/* включаем неканонический режим без эха */
	tattr.c_lflag &= ~(ICANON|ECHO);
	/* считываем минимум по одному символу */
	tattr.c_cc[VMIN] = 1;
	/* без ограничения времени ожидания */
	tattr.c_cc[VTIME] = 0;
	/* устанавливаем новый режим работы терминала */
	tcsetattr(0, TCSAFLUSH, &tattr);
}

void reset_input_mode()
{
	tcsetattr(0, TCSANOW, &saved_attributes);
}
