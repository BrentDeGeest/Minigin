#pragma once
#include <glm/glm.hpp>
#include "BaseComponent.h"

namespace dae
{
	class Transform final 
	{
	public:
		const glm::vec3& GetWorldPosition() const { return m_WorldPosition; }
		const glm::vec3& GetLocalPosition() const { return m_LocalPosition; }
		const glm::vec3& GetSize() const { return m_size; }
		const float GetRotation() const { return m_rotation; }
		void SetWorldPosition(float x, float y, float z = 0.0f);
		void SetLocalPosition(float x, float y, float z = 0.0f);
		void SetSize(float x, float y, float z);
		void SetRotation(float rotation);
		
	private:
		glm::vec3 m_WorldPosition;
		glm::vec3 m_LocalPosition;
		glm::vec3 m_size;
		float m_rotation;
	};
}
