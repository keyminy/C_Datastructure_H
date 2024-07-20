#pragma once
#include <stdio.h>
void bufferClear();
void bufferClear() {
	while (getchar() != '\n');
}