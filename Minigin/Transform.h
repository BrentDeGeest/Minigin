#pragma once
#include <glm/glm.hpp>
#include "BaseComponent.h"

namespace dae
{
	class Transform final 
	{
	public:
		const glm::vec3& GetPosition() const { return m_position; }
		const glm::vec3& GetSize() const { return m_size; }
		const glm::vec3& GetRotation() const { return m_rotation; }
		void SetPosition(float x, float y, float z);
		void SetSize(float x, float y, float z);
		void SetRotation(float x, float y, float z);
		
	private:
		glm::vec3 m_position;
		glm::vec3 m_size;
		glm::vec3 m_rotation;
	};
}
