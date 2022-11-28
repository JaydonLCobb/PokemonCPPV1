#ifndef POKE327_H
#define POKE327_H
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "heap.h"
using namespace std;

typedef class Character character_t;

#define malloc(size) ({          \
  void *_tmp;                    \
  assert((_tmp = malloc(size))); \
  _tmp;                          \
})

/* Returns true if random float in [0,1] is less than *
 * numerator/denominator.  Uses only integer math.    */
#define rand_under(numerator, denominator) \
  (rand() < ((RAND_MAX / denominator) * numerator))

/* Returns random integer in [min, max]. */
#define rand_range(min, max) ((rand() % (((max) + 1) - (min))) + (min))

#define UNUSED(f) ((void)f)

typedef enum dim
{
  dim_x,
  dim_y,
  num_dims
} dim_t;

typedef int16_t pair_t[num_dims];
typedef class Map map_t;
typedef class Character character_t;
typedef class World world_t;
typedef class NPC npc_t;
typedef class PC pc_t;

#define MAP_X 80
#define MAP_Y 21
#define MIN_TREES 10
#define MIN_BOULDERS 10
#define TREE_PROB 95
#define BOULDER_PROB 95
#define WORLD_SIZE 401
#define MIN_TRAINERS 7
#define ADD_TRAINER_PROB 50

#define mappair(pair) (m->map[pair[dim_y]][pair[dim_x]])
#define mapxy(x, y) (m->map[y][x])
#define heightpair(pair) (m->height[pair[dim_y]][pair[dim_x]])
#define heightxy(x, y) (m->height[y][x])

typedef enum __attribute__((__packed__)) terrain_type
{
  ter_boulder,
  ter_tree,
  ter_path,
  ter_mart,
  ter_center,
  ter_grass,
  ter_clearing,
  ter_mountain,
  ter_forest,
  ter_exit,
  num_terrain_types
} terrain_type_t;

class Map
{
public:
  terrain_type_t map[MAP_Y][MAP_X];
  uint8_t height[MAP_Y][MAP_X];
  character_t *cmap[MAP_Y][MAP_X];
  heap_t turn;
  int32_t num_trainers;
  int8_t n, s, e, w;
};

class Character
{
public:
  NPC *npc;
  PC *pc;
  pair_t pos;
  char symbol;
  int next_turn;
};

class World
{
public:
  map_t *world[WORLD_SIZE][WORLD_SIZE];
  pair_t cur_idx;
  map_t *cur_map;
  int hiker_dist[MAP_Y][MAP_X];
  int rival_dist[MAP_Y][MAP_X];
  character_t pc;
  int quit;
};

// here
class pokemon_t
{
public:
  int p_id;
  string p_identifier;
  int p_species_id;
  int p_height;
  int p_weight;
  int p_base_experience;
  int p_order;
  int p_is_default;

  pokemon_t(int p_id, string p_identifier, int p_species_id, int p_height, int p_weight, int p_base_experience, int p_order, int p_is_default)
  {
    this->p_id = p_id;
    this->p_identifier = p_identifier;
    this->p_species_id = p_species_id;
    this->p_height = p_height;
    this->p_weight = p_weight;
    this->p_base_experience = p_base_experience;
    this->p_order = p_order;
    this->p_is_default = p_is_default;
  }

  void outPoke()
  {
    cout << p_id << ", " << p_identifier << ", " << p_species_id << ", " << p_height << ", " << p_weight << ", " << p_base_experience << ", " << p_order << ", " << p_is_default << endl;
  }
};

class moves_t
{
public:
  int m_id;
  string a;
  string m_identifier;
  int m_generation_id;
  string b;
  int m_type_id;
  string c;
  int m_power;
  string d;
  int m_pp;
  string e;
  int m_accuracy;
  string f;
  int m_priority;
  string g;
  int m_target_id;
  string h;
  int m_damage_class_id;
  string i;
  int m_effect_id;
  string j;
  int m_effect_chance;
  string k;
  int m_contest_type_id;
  string l;
  int m_contest_effect_id;
  string m;
  int m_super_contest_effect_id;
  string n;

