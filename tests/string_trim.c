/*
 * File:   string_trim.c
 * Author: ringo
 *
 * Created on 16.02.2014, 10:57:24
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>

/*
 * CUnit Test Suite
 */

int init_suite(void) {
	return 0;
}

int clean_suite(void) {
	return 0;
}

void test_ltrim() {
	char *input = "\r\n\t hello world!\r\n\t ";
	char *output = ltrim(input);
	CU_ASSERT_STRING_EQUAL(output, "hello world!\r\n\t ");
	free(output);
}

void test_rtrim() {
	char *input = "\r\n\t hello world!\r\n\t ";
	char *output = rtrim(input);
	CU_ASSERT_STRING_EQUAL(output, "\r\n\t hello world!");
	free(output);
}

void test_trim() {
	char *input = "\r\n\t hello world!\r\n\t ";
	char *output = trim(input);
	CU_ASSERT_STRING_EQUAL(output, "hello world!");
	free(output);
}

void test_ltrim_ref() {
	char input[] = "\r\n\t hello world!\r\n\t ";
	ltrim_ref(input);
	CU_ASSERT_STRING_EQUAL(input, "hello world!\r\n\t ");
}

void test_rtrim_ref() {
	char input[] = "\r\n\t hello world!\r\n\t ";
	rtrim_ref(input);
	CU_ASSERT_STRING_EQUAL(input, "\r\n\t hello world!");
}

void test_trim_ref() {
	char input[] = "\r\n\t hello world!\r\n\t ";
	trim_ref(input);
	CU_ASSERT_STRING_EQUAL(input, "hello world!");
}

int main() {
	CU_pSuite pSuite = NULL;

	/* Initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	/* Add a suite to the registry */
	pSuite = CU_add_suite("string_trim", init_suite, clean_suite);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Add the tests to the suite */
	if ((NULL == CU_add_test(pSuite, "test_ltrim", test_ltrim)) ||
		(NULL == CU_add_test(pSuite, "test_rtrim", test_rtrim)) ||
		(NULL == CU_add_test(pSuite, "test_trim", test_trim)) ||
		(NULL == CU_add_test(pSuite, "test_ltrim_ref", test_ltrim_ref)) ||
		(NULL == CU_add_test(pSuite, "test_rtrim_ref", test_rtrim_ref)) ||
		(NULL == CU_add_test(pSuite, "test_trim_ref", test_trim_ref))) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
