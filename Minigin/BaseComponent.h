#pragma once
#include <glm/fwd.hpp>

namespace dae
{
	class BaseComponent
	{
	public:

		virtual void Update(float deltaTime) = 0;
		virtual void FixedUpdate(float fixedTimeStep) = 0;
		virtual void Render(glm::vec3 pos) const = 0;

		BaseComponent() = default;
		virtual ~BaseComponent();
		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) = delete;
	private:

	};
}

