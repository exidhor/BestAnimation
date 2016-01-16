#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <vector>
#include "AnimationPerTile.hpp"
#include "PersonalAnimationManager.hpp"


class TileAnimationManager : public PersonalAnimationManager
{
private:
public:
	TileAnimationManager();
};