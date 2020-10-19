#include <stack>
#include "ast.h"

class EvaluationVisitor : public ASTvisitor
{
public:
    static std::stack<int> op_stack;
    static void empty_stack()
    {
        while (!op_stack.empty())
        {
            op_stack.pop();
        }
    }

    virtual void visit(BinaryASTnode &node)
    {
        node.getLeft()->accept(*this);
        node.getRight()->accept(*this);

        int r = op_stack.top();
        op_stack.pop();
        int l = op_stack.top();
        op_stack.pop();

        if (node.getBin_operator() == "+")
        {
            op_stack.push(l + r);
        }
        else if (node.getBin_operator() == "-")
        {
            op_stack.push(l - r);
        }
        else if (node.getBin_operator() == "*")
        {
            op_stack.push(l * r);
        }
        else
        {
            op_stack.push(l / r);
        }
    }

    virtual void visit(TernaryASTnode &node)
    {
        node.getFirst()->accept(*this);
        int f = op_stack.top();
        op_stack.pop();

        if (f != 0)
        {
            node.getSecond()->accept(*this);
        }
        else
        {
            node.getThird()->accept(*this);
        }
    }

    virtual void visit(IntLitASTnode &node)
    {
        op_stack.push(node.getIntLit());
    }
};
std::stack<int> EvaluationVisitor::op_stack = *(new std::stack<int>);