  moves_t(int m_id, string m_identifier, int m_generation_id, int m_type_id, int m_power, int m_pp, int m_accuracy, int m_priority, int m_target_id, int m_damage_class_id, int m_effect_id, int m_effect_chance, int m_contest_type_id, int m_contest_effect_id, int m_super_contest_effect_id)
  {
    this->m_id = m_id;
    this->m_identifier = m_identifier;
    this->m_generation_id = m_generation_id;
    this->m_type_id = m_type_id;
    this->m_power = m_power;
    this->m_pp = m_pp;
    this->m_accuracy = m_accuracy;
    this->m_priority = m_priority;
    this->m_target_id = m_target_id;
    this->m_damage_class_id = m_damage_class_id;
    this->m_effect_id = m_effect_id;
    this->m_effect_chance = m_effect_chance;
    this->m_contest_type_id = m_contest_type_id;
    this->m_contest_effect_id = m_contest_effect_id;
    this->m_super_contest_effect_id = m_super_contest_effect_id;
  }

  void outMove()
  {
    cout << m_id << ", " << m_identifier << ", " << m_generation_id << ", " << m_type_id << ", " << m_power << ", " << m_pp << ", " << m_accuracy << ", " << m_priority << ", " << m_target_id << ", " << m_damage_class_id << ", " << m_effect_id << ", " << m_effect_chance << ", " << m_contest_type_id << ", " << m_contest_effect_id << ", " << m_super_contest_effect_id << endl;
  }
};

class pokemon_moves_t
{
public:
  int pm_pokemon_id;
  int pm_version_group_id;
  int pm_move_id;
  int pm_pokemon_move_method_id;
  int pm_level;
  int pm_order;

  pokemon_moves_t(int pm_pokemon_id, int pm_version_group_id, int pm_move_id, int pm_pokemon_move_method_id, int pm_level, int pm_order)
  {
    this->pm_pokemon_id = pm_pokemon_id;
    this->pm_version_group_id = pm_version_group_id;
    this->pm_move_id = pm_move_id;
    this->pm_pokemon_move_method_id = pm_pokemon_move_method_id;
    this->pm_level = pm_level;
    this->pm_order = pm_order;
  }

  void outMoves()
  {
    cout << pm_pokemon_id << ", " << pm_version_group_id << ", " << pm_move_id << ", " << pm_pokemon_move_method_id << ", " << pm_level << ", " << pm_order << endl;
  }
};

class pokemon_species_t
{
public:
  int ps_id;
  string ps_identifier;
  int ps_generation_id;
  int ps_evolves_from_species_id;
  int ps_evolution_chain_id;
  int ps_color_id;
  int ps_shape_id;
  int ps_habitat_id;
  int ps_gender_rate;
  int ps_capture_rate;
  int ps_base_happiness;
  int ps_is_baby;
  int ps_hatch_counter;
  int ps_has_gender_differences;
  int ps_growth_rate_id;
  int ps_forms_switchable;
  int ps_is_legendary;
  int ps_is_mythical;
  int ps_order;
  int ps_conquest_order;

  pokemon_species_t(int ps_id, string ps_identifier, int ps_generation_id, int ps_evolves_from_species_id, int ps_evolution_chain_id, int ps_color_id, int ps_shape_id, int ps_habitat_id, int ps_gender_rate,
                    int ps_capture_rate, int ps_base_happiness, int ps_is_baby, int ps_hatch_counter, int ps_has_gender_differences, int ps_growth_rate_id, int ps_forms_switchable, int ps_is_legendary, int ps_is_mythical, int ps_order, int ps_conquest_order)
  {
    this->ps_id = ps_id;
    this->ps_identifier = ps_identifier;
    this->ps_generation_id = ps_generation_id;
    this->ps_evolves_from_species_id = ps_evolves_from_species_id;
    this->ps_evolution_chain_id = ps_evolution_chain_id;
    this->ps_color_id = ps_color_id;
    this->ps_shape_id = ps_shape_id;
    this->ps_habitat_id = ps_habitat_id;
    this->ps_gender_rate = ps_gender_rate;
    this->ps_capture_rate = ps_capture_rate;
    this->ps_base_happiness = ps_base_happiness;
    this->ps_is_baby = ps_is_baby;
    this->ps_hatch_counter = ps_hatch_counter;
    this->ps_has_gender_differences = ps_has_gender_differences;
    this->ps_growth_rate_id = ps_growth_rate_id;
    this->ps_forms_switchable = ps_forms_switchable;
    this->ps_is_legendary = ps_is_legendary;
    this->ps_is_mythical = ps_is_mythical;
    this->ps_order = ps_order;
    this->ps_conquest_order = ps_conquest_order;
  }

