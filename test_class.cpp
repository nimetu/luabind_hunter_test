
extern "C"
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

#include <iostream>
#include <luabind/luabind.hpp>

class TestClass
{
public:
	TestClass() {
		std::cout << "TestClass created\n";
	}

};

int main()
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	using namespace luabind;
	open(L);

	module(L)
	[
		class_<TestClass>("TestClass")
			.def(constructor<>())
	];

	luaL_dostring(L, "local t = TestClass()");

    return 0;
}

