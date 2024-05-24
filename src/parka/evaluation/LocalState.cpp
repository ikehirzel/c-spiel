#include "parka/evaluation/LocalState.hpp"
#include "parka/ir/LValueIr.hpp"
#include "parka/log/Log.hpp"

namespace parka::evaluation
{
	LocalState::LocalState(GlobalState& globalState):
		_globalState(globalState),
		_values(1'048'576),
		_returnValueIndex(0),
		_jumpType(JumpType::None)
	{}

	Value& LocalState::pushValue(const ir::TypeIr& type)
	{
		return _values.push(type);
	}

	Value& LocalState::pushReturnValue(const ir::TypeIr& type)
	{

		auto length = _values.length();
		auto& value = _values.push(type);

		_returnValueIndex = length;

		return value;
	}

	usize LocalState::getReturnValueIndex()
	{
		return _returnValueIndex;
	}

	void LocalState::setReturnValueIndex(usize index)
	{
		_returnValueIndex = index;
	}

	usize LocalState::getScopeIndex()
	{
		return _values.length();
	}

	void LocalState::clearScopeValues(usize index)
	{
		_values.truncate(index);
	}

	void LocalState::setReturning(JumpType returningType)
	{
		_jumpType = returningType;
	}

	IntrinsicConversion LocalState::getConversion(const ir::TypeIr& to, const ir::TypeIr& from) const
	{
		return _globalState.getConversion(to, from);
	}

	Value& LocalState::findValue(const ir::LValueIr& node)
	{
		for (usize i = _values.length(); i-- > 0;)
		{
			auto& value = _values[i];
			
			if (value.nodePtr() == &node)
				return value;
		}

		log::fatal("Unable to get value for node: $", node.symbol());
	}

	Value& LocalState::returnValue()
	{
		assert(_returnValueIndex < _values.length());

		return _values[_returnValueIndex];
	}
}