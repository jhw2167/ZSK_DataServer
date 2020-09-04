#pragma once

/*
	ZSK_DataServer application will be a constant running
	ZSK auxillary application that helps handle the game users,
	routing and connecting games and so on.
	- Data server will handle create game requests and match game
	codes to IP addresses
	- Will handle log in info and confirmation for users
*/

#include "BaseCode/pch/stdafx.h"
#include "Core/TCP.h"
#include "Core/UDP.h"