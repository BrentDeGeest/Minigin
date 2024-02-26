#pragma once
#include <memory>
#include "BaseComponent.h"

namespace dae {
	class TextComponent;
	class FPSComponent final : public BaseComponent
	{
	public:
		FPSComponent();
		void Update(float deltaTime) override;
		void UpdateTextComponent();
		void FixedUpdate(float fixedTimeStep) override;
		void Render(glm::vec3 pos) const override;

		float GetFps() const;

	private:
		int m_FrameCount;
		float m_Fps;
		float m_ElapsedTime;
		std::weak_ptr<TextComponent> m_textComponent;
	};
}

