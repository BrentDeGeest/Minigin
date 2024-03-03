#pragma once
#include <memory>
#include "BaseComponent.h"
#include <string>


namespace dae {
	class Texture2D;
	class TextureComponent : public BaseComponent
	{
	public:

		void Update(float deltaTime) override;
		void FixedUpdate(float fixedTimeStep) override;
		void Render(glm::vec3 pos) const override;

		void SetTexture(const std::string& filename);

		TextureComponent(GameObject* gameObject);
		virtual ~TextureComponent() = default;
		TextureComponent(const TextureComponent& other) = delete;
		TextureComponent(TextureComponent&& other) = delete;
		TextureComponent& operator=(const TextureComponent& other) = delete;
		TextureComponent& operator=(TextureComponent&& other) = delete;
	private:
		std::shared_ptr<Texture2D> m_texture{};
	};
}

