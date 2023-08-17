/* 
 * File:   trim.h
 * Author: ringo
 *
 * Created on 15. Februar 2014, 20:14
 */

#ifndef TRIM_H
#define	TRIM_H

#ifdef	__cplusplus
extern "C" {
#endif
	
	#define WHITESPACES "\t\n\v\f\r "

	/**
	 * @Description\n
	 * &nbsp;&nbsp;the ltrim() function trims src from leading whitespaces and returns a malloc'd char* pointer, so it must be free'd!
	 * @param char* src
     * @return char*
     */
	char* ltrim(char* src);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the ltrim_chars() function trims src from leading trim_chars and returns a malloc'd char* pointer, so it must be free'd!
	 * @param char* src
     * @return char*
     */
	char* ltrim_chars(char* src, const char *trim_chars);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the rtrim() function trims src from trailing whitespaces and returns a malloc'd char* pointer, so it must be free'd!
	 * @param char* src
     * @return char*
     */
	char* rtrim(char* src);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the rtrim_chars() function trims src from trailing trim_chars and returns a malloc'd char* pointer, so it must be free'd!
	 * @param char* src
     * @return char*
     */
	char* rtrim_chars(char* src, const char *trim_chars);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the trim() function trims src from whitespaces and returns a malloc'd char* pointer, so it must be free'd!
	 * @param char* src
     * @return char*
     */
	char* trim(char* src);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the trim_chars() function trims src from trim_chars and returns a malloc'd char* pointer, so it must be free'd!
	 * @param char* src
     * @return char*
     */
	char* trim_chars(char* src, const char *trim_chars);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the ltrim_ref() function trims the given src from leading whitespaces!
	 * @param char* src
     * @return char*
     */
	void ltrim_ref(char src[]);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the ltrim_chars_ref() function trims the given src from leading characters!
	 * @param char* src
     * @return char*
     */
	void ltrim_chars_ref(char src[], const char *trim_chars);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the rtrim_ref() function trims the given src from trailing whitespaces!
	 * @param char* src
     * @return char*
     */
	void rtrim_ref(char src[]);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the rtrim_chars_ref() function trims the given src from trailing characters!
	 * @param char* src
     * @return char*
     */
	void rtrim_chars_ref(char src[], const char *trim_chars);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the trim_ref() function trims the given src from whitespaces!
	 * @param char* src
     * @return char*
     */
	void trim_ref(char src[]);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the trim_chars_ref() function trims the given src from characters!
	 * @param char* src
     * @return char*
     */
	void trim_chars_ref(char src[], const char *trim_chars);
	
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the ltrim_contrary() function trims src from leading non-whitespaces and returns a malloc'd char* pointer, so it must be free'd!
	 * @param char* src
     * @return char*
     */
	char* ltrim_contrary(char* src);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the rtrim_contrary() function trims src from trailing non-whitespaces and returns a malloc'd char* pointer, so it must be free'd!
	 * @param char* src
     * @return char*
     */
	char* rtrim_contrary(char* src);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the trim_contrary() function trims src from non-whitespaces and returns a malloc'd char* pointer, so it must be free'd!
	 * @param char* src
     * @return char*
     */
	char* trim_contrary(char* src);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the ltrim_contrary_ref() function trims the given src from leading non-whitespaces!
	 * @param char* src
     * @return char*
     */
	void ltrim_contrary_ref(char src[]);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the rtrim_contrary_ref() function trims the given src from trailing non-whitespaces!
	 * @param char* src
     * @return char*
     */
	void rtrim_contrary_ref(char src[]);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the trim_contrary_ref() function trims the given src from non-whitespaces!
	 * @param char* src
     * @return char*
     */
	void trim_contrary_ref(char src[]);

#ifdef	__cplusplus
}
#endif

#endif	/* TRIM_H */

