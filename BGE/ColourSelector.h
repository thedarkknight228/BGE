#pragma once
#include "GameComponent.h"
#include "PhysicsController.h"
#include <memory>

using namespace std;

namespace BGE
{
	class ColourSelector
	{
	private:

	public:
		ColourSelector(void);
		~ColourSelector(void);
		struct ColourChange(string colour);
	};
}

