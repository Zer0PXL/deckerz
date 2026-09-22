#include <raylib.h>
#include <iostream>
#include "PlayState.hpp"
#include "Debug.hpp"
#include "GFX.hpp"
#include "UI.hpp"
using namespace std;

#ifdef DEBUG
bool debugMode = true;
bool cheats = true;
#else
bool debugMode = false;
bool cheats = false;
#endif

int main()
{
	// SFML is being deprecated.

	std::cout << "Deckerz GUI v0.1\n";
	std::cout << "! - This version is mid transition from SFML->raylib\n";

	// old SFML graphics objects
	/*sf::Texture bgTexture("res/bg.png");
	sf::Sprite bpsprite(bgTexture);

	sf::Vector2f mousePos;*/

	// raylib graphics objects
	InitWindow(windowWidth, windowHeight, "Deckerz - DEBUG raylib prototype");

	SetTargetFPS(60);

	// My graphics objects
	UI ui;

	// State Manager
	StateManager stateMan;
	stateMan.setState(GameState::Play); // temporary

	// PlayState
	PlayState ps;
	ps.resetBonuses();

	// Start of SFML window loop
	while (!WindowShouldClose())
	{
		// Initialize stuff
		// auto mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
		// ui.resetInteracts();
		// ui.setMouse(mousePos);

		// SFML events
		// while (const optional event = window.pollEvent()) ui.inputHandler(window, event);
		
		// If it's the AI's turn, the AI plays
		//if (ps.getTurn() == Turn::AI) ps.aiTurn();
		// Else, the player gets to play
		//else ps.PlayerIntHandler(ui.getInteracts());

		// Layout everything
		//if (ui.getInteracts().playerInteraction == PI::Play) ui.resetMCs();
		//Snapshot snapshot = ps.snapshot();
		//ui.layoutHandler(window, snapshot);

		// Check collision
		//ui.collisionHandler();

		// Draw everything
		BeginDrawing();
		{
			// Clear window and draw background
			ClearBackground(RAYWHITE);
			DrawText("imagine there was like a card game here or something", 190, 200, 20, BLACK);

			//ui.drawhandler()
		}
		EndDrawing();
	}

	CloseWindow();

	return 0;
}