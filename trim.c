#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "trim.h"

char* ltrim(char* src) {
	char* trimmed;
	int i = 0, string_length = strlen(src), first_non_space_character_index = 0;
	int non_space_found = 0;
	
	for(i = 0; i < string_length; i++) {
		first_non_space_character_index = i;
		if (!isspace(src[i])) {
			non_space_found = 1;
			break;
		}
	}
	if (!non_space_found) {
		first_non_space_character_index++;
	}
	
	int trimmed_length = string_length - first_non_space_character_index;
	trimmed = malloc(trimmed_length + 1);
	if (trimmed == NULL) {
		return src;
	}
	strncpy(trimmed, src + first_non_space_character_index, trimmed_length);
	trimmed[trimmed_length] = '\0';
	
	return trimmed;
}

char* rtrim(char* src) {
	char* trimmed;
	int i = 0, string_length = strlen(src), last_non_space_character_index = 0;
	int non_space_found = 0;
	
	for(i = string_length - 1; i >= 0; i--) {
		last_non_space_character_index = i;
		if (!isspace(src[i])) {
			non_space_found = 1;
			break;
		}
	}
	if (!non_space_found) {
		last_non_space_character_index = -1;
	}
	
	int trimmed_length = last_non_space_character_index + 1;
	trimmed = malloc(trimmed_length + 1);
	if (trimmed == NULL) {
		return src;
	}
	strncpy(trimmed, src, trimmed_length);
	trimmed[trimmed_length] = '\0';
	
	return trimmed;
}

char* trim(char* src) {
	char* ltrimmed = ltrim(src);
	char* trimmed = rtrim(ltrimmed);
	free(ltrimmed);
	return trimmed;
}

void ltrim_ref(char src[]) {
	int i = 0, string_length = strlen(src), first_non_space_character_index = 0;
	int non_space_found = 0;
	
	for(i = 0; i < string_length; i++) {
		first_non_space_character_index = i;
		if (!isspace(src[i])) {
			non_space_found = 1;
			break;
		}
	}
	
	if (first_non_space_character_index == 0) {
		return;
	}
	
	if (!non_space_found) {
		first_non_space_character_index++;
	}
	
	int trimmed_length = string_length - first_non_space_character_index;
	for(i = first_non_space_character_index; i < string_length; i++) {
		src[i - first_non_space_character_index] = src[i];
	}
	src[trimmed_length] = '\0';
}

void rtrim_ref(char src[]) {
	int i = 0, string_length = strlen(src);
	int non_space_found = 0;
	
	for(i = string_length - 1; i >= 0; i--) {
		if (!isspace(src[i])) {
			src[i + 1] = '\0';
			non_space_found = 1;
			break;
		}
	}
	
	if (!non_space_found) {
		src[0] = '\0';
	}
}

void trim_ref(char src[]) {
	ltrim_ref(src);
	rtrim_ref(src);
}

char* ltrim_contrary(char* src) {
	char* trimmed;
	int i = 0, string_length = strlen(src), first_non_space_character_index = 0;
	int space_found = 0;
	
	for(i = 0; i < string_length; i++) {
		first_non_space_character_index = i;
		if (isspace(src[i])) {
			space_found = 1;
			break;
		}
	}
	if (!space_found) {
		first_non_space_character_index++;
	}
	
	int trimmed_length = string_length - first_non_space_character_index;
	trimmed = malloc(trimmed_length + 1);
	if (trimmed == NULL) {
		return src;
	}
	strncpy(trimmed, src + first_non_space_character_index, trimmed_length);
	trimmed[trimmed_length] = '\0';
	
	return trimmed;
}

char* rtrim_contrary(char* src) {
	char* trimmed;
	int i = 0, string_length = strlen(src), last_non_space_character_index = 0;
	int space_found = 0;
	
	for(i = string_length - 1; i >= 0; i--) {
		last_non_space_character_index = i;
		if (isspace(src[i])) {
			space_found = 1;
			break;
		}
	}
	if (!space_found) {
		last_non_space_character_index = -1;
	}
	
	int trimmed_length = last_non_space_character_index + 1;
	trimmed = malloc(trimmed_length + 1);
	if (trimmed == NULL) {
		return src;
	}
	strncpy(trimmed, src, trimmed_length);
	trimmed[trimmed_length] = '\0';
	
	return trimmed;
}

char* trim_contrary(char* src) {
	char* ltrimmed = ltrim_contrary(src);
	char* trimmed = rtrim_contrary(ltrimmed);
	free(ltrimmed);
	return trimmed;
}

void ltrim_contrary_ref(char src[]) {
	int i = 0, string_length = strlen(src), first_non_space_character_index = 0;
	int space_found = 0;
	
	for(i = 0; i < string_length; i++) {
		first_non_space_character_index = i;
		if (isspace(src[i])) {
			space_found = 1;
			break;
		}
	}
	
	if (first_non_space_character_index == 0) {
		return;
	}
	
	if (!space_found) {
		first_non_space_character_index++;
	}
	
	int trimmed_length = string_length - first_non_space_character_index;
	for(i = first_non_space_character_index; i < string_length; i++) {
		src[i - first_non_space_character_index] = src[i];
	}
	src[trimmed_length] = '\0';
}

void rtrim_contrary_ref(char src[]) {
	int i = 0, string_length = strlen(src);
	int space_found = 0;
	
	for(i = string_length - 1; i >= 0; i--) {
		if (isspace(src[i])) {
			src[i + 1] = '\0';
			space_found = 1;
			break;
		}
	}
	
	if (!space_found) {
		src[0] = '\0';
	}
}

void trim_contrary_ref(char src[]) {
	ltrim_contrary_ref(src);
	rtrim_contrary_ref(src);
}
