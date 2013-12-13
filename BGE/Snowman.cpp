#include "Snowman.h"
#include "Model.h"
#include "Content.h"

using namespace BGE;

Snowman::Snowman(float radius)
{
	std::shared_ptr<GameComponent> model (Content::LoadModel("sphere"));
	model->drawMode = Model::draw_modes::single_material;
	model->Initialise();
	diffuse = glm::vec3(0,0,1);
	specular = glm::vec3(1.2f,1.2f, 1.2f);
	tag = "Sphere";
	Attach(model);
	scale = glm::vec3(radius, radius, radius);
}


Snowman::~Snowman(void)
{
}
