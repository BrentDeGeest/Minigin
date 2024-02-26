#include "Transform.h"

void dae::Transform::SetPosition(const float x, const float y, const float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

void dae::Transform::SetSize(const float x, const float y, const float z)
{
	m_size.x = x;
	m_size.y = y;
	m_size.z = z;
}

void dae::Transform::SetRotation(const float x, const float y, const float z)
{
	m_rotation.x = x;
	m_rotation.y = y;
	m_rotation.z = z;
}


