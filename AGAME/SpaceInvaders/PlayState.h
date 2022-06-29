#pragma once

#include "IGameState.h"

class Ship;

class PlayState : public IGameState
{
public:
	PlayState(Application* _app) : IGameState(_app) {}

	virtual void Start() override;
	virtual void Update(float _dt) override;
	virtual void Draw() override;
	virtual void OnDestroy() override;
protected:
private:
	Ship* m_ship = nullptr;
};