#pragma once
#include <memory>
#include "BaseComponent.h"

namespace dae {
	class TextComponent;
	class FPSComponent final : public BaseComponent
	{
	public:
		FPSComponent(GameObject* gameObject);
		void Update(float deltaTime) override;
		void FixedUpdate(float fixedTimeStep) override;
		void Render(glm::vec3 pos) const override;
		void SetTextComponent(TextComponent* component);
		float GetFps() const;

		virtual ~FPSComponent();

	private:
		int m_FrameCount;
		float m_Fps;
		float m_ElapsedTime;
		TextComponent* m_TextComponent = nullptr;
	};
}

