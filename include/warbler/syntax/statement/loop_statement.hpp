#ifndef WARBLER_SYNTAX_LOOP_STATEMENT_HPP
#define WARBLER_SYNTAX_LOOP_STATEMENT_HPP

// local headers
#include <warbler/lexicon/token.hpp>
#include <warbler/result.hpp>
#include <warbler/syntax/loop_condition.hpp>

namespace warbler::syntax
{
	class Statement;
	
	enum LoopType
	{
		LOOP_FOR,
		LOOP_WHILE,
		LOOP_LOOP
	};

	class LoopStatement
	{
	private:

		Array<Statement> _body;
		LoopCondition _condition;
		LoopType _type;

	public:

		LoopStatement(Array<Statement>&& body, LoopCondition&& condition, LoopType type);

		static Result<LoopStatement> parse(lexicon::TokenIterator& iter);

		void print_tree(u32 depth = 0) const;
	};
}

#endif
