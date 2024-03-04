#include "Transform.h"



void dae::Transform::SetWorldPosition(float x, float y, float z)
{
	m_WorldPosition.x = x;
	m_WorldPosition.y = y;
	m_WorldPosition.z = z;
}

void dae::Transform::SetLocalPosition(float x, float y, float z)
{
	m_LocalPosition.x = x;
	m_LocalPosition.y = y;
	m_LocalPosition.z = z;
}

void dae::Transform::SetSize(const float x, const float y, const float z)
{
	m_size.x = x;
	m_size.y = y;
	m_size.z = z;
}

void dae::Transform::SetRotation(const float rotation)
{
	m_rotation = rotation;
	
}


