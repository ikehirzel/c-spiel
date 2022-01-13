#ifndef WARBLER_AST_STATEMENT_DECLARATION_STATEMENT_HPP
#define WARBLER_AST_STATEMENT_DECLARATION_STATEMENT_HPP

// local headers
#include <warbler/ast/identifier.hpp>
#include <warbler/ast/typename.hpp>
#include <warbler/ast/expression/expression.hpp>

namespace warbler
{
	class DeclarationStatement
	{
	private:

		Identifier _name;
		Typename _type;
		Expression _value;

	public:

		DeclarationStatement(Identifier&& name, Typename&& type, Expression&& value);

		static Result<DeclarationStatement> parse(TokenIterator& iter);

		void print_tree(u32 depth = 0) const;
	};
}

#endif
