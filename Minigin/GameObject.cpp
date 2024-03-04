#include <string>
#include "GameObject.h"
#include "BaseComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Transform.h"
using namespace dae;


dae::GameObject::GameObject()
{
}

dae::GameObject::~GameObject() {
	
}

int dae::GameObject::GetChildCount() const
{
    return int(m_Children.size());
}

GameObject* dae::GameObject::GetChildAt(size_t index) const {
    if (index < m_Children.size()) {
        return m_Children[index].get();
    }
    return nullptr; // Return nullptr if index is out of range
}

float dae::GameObject::GetRotation() const
{
    return m_transform.GetRotation();
}

void dae::GameObject::SetRotation(float rotation)
{
    m_transform.SetRotation(rotation);
}

inline glm::vec3 dae::GameObject::GetWorldPosition() const {
    if (m_Parent) {
        return m_Parent->m_transform.GetWorldPosition() + m_transform.GetLocalPosition();
    }
    return m_transform.GetWorldPosition();
}

void dae::GameObject::SetLocalPosition(float x, float y)
{
	 m_transform.SetLocalPosition(x, y);
}

glm::vec3 dae::GameObject::GetLocalPosition() const
{
    return m_transform.GetLocalPosition();
}

void dae::GameObject::Update(float deltaTime) {
	for (auto& component : m_components)
	{
		component->Update(deltaTime);
	}

	for (auto& gameObject : m_Children)
	{
		gameObject->Update(deltaTime);
	}
}
void dae::GameObject::FixedUpdate(float fixedTimeStep){
	for (auto& gameObject : m_Children)
	{
		gameObject->FixedUpdate(fixedTimeStep);
	}
}

void dae::GameObject::Render() const
{
    glm::vec3 positionToRender;

    if (m_Parent)
    {
        // If there is a parent, use the local position
        positionToRender = m_transform.GetLocalPosition();
    }
    else
    {
        // If there is no parent, use the world position
        positionToRender = m_transform.GetWorldPosition();
    }


    for (auto& component : m_components)
    {
        component->Render(positionToRender);
    }
}

void dae::GameObject::SetPosition(float x, float y)
{
    if (m_Parent)
    {
        // Calculate local position relative to parent
        float parentX = m_Parent->m_transform.GetWorldPosition().x;
        float parentY = m_Parent->m_transform.GetWorldPosition().y;
        float localX = x - parentX;
        float localY = y - parentY;
        m_transform.SetLocalPosition(localX, localY);
    }
    else
    {
        // Set position in world coordinates
        m_transform.SetWorldPosition(x, y);
    }

    SetDirty();
}

void dae::GameObject::SetParent(std::shared_ptr<GameObject> parent)
{
    if (m_Parent)
        m_Parent->RemoveChild(this);

    m_Parent = parent;

    if (m_Parent)
        m_Parent->AddChild(std::unique_ptr<GameObject>(this));
    
}

void dae::GameObject::AddChild(std::unique_ptr<GameObject> gameObject)
{
    m_Children.push_back(std::move(gameObject));
}

void dae::GameObject::RemoveChild(GameObject* gameObject)
{
    auto it = std::find_if(m_Children.begin(), m_Children.end(),
        [gameObject](const std::unique_ptr<GameObject>& ptr) {
            return ptr.get() == gameObject;
        });
    if (it != m_Children.end())
        m_Children.erase(it);
}
