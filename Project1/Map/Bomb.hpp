#pragma once
#include "Header.h"
#include "Player.hpp"
#include "Entity.hpp"

namespace Map {
	class Bomb {

	private:
		Player owner;

	};
}
public PlayerEntity Owner{ get; set; }
public int BombRadius{ get; set; }
public int BombTimer{ get; set; }
public bool IsExploding{ get; set; }
public int Points{ get; set; }