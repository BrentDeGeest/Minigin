#pragma once
#include <memory>
#include "Transform.h"
#include <vector>

namespace dae
{
	class BaseComponent;

	class GameObject final
	{
	public:
		virtual void Update(float deltaTime);
		virtual void FixedUpdate(float fixedTimeStep);
		virtual void Render() const;

		void SetPosition(float x, float y);

		// component code
		template<typename T> 
		T* AddComponent() {
			std::unique_ptr<T> newComponent = std::make_unique<T>(this);
			m_components.push_back(std::move(newComponent));
			return dynamic_cast<T*>(m_components.back().get());
		};

		template<typename T> 
		void RemoveComponent() {
			for (auto it = m_components.begin(); it != m_components.end(); ++it) {
				if (dynamic_cast<T*>((*it).get())) {
					m_components.erase(it);
					return;
				}
			}
		};

		template<typename T> 
		T* GetComponent() {
			for (auto& component : m_components) {
				if (dynamic_cast<T*>(component.get())) {
					return dynamic_cast<T*>(component.get());
				}
			}
			return nullptr;
		};

		// rule of 5
		GameObject();
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_transform{};
		std::vector<std::unique_ptr<BaseComponent>> m_components;
		bool m_IsActive{ true };
	};
	
}
