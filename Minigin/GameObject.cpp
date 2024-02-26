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

void dae::GameObject::Update() {
	for (auto& component : m_components)
	{
		component->Update();
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
	//Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
}

//void dae::GameObject::SetTexture(const std::string& filename)
//{
//	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
//}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

/*
template<typename T>
T* dae::GameObject::AddComponent()
{
	std::unique_ptr<T> newComponent = std::make_unique<T>();
	m_components.push_back(std::move(newComponent));
	return dynamic_cast<T*>(m_components.back().get());
}

template<typename T>
void dae::GameObject::RemoveComponent()
{
	for (auto it = m_components.begin(); it != m_components.end(); ++it) {
		if (dynamic_cast<T*>((*it).get())) {
			m_components.erase(it);
			return;
		}
	}
}

template<typename T>
T* dae::GameObject::GetComponent() 
{
	for (auto& component : m_components) {
		if (dynamic_cast<T*>(component.get())) {
			return dynamic_cast<T*>(component.get());
		}
	}
	return nullptr;
}

*/


