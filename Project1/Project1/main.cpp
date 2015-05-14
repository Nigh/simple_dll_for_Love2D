
extern "C"
{
#include "lua.h"
#include "lauxlib.h"
}

static int love_avr (lua_State *L)
{
	int n = lua_gettop(L);
	double sum = 0;
	int i;

	for (i = 1; i <= n; i++)
		sum += lua_tonumber(L, i);
	lua_pushnumber(L, sum / n);
	lua_pushnumber(L, sum);
	return 2;
}

static int love_doubles (lua_State *L)
{
    double d = lua_tonumber(L, 1);
	d = d*2;
	lua_pushnumber(L, d);
	return 1;
}

// these are methods that the library provides
static const struct luaL_reg love_methods [] =
{
	{ "doubles", love_doubles },
	{ "avr", love_avr },
	{NULL, 			NULL}
};

extern "C"
{
__declspec(dllexport) int luaopen_lovelib(lua_State *L)
{
	luaL_openlib (L, "lovelib", love_methods, 0);
	return 1;
}

}

