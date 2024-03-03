#include "TextureComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Transform.h"


dae::TextureComponent::TextureComponent(GameObject* gameObject):
	BaseComponent(gameObject)
{
}

void dae::TextureComponent::Update(float)
{
}

void dae::TextureComponent::FixedUpdate(float)
{
}

void dae::TextureComponent::Render(glm::vec3 pos) const
{
	Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
}

void dae::TextureComponent::SetTexture(const std::string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
}
