#include "ast.h"

class PreFixVisitor : public ASTvisitor
{
public:
    virtual void visit(BinaryASTnode &node)
    {
        std::cout << node.getBin_operator() << " ";
        node.getLeft()->accept(*this);
        node.getRight()->accept(*this);
    }

    virtual void visit(TernaryASTnode &node)
    {
        std::cout << "?"
                  << " "
                  << ":"
                  << " ";
        node.getFirst()->accept(*this);
        node.getSecond()->accept(*this);
        node.getThird()->accept(*this);
    }

    virtual void visit(IntLitASTnode &node)
    {
        std::cout << node.getIntLit() << " ";
    }
};