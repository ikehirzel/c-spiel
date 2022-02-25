#include <warbler/syntax/expression/additive_expression.hpp>

// local headers
#include <warbler/util/print.hpp>
#include <stdexcept>

namespace warbler::syntax
{
	AdditiveExpression::AdditiveExpression(Ptr<Expression>&& lhs, Array<AdditiveRhs>&& rhs) :
	_lhs(std::move(lhs)),
	_rhs(std::move(rhs))
	{}

	Result<Ptr<Expression>> AdditiveExpression::parse(lexicon::TokenIterator& iter)
	{
		auto lhs = MultiplicativeExpression::parse(iter);

		if (!lhs)
			return {};

		Array<AdditiveRhs> rhs;

		while (true)
		{
			AdditiveType type;
			if (iter->type() == lexicon::TOKEN_PLUS)
			{
				type = ADDITIVE_ADD;
			}
			else if (iter->type() == lexicon::TOKEN_MINUS)
			{
				type = ADDITIVE_ADD;
			}
			else
			{
				break;
			}

			iter += 1;			

			auto res = MultiplicativeExpression::parse(iter);

			if (!res)
				return {};

			rhs.emplace_back(AdditiveRhs { res.unwrap(), type });
		}

		if (rhs.empty())
			return lhs.unwrap();

		auto *ptr = new AdditiveExpression(lhs.unwrap(), std::move(rhs));

		return Ptr<Expression>(ptr);
	}

	bool AdditiveExpression::validate(semantics::ModuleContext& mod_ctx, semantics::FunctionContext& func_ctx)
	{
		if (!_lhs->validate(mod_ctx, func_ctx))
			return false;

		for (auto& rhs : _rhs)
		{
			if (!rhs.expr->validate(mod_ctx, func_ctx))
				return false;
		}

		return true;
	}

	void AdditiveExpression::print_tree(u32 depth) const
	{
		if (_rhs.size() > 0)
			depth += 1;

		_lhs->print_tree(depth);
		
		for (const auto& rhs : _rhs)
		{
			print_branch(depth - 1, rhs.type == ADDITIVE_ADD ? "+" : "-");
			rhs.expr->print_tree(depth);
		}
	}

	Type *AdditiveExpression::get_type()
	{
		throw std::runtime_error("AdditiveExpression::" + String(__func__) + " is not implemented yet");
	}

	const source::Location& AdditiveExpression::location() const
	{
		throw std::runtime_error("AdditiveExpression::" + String(__func__) + " is not implemented yet");
	}
}
