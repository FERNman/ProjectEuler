#pragma once

#include "Util.h"

namespace Problems
{
	unsigned long long latticePaths()
	{
		unsigned int gridSize = 20;

		return Util::Factorial(gridSize + gridSize) / (Util::Factorial(gridSize) * Util::Factorial(gridSize));
	}
}