#include <string>
#include "GameObject.h"
#include "BaseComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Transform.h"


dae::GameObject::GameObject()
{
}

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update(float deltaTime) {
	for (auto& component : m_components)
	{
		component->Update(deltaTime);
	}
}
void dae::GameObject::FixedUpdate(float){}

void dae::GameObject::Render() const
{
	const auto& pos = m_transform.GetPosition();
	for (auto& component : m_components)
	{
		component->Render(pos);
	}
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}
