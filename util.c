/*
 * util.c
 *
 *  Created on: Dec 16, 2020
 *      Author: ghada
 */


#include "global.h"
#include "util.h"

void printToken (TokenType token, const char* tokenString){
	switch(token){
	case IF:
	case THEN:
	case ELSE:
	case REPEAT:
	case UNTIL:
	case READ:
	case WRITE:
		fprintf(listing , "reserved word: %s\n" , tokenString);
		break;
	case ASSIGN: fprintf (listing, ":=\n"); break;
	case LT:fprintf (listing, "<\n"); break;
	case EQ:fprintf (listing, "=\n"); break;
	case LPAREN :fprintf (listing, "(\n"); break;
	case RPAREN:fprintf (listing, ")\n"); break;
	case SEMI:fprintf (listing, ";\n"); break;
	case PLUS:fprintf (listing, "+\n"); break;
	case MINUS:fprintf (listing, "-\n"); break;
	case TIMES:fprintf (listing, "*\n"); break;
	case OVER:fprintf (listing, "/\n"); break;
	case ENDFILE:fprintf (listing, "EOF\n"); break;
	case NUM: fprintf (listing, "NUM , val= %s\n", tokenString); break;
	case ID: fprintf(listing,"ID, name = %s\n",tokenString); break;
	case ERROR:fprintf (listing ,"ERROR :%s\n",tokenString); break;
	default : fprintf(listing , "Unknown token: %d\n", token);

	}
}
TreeNode * newStmtNode(StmtKind kind)
{
	TreeNode * t = (TreeNode *) malloc (sizeof (TreeNode));
	int i ;
	if (t == NULL){fprintf(listing , "Out of memory error at line %d\n" ,lineno );}

	else {
		for (i=0 ; i< MAXCHELDREN; i++) t-> child[i] = NULL;
		t-> sibling= NULL ;
		t-> nodekind = StmtK;
		t-> Kind.stmt= kind ;
		t-> Lineno = lineno ;
	}
	return t;
}
/* 423 Creates a  new Expression*/
TreeNode * newExpNode(){
	TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
	int i;
	if(t==NULL)
		fprintf(listing,"out of memory error at line %d\n",lineno);
	else{
		for(i=0;i<MAXCHELDREN;i++) t->child[i]=NULL;
		t->sibling =NULL;
		t->nodekind =ExpK;
		t->Lineno=lineno;
		t->type=Void;
	}
	return t;
}

// 445
char * copyString(char * s)
{
	int n;
	char * t;
	if(n==NULL)
		fprintf(listing,"out of memory error at line %d\n",lineno);
	else strcpy(t,s);
	return t;

}
static int indentno=0;
//463
#define INDENT indentno+=2
#define UNINDENT indentno-=2

//467
static void printSpaces(void)
{
	int i;
	for(i=0;i<indentno;i++)
		fprintf(listing," ");
}

//476
void printTree (TreeNode * tree)
{
	int i;
	INDENT;
	while (tree != NULL)
	{
		printSpaces();
		if (tree->nodekind==StmtK)  ///me4 wade7 481
				{
			switch (tree->Kind.stmt)
			{
			case IfK:
				fprintf(listing,"if\n");
				break;
			case RepeatK:
				fprintf(listing,"Repeat\n");
				break;
			case AssignK:
				fprintf(listing,"Assign to: $s\n",tree->attr.name);
				break;
			case ReadK:
				fprintf(listing,"Read to: $s\n",tree->attr.name);
				break;
			case WriteK:
				fprintf(listing,"Write\n");
				break;

			default:
				fprintf(listing,"Unknown ExpNode Kind\n");
				break;
			}
				}
		else if( tree->nodekind ==ExpK)
		{
			switch (tree->Kind.exp){
			case OpK:
				fprintf(listing,"Op: ");
				printToken(tree->attr.op,"\0");
				break;
			case ConstK:
				fprintf(listing,"const: %d\n", tree -> attr.val);
				break;
			case IdK:
				fprintf(listing,"Id: %s\n", tree -> attr.name);
				break;
			default:
				fprintf(listing,"Unknown ExpNode Kind \n");
				break;
			}
		}
		else fprintf(listing,"Unknown node kind\n");


		for (int i = 0; i < MAXCHELDREN; i++)
		{  printTree(tree->child[i]);}

		tree = tree->sibling;


	}
	UNINDENT;

}


