#pragma once
#include <string>
#include <memory>
//#include "GameObject.h"
#include "BaseComponent.h"
#include "Transform.h"

namespace dae
{
	class Font;
	class Texture2D;
	class GameObject;

	class TextComponent final : public BaseComponent
	{
	public:
		void Update(float deltaTime) override;
		void FixedUpdate(float fixedTimeStep) override;
		void Render(glm::vec3 pos) const override;

		void SetText(const std::string& text);
		void SetPosition(float x, float y);

		void SetFont(std::shared_ptr<Font> font);

		TextComponent(GameObject* gameObject);
		//TextComponent(const std::string& text, std::shared_ptr<Font> font);
		virtual ~TextComponent() = default;
		TextComponent(const TextComponent& other) = delete;
		TextComponent(TextComponent&& other) = delete;
		TextComponent& operator=(const TextComponent& other) = delete;
		TextComponent& operator=(TextComponent&& other) = delete;

	private:
		//friend class GameObject;
		bool m_needsUpdate;
		std::string m_text;
		Transform m_transform{};
		std::shared_ptr<Font> m_font;
		std::shared_ptr<Texture2D> m_textTexture;
	};
}
