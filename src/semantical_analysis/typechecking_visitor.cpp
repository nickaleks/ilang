#include "typechecking_visitor.h"
#include <iostream>

/*
    Just a dummy method, exapmple of how it is used
*/
void TypeCheckingVisitor::visit(Prototype& node) 
{
    std::cout << "Visiting PrototypeNode: " << node.getName();
}

/*
    Check that array's size is an integer constant
*/
void TypeCheckingVisitor::visit(ArrayDecl& node) 
{
    auto sizeExpression = node.expression;
    if (sizeExpression->type->type != types::Integer)
    {
        reportError("Size of array is not compile-time integer constanst\n");
    }
}

/*
    Check that both sides of the assignment are of the same or
    compatible types. If second variant, cast it
*/
void TypeCheckingVisitor::visit(Assignment& node) 
{
    // Variable, array or record reference
    auto left = (Expression*) node.variable;
    auto left_type = left->type->type;
    auto right = (Expression*) node.value;
    auto right_type = right->type->type;

    if (left_type == types::Integer && right_type == types::Integer)
    {
        return;
    }
    else if (left_type == types::Integer && right_type == types::Real)
    {
        auto cast_node = new Cast { right, new IntegerType() };
        node.value = cast_node;
    }
    else if (left_type == types::Integer && right_type == types::Boolean)
    {
        auto cast_node = new Cast { right, new BooleanType() };
        node.value = cast_node;
    }
    else if (left_type == types::Real && right_type == types::Integer)
    {
        auto cast_node = new Cast { right, new IntegerType() };
        node.value = cast_node;
    }
    else if (left_type == types::Real && right_type == types::Real)
    {
        return;
    }
    else if (left_type == types::Real && right_type == types::Boolean)
    {
        auto cast_node = new Cast { right, new RealType() };
        node.value = cast_node;
    }
    else if (left_type == types::Boolean && right_type == types::Integer)
    {
        auto cast_node = new Cast { right, new BooleanType() };
        node.value = cast_node;
    }
    else if (left_type == types::Boolean && right_type == types::Boolean)
    {
        return;
    }
    else if (left_type == types::Array && right_type == types::Array)
    {
        if (*left->type != *right->type)
        {
            reportError("Trying to assign arrays of different types");
        }
        return;
    }
    else if (left_type == types::Record && right_type == types::Record)
    {
        if (*left->type != *right->type)
        {
            reportError("Trying to assign records of different types");
        }
        return;
    }
    else 
    {
        reportError("Trying to assign incompatible types");
    }
}

void TypeCheckingVisitor::visit(Binary& node) 
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(Boolean& node)
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(BooleanType& node)
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(Cast& node)
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(For& node) 
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(If& node) 
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(Integer& node) 
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(IntegerType& node) 
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(Real& node) 
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(RealType& node) 
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(RecordDecl& node) 
{
    std::cout << "Foo";
}

/*
    Check that function will return value of the expected type
*/
void TypeCheckingVisitor::visit(Routine& node) 
{
    // Go through all statements in body, find and check all returns
}

/*
    Check that arguments are exactly as in the routine declaration
*/
void TypeCheckingVisitor::visit(RoutineCall& node) 
{
    auto actualArguments = node.args;
    auto expectedArguments = node.callee->proto->args;
    auto routineName = node.callee->proto->name;

    // Check arguments
    auto argsLength = expectedArguments.size();
    if (actualArguments.size() != argsLength)
        reportError("Arguments of function " + routineName + " are incorrect! Expected " + 
            std::to_string(argsLength) + ", got " + std::to_string(actualArguments.size()));

    for (int i = 0; i < argsLength; i++)
    {
        if (((Expression*) expectedArguments[i])->type->type != ((Expression*) actualArguments[i])->type->type)
            reportError("Arguments of function " + routineName + 
                " are incorrect! Expected another type on " + std::to_string(i));
    }

    // Forward further
    node.callee->accept(*this);
}

void TypeCheckingVisitor::visit(TypeDecl& node) 
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(Unary& node) 
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(Undefined& node) 
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(Var& node) 
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(Variable& node) 
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(While& node) 
{
    std::cout << "Foo";
}

void TypeCheckingVisitor::visit(Return& node) 
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(RecordRef& node) 
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(ArrayRef& node) 
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(Program& node) 
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(Statements& node) 
{
    std::cout << "Foo";
}
void TypeCheckingVisitor::visit(Void& node) 
{
    std::cout << "Foo";
}