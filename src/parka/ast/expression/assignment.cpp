#include "parka/ast/expression/assignment.hpp"
#include "parka/ast/expression/additive.hpp"
#include "parka/ast/expression/conditional.hpp"
#include "parka/validator.hpp"

Optional<AssignmentType> getAssignmentType(Token& token)
{
	switch (token.type())
	{
		case TokenType::Assign:
			return ASSIGNMENT_BECOME;

		case TokenType::MultiplyAssign:
			return ASSIGNMENT_MULTIPLY;

		case TokenType::DivideAssign:
			return ASSIGNMENT_DIVIDE;

		case TokenType::ModulusAssign:
			return ASSIGNMENT_MODULUS;

		case TokenType::AddAssign:
			return ASSIGNMENT_ADD;

		case TokenType::SubtractAssign:
			return ASSIGNMENT_SUBTRACT;

		case TokenType::LeftBitShiftAssign:
			return ASSIGNMENT_LEFT_BIT_SHIFT;

		case TokenType::RightBitShiftAssign:
			return ASSIGNMENT_RIGHT_BIT_SHIFT;

		case TokenType::BitwiseAndAssign:
			return ASSIGNMENT_BITWISE_AND;

		case TokenType::BitwiseOrAssign:
			return ASSIGNMENT_BITWISE_OR;

		case TokenType::BitwiseXorAssign:
			return ASSIGNMENT_BITWISE_XOR;
		
		default:
			return {};
	}
}

Optional<Box<Expression>> Assignment::parse(Token& token)
{
	auto lhs = ConditionalExpression::parse(token);

	if (!lhs)
		return {};

	auto type = getAssignmentType(token);

	if (!type)
		return lhs;

	token.increment();

	auto rhs = ConditionalExpression::parse(token);

	if (!rhs)
		return {};

	auto *expression = new Assignment(lhs.unwrap(), rhs.unwrap(), type.unwrap());
	auto box = Box<Expression>(expression);

	return box;
}

bool Assignment::validate(SymbolTable& symbols)
{
	bool success = true;

	if (!_lhs->validate(symbols))
		success = false;

	if (!_rhs->validate(symbols))
		success = false;

	// TODO: validate type of assignment

	return success;
}
