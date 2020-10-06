// $Id$
#include <iostream>
#include <fstream>

#include "driver.h"
#include "ast.h"

std::stack<int> ASTContext::op_stack = *(new std::stack<int>);

int main(int argc, char *argv[])
{
    ASTContext ast;
    decaf::Driver driver(ast);
    
    std::string line;
    while( std::cout << "input: " &&
	   std::getline(std::cin, line) &&
	   !line.empty() )
    {
	    
	    bool result = driver.parse_string(line, "input");

	    if (result)
    	{
            std::cout<<"Successfully Parsed!"<<std::endl;
            if (ast.root != NULL) {
                /* Code */
                std::cout << "Prefix    : ";
                ast.root->printPreFix();
                std::cout << std::endl;

                std::cout << "Postfix   : ";
                ast.root->printPostFix();
                std::cout << std::endl;
                
                std::cout << "Evaluation: ";
                std::cout << ast.evaluate();
                std::cout << std::endl; 
                
                std::cout << std::endl;
            }
            ast.clearAST();
	    }
	}
}

