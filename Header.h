#pragma once

#include "raylib.h"
#include "iostream"

struct s_student {
	int HP;
	int x;
	int y;
	int price;

} t_student;

struct s_enemi {
	int HP;
	int x;
	int y;
	int atac;

} t_enemi;

struct s_atac_student {
	int atac;
	int x;
	int y;

};

struct s_plitki {
	int x;
	int y;

} t_plitki;

void RenderMap(const char* filename);

