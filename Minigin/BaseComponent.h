#pragma once
#include <glm/fwd.hpp>

namespace dae
{
	class GameObject;
	class BaseComponent
	{
	public:

		virtual void Update(float deltaTime) = 0;
		virtual void FixedUpdate(float fixedTimeStep) = 0;
		virtual void Render(glm::vec3 pos) const = 0;

		virtual ~BaseComponent();
		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) = delete;

		GameObject* GetOwner();
	protected:
		BaseComponent(GameObject* gameObject);
	private:
		GameObject* m_Owner;
	};
}

