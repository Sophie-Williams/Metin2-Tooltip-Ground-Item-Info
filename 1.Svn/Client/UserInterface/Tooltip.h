#pragma once

#if defined(TOOLTIP_GROUND_ITEM)
#include <array>
class TooltipData
{
public:
	enum config
	{
		TOOLTIP_LIMIT_DIST = 500,
		OWNER_NAME = 1,
	};

	TooltipData(const long* socket, const TPlayerItemAttribute* attr)
	{
		std::generate(Tooltip.begin(), Tooltip.end(), []() { return PyList_New(0); });

		for (size_t i = 0; i < ITEM_SOCKET_SLOT_MAX_NUM; i++)
			PyList_Append(Tooltip.at(T_SOCKET), Py_BuildValue("i", socket[i]));

		for (size_t i = 0; i < ITEM_ATTRIBUTE_SLOT_MAX_NUM; i++)
			PyList_Append(Tooltip.at(T_ATTR), Py_BuildValue("[ii]", attr[i].bType, attr[i].sValue));
	}
	~TooltipData()
	{
		for (const auto& v : Tooltip)
			Py_DECREF(v);
	}

	enum : size_t { T_SOCKET, T_ATTR, T_MAX };

	auto operator[] (const size_t idx) const { return Tooltip.at(idx); };

private:
	std::array<PyObject*, T_MAX> Tooltip;
};
#endif
