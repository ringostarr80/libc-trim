/* 
 * File:   main.c
 * Author: ringo
 *
 * Created on 16. Februar 2014, 21:20
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "trim.h"

/*
 * 
 */
int main(int argc, char** argv) {
	char* input = "hallo welt";
	char trim_chars[3] = {'a', 'h', 'l'};
	char* output = ltrim_chars(input, trim_chars);
	printf("output: %s\n", output);
	free(output);
	return (EXIT_SUCCESS);
}
