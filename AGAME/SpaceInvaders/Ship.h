#pragma once

#include "IGameObject.h"

class Ship : public IGameObject
{
public:
	virtual void Start() override;
	virtual void Update(float _dt) override;
	virtual void Draw() override;
	virtual void OnDestroy() override;
private:
	float m_speed;
	float m_rotationSpeed;
};