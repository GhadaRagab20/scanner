/*
 * global.h
 *
 *  Created on: Dec 14, 2020
 *      Author: ghada
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#define MAXRESERVED 8
typedef enum
{ENDFILE,ERROR,
 IF,THEN,ELSE,END,REPEAT,UNTIL,READ,WRITE,
 ID,NUM,
 ASSIGN,EQ,LT,PLUS,MINUS,TIMES,OVER,LPAREN,RPAREN,SEMI
}TokenType;

//FILE* source;
extern FILE* listing;

extern FILE* code;

extern int lineno;

/*Syntax Tree for parsing*/
typedef enum  {StmtK,ExpK} NodeKind;
typedef enum  {IfK,RepeatK,AssignK,ReadK,WriteK} StmtKind;
typedef enum  {OpK,ConstK,IdK}ExpKind;

typedef enum  {Void,Integer,Boolean} ExpType;

#define MAXCHELDREN 3
typedef struct treeNode{
	struct treeNode *child[MAXCHELDREN];
	struct treeNode *sibling;
	int Lineno;
	NodeKind nodekind;
	union{ StmtKind stmt;ExpKind exp;}Kind;
	union{ TokenType op;int val;char* name;}attr;
    ExpType type;
}TreeNode;


extern int EchoSources;

//extern int TraceScan;

extern int traceParse;

extern int TraceAnalyse;

extern int TraceCode;

extern int Error;

#endif /* GLOBAL_H_ */
