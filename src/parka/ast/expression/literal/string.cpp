#include "parka/ast/expression/literal/string.hpp"
#include "parka/symbol/node_bank.hpp"
#include "parka/util/print.hpp"

Optional<ExpressionId> StringLiteral::parse(Token& token)
{
	if (token.type() != TokenType::StringLiteral)
	{
		printParseError(token, "string");
		return {};
	}

	auto literal = StringLiteral(token, token.text());
	auto id = NodeBank::add(std::move(literal));

	token.increment();

	return id;
}

bool StringLiteral::validate(const EntityId&)
{
	return true;
}

Optional<Type> StringLiteral::getType() const
{
	return Type::stringType;
}

