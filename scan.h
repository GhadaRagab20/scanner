/*
 * scan.h
 *
 *  Created on: Dec 14, 2020
 *      Author: ghada
 */

#ifndef SCAN_H_
#define SCAN_H_

#define MAXTOKENLEN 40

extern char tokenString[MAXTOKENLEN+1];

TokenType getToken(void);


#endif /* SCAN_H_ */
