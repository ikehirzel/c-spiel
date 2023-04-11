#ifndef PARKA_SYNTAX_EXPRESSION_PRIMARY_SYNTAX_HPP
#define PARKA_SYNTAX_EXPRESSION_PRIMARY_SYNTAX_HPP

#include "parka/syntax/ExpressionSyntax.hpp"

namespace parka
{
	struct PrimaryExpressionSyntax
	{
		static Optional<ExpressionId> parse(Token& token);
	};
}

#endif
