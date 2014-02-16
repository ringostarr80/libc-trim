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

	/**
	 * @Description\n
	 * &nbsp;&nbsp;the ltrim() function trims src from leading whitespaces and returns a malloc'd char* pointer, so it must be free'd!
	 * @param char* src
     * @return char*
     */
	char* ltrim(char* src);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the rtrim() function trims src from trailing whitespaces and returns a malloc'd char* pointer, so it must be free'd!
	 * @param char* src
     * @return char*
     */
	char* rtrim(char* src);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the trim() function trims src from whitespaces and returns a malloc'd char* pointer, so it must be free'd!
	 * @param char* src
     * @return char*
     */
	char* trim(char* src);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the ltrim_ref() function trims the given src from leading whitespaces!
	 * @param char* src
     * @return char*
     */
	void ltrim_ref(char src[]);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the rtrim_ref() function trims the given src from trailing whitespaces!
	 * @param char* src
     * @return char*
     */
	void rtrim_ref(char src[]);
	/**
	 * @Description\n
	 * &nbsp;&nbsp;the trim_ref() function trims the given src from whitespaces!
	 * @param char* src
     * @return char*
     */
	void trim_ref(char src[]);

#ifdef	__cplusplus
}
#endif

#endif	/* TRIM_H */

