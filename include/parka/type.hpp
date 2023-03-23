#ifndef PARKA_TYPE_HPP
#define PARKA_TYPE_HPP

#include "parka/entity_context.hpp"
#include "parka/util/primitives.hpp"

class Type
{
	EntityId _entityId;

	// TODO: Add pointer info
	// TODO: Add Literal for better type inference?
public:

	Type(EntityId entityId) :
	_entityId(entityId)
	{}
	Type(Type&&) = default;
	Type(const Type&) = default;
	~Type() = default;

	String getName() const;

	bool canConvertTo(const Type& other);

	const auto& entityId() const { return _entityId; }
};

extern const Type voidType;
extern const Type i32Type;

#endif