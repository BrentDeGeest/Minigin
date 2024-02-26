#include "FPSComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Transform.h"
#include <chrono>
#include "TextComponent.h"

dae::FPSComponent::FPSComponent() :
    m_FrameCount{0}, m_Fps{0.0f}, m_ElapsedTime{0.0f}
{
}

void dae::FPSComponent::Update(float deltaTime)
{
    // Increment frame count
    m_FrameCount++;

    // Accumulate elapsed time
    m_ElapsedTime += deltaTime;

    // If one second has elapsed, calculate FPSComponent
    if (m_ElapsedTime >= 1.0f) {
        // Calculate FPSComponent
        m_Fps = static_cast<float>(m_FrameCount) / m_ElapsedTime;
        UpdateTextComponent();
        // Reset frame count and elapsed time for next second
        m_FrameCount = 0;
        m_ElapsedTime -= 1.0f;
    }
}

void dae::FPSComponent::UpdateTextComponent()
{
    if (auto textComponentSharedPtr = m_textComponent.lock()) {
        auto textComponent = textComponentSharedPtr.get();
        float fps = GetFps();
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1) << fps;
        std::string fpsText = ss.str();
        textComponent->SetText(fpsText);
    }
}


void dae::FPSComponent::FixedUpdate(float)
{
}

void dae::FPSComponent::Render(glm::vec3) const
{
}

float dae::FPSComponent::GetFps() const
{
	return m_Fps;
}
