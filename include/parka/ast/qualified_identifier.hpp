#ifndef PARKA_AST_QUALIFIED_IDENTIFIER_HPP
#define PARKA_AST_QUALIFIED_IDENTIFIER_HPP

#include "parka/ast/identifier.hpp"
#include "parka/util/array.hpp"
#include "parka/util/optional.hpp"

class QualifiedIdentifier
{
	Array<Identifier> _parts;
	bool _isAbsolute;

	QualifiedIdentifier(Array<Identifier>&& parts, bool isAbsolute) :
	_parts(std::move(parts)),
	_isAbsolute(isAbsolute)
	{}

public:

	static Optional<QualifiedIdentifier> parse(Token& token);

	const auto& operator[](usize index) const { return _parts[index]; }
	const auto *begin() const { return _parts.begin(); }
	const auto *end() const { return _parts.end(); }

	friend std::ostream& operator<<(std::ostream& out, const QualifiedIdentifier& identifier);

	const auto& length() const { return _parts.length(); }
	const auto& isAbsolute() const { return _isAbsolute; }
};

#endif