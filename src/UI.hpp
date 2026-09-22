#pragma once
#include "GFX.hpp"
#include <optional>
#include <memory>
#include <unordered_map>

// PlayerInteraction
enum class PlayerInt
{
    None,
    Play,
    Draw
};

// Dumb name, but it's the logic that goes to PlayState
struct Interactions
{
    PlayerInt playerInteraction = PlayerInt::None;
    std::unordered_map<int, MiddleCard> playedCards;
};

// A photo of the screen
// (not literally)
struct Snapshot
{
    std::vector<std::shared_ptr<Card>> playerHand;
    std::shared_ptr<Card> pileCard;
};

class UI
{
private:
    // Interactions
    // sf::Vector2f mousePos;
    Interactions interacts;

    // MiddleCards
	std::unordered_map<int, MiddleCard> middleCards; // Uses UCID as a key
	std::unordered_map<int, MiddleCard> selectedCards; // Uses UCID as a key

    // Buttons
	// std::vector<Button> buttons;
public:
    void setMouse(int mPos);
    void resetInteracts();
    Interactions getInteracts();
    void resetMCs();

    Interactions inputHandler(int& window, std::optional<std::shared_ptr<int>> event);
    void layoutHandler(int& window, Snapshot snapshot);
    void collisionHandler();
    void drawHandler(int& window);
};