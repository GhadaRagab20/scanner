/*
 * util.h
 *
 *  Created on: Dec 14, 2020
 *      Author: ghada
 */

#ifndef UTIL_H_
#define UTIL_H_


void printToken(TokenType,const char*);

TreeNode* newStmtNode(StmtKind);

TreeNode* newEXPNode(ExpKind);
char*copystring(char*);
void printTree(TreeNode*);




#endif /* UTIL_H_ */
