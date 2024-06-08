#ifndef PARKA_VALIDATION_PRIMITIVE_TYPE_CONTEXT_HPP
#define PARKA_VALIDATION_PRIMITIVE_TYPE_CONTEXT_HPP

#include "parka/validation/TypeContext.hpp"

namespace parka::validation
{
	class I32TypeContext: public TypeContext
	{
	public:

		static I32TypeContext instance;
	
	private:

		I32TypeContext() = default;
		I32TypeContext(I32TypeContext&&) = default;
		I32TypeContext(const I32TypeContext&) = default;

	public:

		ir::BinaryOperatorIr* getBinaryOperator(BinaryExpressionType, const ir::TypeIr&) const;
		ir::AssignmentOperatorIr* getAssignmentOperator(AssignmentType, const ir::TypeIr&) const;
	};
}

#endif
