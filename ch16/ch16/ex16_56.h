#pragma once
#include "ex16_48.h"
#include "ex16_53.h"



template <typename...Args>
std::ostream &errorMsg(std::ostream &os, const Args&... rest) {
	return print(os, debug_rep(rest)...);
}