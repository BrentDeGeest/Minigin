#include "BaseComponent.h"
#include "GameObject.h"

dae::BaseComponent::~BaseComponent() {
	//delete m_Owner;
}

dae::BaseComponent::BaseComponent(GameObject* gameObject):
	m_Owner{gameObject}
{
}

dae::GameObject* dae::BaseComponent::GetOwner() 
{
	return m_Owner;
}