  void outSpecies()
  {
    cout << ps_id << ", " << ps_identifier << ", " << ps_generation_id << ", " << ps_evolves_from_species_id << ", " << ps_evolution_chain_id << ", " << ps_color_id << " , " << ps_shape_id << ", " << ps_habitat_id << ", " << ps_gender_rate << ", " << ps_capture_rate << ", " << ps_base_happiness << ", " << ps_is_baby << ", " << ps_hatch_counter << ", " << ps_has_gender_differences << ", " << ps_growth_rate_id << ", " << ps_forms_switchable << ", " << ps_is_legendary << ", " << ps_is_mythical << ", " << ps_order << ", " << ps_conquest_order << endl;
  }
};

class experience_t
{
public:
  int e_growth_rate_id;
  int e_level;
  int e_experience;

  experience_t(int e_growth_rate_id, int e_level, int e_experience)
  {
    this->e_growth_rate_id = e_growth_rate_id;
    this->e_level = e_level;
    this->e_experience = e_experience;
  }

  void outExperience()
  {
    cout << e_growth_rate_id << ", " << e_level << ", " << e_experience << endl;
  }
};

class type_names_t
{
public:
  int t_type_id;
  int t_local_language_id;
  string t_name;

  type_names_t(int t_type_id, int t_local_language_id, string t_name)
  {
    this->t_type_id = t_type_id;
    this->t_local_language_id = t_local_language_id;
    this->t_name = t_name;
  }

  void outTypeNames()
  {
    cout << t_type_id << ", " << t_local_language_id << ", " << t_name << endl;
  }
};

class pokemon_stats_t
{
public:
  int pt_pokemon_id;
  int pt_stat_id;
  int pt_base_stat;
  int pt_effort;

  pokemon_stats_t(int pt_pokemon_id, int pt_stat_id, int pt_base_stat, int pt_effort)
  {
    this->pt_pokemon_id = pt_pokemon_id;
    this->pt_stat_id = pt_stat_id;
    this->pt_base_stat = pt_base_stat;
    this->pt_effort = pt_effort;
  }

  void outPmStats()
  {
    cout << pt_pokemon_id << ", " << pt_stat_id << ", " << pt_base_stat << ", " << pt_effort << endl;
  }
};

class stats_t
{
public:
  int st_id;
  int st_damage_class_id;
  string st_identifier;
  int st_is_battle_only;
  int st_game_index;

  stats_t(int st_id, int st_damage_class_id, string st_identifier, int st_is_battle_only, int st_game_index)
  {
    this->st_id = st_id;
    this->st_damage_class_id = st_damage_class_id;
    this->st_identifier = st_identifier;
    this->st_is_battle_only = st_is_battle_only;
    this->st_game_index = st_game_index;
  }

  void outStats()
  {
    cout << st_id << ", " << st_damage_class_id << ", " << st_identifier << ", " << st_is_battle_only << ", " << st_game_index << endl;
  }
};

class pokemon_types_t
{
public:
  int pt_pokemon_id;
  int pt_type_id;
  int pt_slot;

  pokemon_types_t(int pt_pokemon_id, int pt_type_id, int pt_slot)
  {
    this->pt_pokemon_id = pt_pokemon_id;
    this->pt_type_id = pt_type_id;
    this->pt_slot = pt_slot;
  }

  void out_pType()
  {
    cout << pt_pokemon_id << ", " << pt_type_id << ", " << pt_slot << endl;
  }
};

extern world_t world;

extern pair_t all_dirs[8];

#define rand_dir(dir)         \
  {                           \
    int _i = rand() & 0x7;    \
    dir[0] = all_dirs[_i][0]; \
    dir[1] = all_dirs[_i][1]; \
  }

typedef struct path
{
  heap_node_t *hn;
  uint8_t pos[2];
  uint8_t from[2];
  int32_t cost;
} path_t;

int new_map(int teleport);

extern vector<pokemon_t> poke_arr;
extern vector<pokemon_moves_t> pokemon_moves_t_arr;
extern vector<pokemon_moves_t> pokemon_moves_t_end_arr;
extern vector<moves_t> moves_t_arr;
extern vector<pokemon_stats_t> poke_stats_t_arr;
#endif
