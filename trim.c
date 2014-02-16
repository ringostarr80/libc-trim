#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* ltrim(char* src) {
	char* trimmed;
	int i = 0, string_length = strlen(src), first_non_space_character_index = 0;
	
	for(i = 0; i < string_length; i++) {
		if (!isspace(src[i])) {
			first_non_space_character_index = i;
			break;
		}
	}
	
	int trimmed_length = string_length - first_non_space_character_index;
	trimmed = malloc(trimmed_length + 1);
	if (trimmed == NULL) {
		return src;
	}
	strncpy(trimmed, src + first_non_space_character_index, string_length - first_non_space_character_index);
	trimmed[trimmed_length] = '\0';
	
	return trimmed;
}

char* rtrim(char* src) {
	char* trimmed;
	int i = 0, string_length = strlen(src), last_non_space_character_index = 0;
	
	for(i = string_length - 1; i >= 0; i--) {
		if (!isspace(src[i])) {
			last_non_space_character_index = i;
			break;
		}
	}
	
	trimmed = malloc(sizeof(char) * (last_non_space_character_index + 2));
	if (trimmed == NULL) {
		return src;
	}
	strncpy(trimmed, src, last_non_space_character_index + 1);
	trimmed[last_non_space_character_index + 1] = '\0';
	
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
	
	for(i = 0; i < string_length; i++) {
		if (!isspace(src[i])) {
			first_non_space_character_index = i;
			break;
		}
	}
	
	if (first_non_space_character_index == 0) {
		return;
	}
	
	int trimmed_length = string_length - first_non_space_character_index;
	for(i = first_non_space_character_index; i < string_length; i++) {
		src[i - first_non_space_character_index] = src[i];
	}
	src[trimmed_length] = '\0';
}

void rtrim_ref(char src[]) {
	int i = 0, string_length = strlen(src), last_non_space_character_index = 0;
	
	for(i = string_length - 1; i >= 0; i--) {
		if (!isspace(src[i])) {
			src[i + 1] = '\0';
			break;
		}
	}
}

void trim_ref(char src[]) {
	ltrim_ref(src);
	rtrim_ref(src);
}
