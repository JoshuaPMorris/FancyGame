#pragma once

class Application;

class IGameState
{
public:
	IGameState(Application* _app) { app = _app; }
	virtual void Start() {}
	virtual void Update(float _dt) {}
	virtual void Draw() {}
	virtual void OnDestroy() {}

	Application* app;

};