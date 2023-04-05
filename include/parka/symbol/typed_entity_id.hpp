#ifndef PARKA_ENTITY_TYPED_ENTITY_ID_HPP
#define PARKA_ENTITY_TYPED_ENTITY_ID_HPP

#include "parka/symbol/entity_id.hpp"
#include "parka/symbol/expression_id.hpp"
#include "parka/util/optional.hpp"
#include "parka/util/primitives.hpp"

enum class TypedEntityType: u8
{
	Struct,
	Primitive,
	Function,
	Variable,
	Parameter
};

class TypedEntityId
{
	u32 _index;
	TypedEntityType _type;

	TypedEntityId(TypedEntityType type, u32 index) :
	_index(index),
	_type(type)
	{}

public:

	TypedEntityId(TypedEntityId&&) = default;
	TypedEntityId(const TypedEntityId&) = default;
	~TypedEntityId() = default;
	TypedEntityId& operator=(TypedEntityId&& other) = default;
	TypedEntityId& operator=(const TypedEntityId& other) = default;

	static Optional<TypedEntityId> from(const EntityId& id);

	const auto& index() const { return _index; }
	const auto& type() const { return _type; }

	friend std::ostream& operator<<(std::ostream& out, const TypedEntityId& id);
	bool operator==(const TypedEntityId& other) const;

	friend struct NodeBank;
};

#endif
