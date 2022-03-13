#include "Assets.h"

#include "MeshBuilder.h"

namespace HGE
{
	std::shared_ptr<Assets> Assets::Initialize()
	{
		std::shared_ptr<Assets> rtrn = std::make_shared<Assets>();

		rtrn->Self = rtrn;
		rtrn->Meshbuilder = rtrn->Meshbuilder->Initialize(rtrn);

		return rtrn;
	}
}