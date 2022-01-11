#ifndef WARBLER_AST_ARGUMENT_HPP
#define WARBLER_AST_ARGUMENT_HPP

// standard headers
#include <warbler/result.hpp>
#include <warbler/token.hpp>
#include <warbler/ast/expression/expression.hpp>

namespace warbler
{
	class Argument
	{
	private:

		Expression *_expr;

	public:

		Argument(Expression *expr);
		~Argument();

		static Result<Argument> parse(TokenIterator& iter);
		static Result<std::vector<Argument>> parse_list(TokenIterator& iter);

		void print_tree(u32 depth = 0);
	};
}

#endif
