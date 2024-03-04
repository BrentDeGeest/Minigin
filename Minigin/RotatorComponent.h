#pragma once
#include "BaseComponent.h"

namespace dae {
    class RotatorComponent : public BaseComponent
    {
    public:
        RotatorComponent(GameObject* gameObject, float rotationSpeed);
        void Update(float deltaTime) override;

    private:
        float m_RotationSpeed;
    };
}

