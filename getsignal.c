#include "main.h"

/**
 * catch_sig - get the signal
 * @signalid: integer argument to indentify signal
 * Return: void
 */
void catch_sig(int sign_id)
{
	if (sign_id == SIGINT)
		_puts("\n#cisfun$ ");
}
