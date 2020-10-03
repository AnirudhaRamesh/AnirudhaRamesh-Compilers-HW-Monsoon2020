#include <iostream>
#include <stack>
class BinaryASTnode;
class TernaryASTnode;
class IntLitASTnode;

class ASTnode
{
public:
    virtual void printPostFix() const = 0;
    virtual void printPreFix() const = 0;
    virtual void evaluate() const = 0;
    virtual ~ASTnode() {}
};

class ASTContext
{
public:
    static std::stack<int> op_stack;
    ASTnode *root;

    ~ASTContext()
    {
        clearAST();
    }

    static void empty_stack()
    {
        while (!op_stack.empty())
        {
            op_stack.pop();
        }
    }

    int evaluate()
    {
        empty_stack();

        if (root != NULL)
        {
            root->evaluate();
            return op_stack.top();
        }
        else
        {
            // Return MAX value in case root is NULL
            return INT32_MAX;
        }
    }

    // free all saved expression trees
    void clearAST()
    {
        delete root;
    }
};

class BinaryASTnode : public ASTnode
{
    // LHS and RHS can be of any type. So we need to use BaseAST
    ASTnode *lhs;
    ASTnode *rhs;
    std::string bin_operator;

public:
    // Constructor to initialize binary operator, lhs and rhs of the binary expression.
    BinaryASTnode(std::string op, ASTnode *_lhs, ASTnode *_rhs) : bin_operator(op), lhs(_lhs), rhs(_rhs) {}

    virtual void printPostFix() const
    {
        lhs->printPostFix();
        rhs->printPostFix();
        std::cout << bin_operator << " ";
    }

    virtual void printPreFix() const
    {
        std::cout << bin_operator << " ";
        lhs->printPreFix();
        rhs->printPreFix();
    }

    virtual void evaluate() const
    {
        lhs->evaluate();
        rhs->evaluate();

        int r_op = ASTContext::op_stack.top();
        ASTContext::op_stack.pop();
        int l_op = ASTContext::op_stack.top();
        ASTContext::op_stack.pop();

        if (bin_operator == "+")
        {
            ASTContext::op_stack.push(l_op + r_op);
        }
        else if (bin_operator == "-")
        {
            ASTContext::op_stack.push(l_op - r_op);
        }
        else if (bin_operator == "*")
        {
            ASTContext::op_stack.push(l_op * r_op);
        }
        else
        {
            ASTContext::op_stack.push(l_op / r_op);
        }
    }
};

class TernaryASTnode : public ASTnode
{
    ASTnode *first;
    ASTnode *second;
    ASTnode *third;

public:
    TernaryASTnode(ASTnode *first, ASTnode *second, ASTnode *third) : first(first), second(second), third(third) {}

    virtual void printPostFix() const
    {
        first->printPostFix();
        second->printPostFix();
        third->printPostFix();
        std::cout << "?"
                  << " ";
        std::cout << ":"
                  << " ";
    }

    virtual void printPreFix() const
    {
        std::cout << "?"
                  << " ";
        std::cout << ":"
                  << " ";
        first->printPreFix();
        second->printPreFix();
        third->printPreFix();
    }

    virtual void evaluate() const
    {
        first->evaluate();
        int f = ASTContext::op_stack.top();
        ASTContext::op_stack.pop();

        if (f != 0)
        {
            second->evaluate();
        }
        else
        {
            third->evaluate();
        }
    }
};

class IntLitASTnode : public ASTnode
{
    int intlit;

public:
    IntLitASTnode(int intlit) : intlit(intlit) {}

    virtual void printPostFix() const
    {
        std::cout << intlit << " ";
    }

    virtual void printPreFix() const
    {
        std::cout << intlit << " ";
    }

    virtual void evaluate() const
    {
        ASTContext::op_stack.push(intlit);
    }
};
