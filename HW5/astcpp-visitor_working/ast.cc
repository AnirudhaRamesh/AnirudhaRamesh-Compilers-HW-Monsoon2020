// $Id$

#include <iostream>
#include <fstream>

#include "driver.h"
// #include "ast.h"  
// ast.h included in PostFixVisitor.h
#include "PostFixVisitor.h"
#include "PreFixVisitor.h"
#include "EvaluationVisitor.h"

int main(int argc, char *argv[])
{
    ASTContext ast;
    decaf::Driver driver(ast);
    PostFixVisitor postfixvisitor;
    PreFixVisitor prefixvisitor;
    EvaluationVisitor evaluationvisitor;
    
    std::string line;
    while( std::cout << "input: " &&
	   std::getline(std::cin, line) &&
	   !line.empty() )
    {
	    
	    bool result = driver.parse_string(line, "input");

	    if (result)
    	{
            if (ast.root != NULL ) {
                std::cout<<"Successfully Parsed!"<<std::endl;
                
                BinaryASTnode* bnode;
                TernaryASTnode* tnode;
                IntLitASTnode* inode;

                std::cout << "Prefix    : ";
                bnode = dynamic_cast<BinaryASTnode*>(ast.root);
                if (bnode != NULL) {
                    prefixvisitor.visit(*bnode);
                }

                tnode = dynamic_cast<TernaryASTnode*>(ast.root);
                if (tnode != NULL) {
                    prefixvisitor.visit(*tnode);
                }
                
                inode = dynamic_cast<IntLitASTnode*>(ast.root);
                if (inode != NULL) {
                    prefixvisitor.visit(*inode);
                }
                std::cout << std::endl;

                std::cout << "Postfix   : ";
                bnode = dynamic_cast<BinaryASTnode*>(ast.root);
                if (bnode != NULL) {
                    postfixvisitor.visit(*bnode);
                }

                tnode = dynamic_cast<TernaryASTnode*>(ast.root);
                if (tnode != NULL) {
                    postfixvisitor.visit(*tnode);
                }
                
                inode = dynamic_cast<IntLitASTnode*>(ast.root);
                if (inode != NULL) {
                    postfixvisitor.visit(*inode);
                }
                std::cout << std::endl;
                
                std::cout << "Evaluation: ";
                bnode = dynamic_cast<BinaryASTnode*>(ast.root);
                if (bnode != NULL) {
                    EvaluationVisitor::empty_stack();
                    evaluationvisitor.visit(*bnode);
                    std::cout << EvaluationVisitor::op_stack.top();
                }

                tnode = dynamic_cast<TernaryASTnode*>(ast.root);
                if (tnode != NULL) {
                    EvaluationVisitor::empty_stack();
                    evaluationvisitor.visit(*tnode);
                    std::cout << EvaluationVisitor::op_stack.top();
                }
                
                inode = dynamic_cast<IntLitASTnode*>(ast.root);
                if (inode != NULL) {
                    EvaluationVisitor::empty_stack();
                    evaluationvisitor.visit(*inode);
                    std::cout << EvaluationVisitor::op_stack.top();
                }
                std::cout << std::endl;

                std::cout << std::endl;
            }
            ast.clearAST();
	    }
	}
}

