#include "RotatorComponent.h"
#include "GameObject.h"

dae::RotatorComponent::RotatorComponent(GameObject* gameObject, float rotationSpeed) : 
	BaseComponent(gameObject),
	m_RotationSpeed{rotationSpeed}
{
}

void dae::RotatorComponent::Update(float deltaTime)
{
	GetOwner()->SetRotation(GetOwner()->GetRotation() + m_RotationSpeed * deltaTime);
}
