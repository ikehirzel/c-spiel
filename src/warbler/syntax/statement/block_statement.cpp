#include <warbler/syntax/statement/block_statement.hpp>

#include <warbler/util/print.hpp>

namespace warbler::syntax
{
	BlockStatement::BlockStatement(Array<Ptr<Statement>>&& statements) :
	_statements(std::move(statements))
	{}

	Result<BlockStatement> BlockStatement::parse(lexicon::Token& token)
	{
		if (token.type() != lexicon::TokenType::LeftBrace)
		{
			print_parse_error(token, "compound statement starting with '{'");
			return {};
		}

		token.next();

		Array<Ptr<Statement>> statements;

		while (token.type() != lexicon::TokenType::RightBrace)
		{
			auto res = Statement::parse(token);


			if (!res)
				return {};

			statements.emplace_back(res.unwrap());
		}

		token.next();

		return BlockStatement { std::move(statements) };
	}

	// bool BlockStatement::validate(semantics::SymbolTable& symbols)
	// {
	// 	func_ctx.blocks.push_back(&_context);

	// 	for (auto& statement : _statements)
	// 	{
	// 		if (!statement->validate(mod_ctx, func_ctx))
	// 			return false;
	// 	}

	// 	func_ctx.blocks.pop_back();

	// 	return true;
	// }
}
