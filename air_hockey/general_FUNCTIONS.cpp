#include "air_hockey_GENERAL_HEADER.h"

void sleep(int count)
{
	for (int i = 0; i < count; ++i);
	/* this is just a delay thing
	becasue Windows.h doesnt work with SFML for some reason
	*/
}