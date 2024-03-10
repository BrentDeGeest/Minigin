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
		void Update(float deltaTime);
		void FixedUpdate(float fixedTimeStep);
		void Render() const;

		void SetPosition(float x, float y);

		// component code
		template<typename T> 
		T* AddComponent() {
			auto newComponent = std::make_unique<T>(this);
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
		~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;


		void SetParent(std::shared_ptr<GameObject> parent);
		int GetChildCount()const;
		GameObject* GetChildAt(size_t index) const;

		glm::vec3 GetWorldPosition() const;
		void SetLocalPosition(float x, float y);
		glm::vec3 GetLocalPosition() const;

		float GetRotation() const;
		void SetRotation(float rotation);
		
		void SetDirty() { m_IsDirty = true; }
		bool IsDirty() const { return m_IsDirty; }
		void ClearDirty() { m_IsDirty = false; }
	protected:

	private:
		Transform m_transform{};
		std::vector<std::unique_ptr<BaseComponent>> m_components;
		bool m_IsActive{ true };

		// hierarchy system
		std::vector<std::unique_ptr<GameObject>> m_Children;
		std::shared_ptr<GameObject> m_Parent;

		// hierarchy system
		void AddChild(std::unique_ptr<GameObject> gameObject);
		void RemoveChild(GameObject* gameObject);

		bool m_IsDirty = true;
	};
	
}
