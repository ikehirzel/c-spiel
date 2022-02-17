#ifndef WARBLER_AST_EXPRESSION_POSTFIX_EXRESSION
#define WARBLER_AST_EXPRESSION_POSTFIX_EXRESSION

#include <warbler/ast/expression/expression.hpp>
#include <warbler/ast/name.hpp>

namespace warbler::ast
{
	enum PostfixType
	{
		POSTFIX_INDEX,
		POSTFIX_FUNCTION_CALL,
		POSTFIX_MEMBER
	};

	class PostfixExpression : public Expression
	{
	private:

		Ptr<Expression> _expression;

		union
		{
			Ptr<Expression> _index;
			Array<Ptr<Expression>> _arguments;
			Name _member;
		};

		PostfixType _type;

	public:

		PostfixExpression(Ptr<Expression>&& expression, Ptr<Expression>&& index);
		PostfixExpression(Ptr<Expression>&& expression, Array<Ptr<Expression>>&& arguments);
		PostfixExpression(Ptr<Expression>&& expression, Name&& member);
		
		static Result<Ptr<Expression>> parse(TokenIterator& iter);

		bool validate(semantics::ModuleContext& module, semantics::FunctionContext function);
		ast::Type *get_type(semantics::ModuleContext& module) const;
		const Location& location() const;
		void print_tree(u32 depth = 0) const;
	};
}

#endif
