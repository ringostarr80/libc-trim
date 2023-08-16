#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#ifndef TRIM_H
#include "trim.h"
#endif

// standard trim functions
char* ltrim(char* src) {
	return ltrim_chars(src, WHITESPACES);
}

char* ltrim_chars(char* src, char *trim_chars) {
	char* trimmed;
	int i = 0, j = 0, string_length = strlen(src), first_non_space_character_index = 0;
	int non_space_found = 0, trim_char_found = 0;
	
	size_t trim_chars_count = sizeof(&trim_chars) / sizeof(char);
	if (trim_chars_count > 0) {
		for(i = 0; i < string_length; i++) {
			first_non_space_character_index = i;
			trim_char_found = 0;
			for(j = 0; j < trim_chars_count; j++) {
				if (src[i] == trim_chars[j]) {
					trim_char_found = 1;
					break;
				}
			}
			if (!trim_char_found) {
				non_space_found = 1;
				break;
			}
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
	return rtrim_chars(src, WHITESPACES);
}

char* rtrim_chars(char* src, char *trim_chars) {
	char* trimmed;
	int i = 0, j = 0, string_length = strlen(src), last_non_space_character_index = 0;
	int non_space_found = 0, trim_char_found = 0;
	
	size_t trim_chars_count = sizeof(&trim_chars) / sizeof(trim_chars[0]);
	if (trim_chars_count > 0) {
		for(i = string_length - 1; i >= 0; i--) {
			last_non_space_character_index = i;
			trim_char_found = 0;
			for(j = 0; j < trim_chars_count; j++) {
				if (src[i] == trim_chars[j]) {
					trim_char_found = 1;
					break;
				}
			}
			if (!trim_char_found) {
				non_space_found = 1;
				break;
			}
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
	return trim_chars(src, WHITESPACES);
}

char* trim_chars(char* src, char *trim_chars) {
	char* ltrimmed = ltrim_chars(src, trim_chars);
	char* trimmed = rtrim_chars(ltrimmed, trim_chars);
	free(ltrimmed);
	return trimmed;
}

void ltrim_ref(char src[]) {
	ltrim_chars_ref(src, WHITESPACES);
}

void ltrim_chars_ref(char src[], char *trim_chars) {
	int i = 0, j = 0, string_length = strlen(src), first_non_space_character_index = 0;
	int non_space_found = 0, trim_char_found = 0;
	
	size_t trim_chars_count = sizeof(&trim_chars) / sizeof(trim_chars[0]);
	if (trim_chars_count == 0) {
		return;
	}
	
	for(i = 0; i < string_length; i++) {
		first_non_space_character_index = i;
		trim_char_found = 0;
		for(j = 0; j < trim_chars_count; j++) {
			if (src[i] == trim_chars[j]) {
				trim_char_found = 1;
				break;
			}
		}
		if (!trim_char_found) {
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
	rtrim_chars_ref(src, WHITESPACES);
}

void rtrim_chars_ref(char src[], char *trim_chars) {
	int i = 0, j = 0, string_length = strlen(src);
	int non_space_found = 0, trim_char_found = 0;
	
	size_t trim_chars_count = sizeof(&trim_chars) / sizeof(trim_chars[0]);
	if (trim_chars_count == 0) {
		return;
	}
	
	for(i = string_length - 1; i >= 0; i--) {
		trim_char_found = 0;
		for(j = 0; j < trim_chars_count; j++) {
			if (src[i] == trim_chars[j]) {
				trim_char_found = 1;
				break;
			}
		}
		if (!trim_char_found) {
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
	trim_chars_ref(src, WHITESPACES);
}

void trim_chars_ref(char src[], char *trim_chars) {
	ltrim_chars_ref(src, trim_chars);
	rtrim_chars_ref(src, trim_chars);
}

// contrary trim functions
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
