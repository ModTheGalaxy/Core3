theme_park_nightsister_outcast = Creature:new {
  objectName = "@mob/creature_names:nightsister_outcast",
  randomNameType = NAME_GENERIC,
  randomNameTag = true,
  socialGroup = "nightsister",
  faction = "nightsister",
  level = 81,
  chanceHit = 0.75,
  damageMin = 555,
  damageMax = 820,
  baseXp = 7761,
  baseHAM = 12000,
  baseHAMmax = 15000,
  armor = 1,
  resists = {30,30,30,100,100,100,100,100,-1},
  meatType = "",
  meatAmount = 0,
  hideType = "",
  hideAmount = 0,
  boneType = "",
  boneAmount = 0,
  milk = 0,
  tamingChance = 0,
  ferocity = 0,
  pvpBitmask = ATTACKABLE,
  creatureBitmask = NONE,
  optionsBitmask = AIENABLED + CONVERSABLE,
  diet = HERBIVORE,

  templates = {"object/mobile/dressed_dathomir_nightsister_outcast.iff"},
  lootGroups = {},
  weapons = {},
  conversationTemplate = "theme_park_nightsister_mission_target_convotemplate",
  attacks = merge(tkamid,brawlermaster)
}

CreatureTemplates:addCreatureTemplate(theme_park_nightsister_outcast, "theme_park_nightsister_outcast")