corvette_prisoner = Creature:new {
	objectName = "@mob/creature_names:prisoner",
	randomNameType = NAME_GENERIC,
	randomNameTag = true,
	socialGroup = "prisoner",
	faction = "",
	level = 12,
	chanceHit = 0.29,
	damageMin = 130,
	damageMax = 140,
	baseXp = 430,
	baseHAM = 1200,
	baseHAMmax = 1400,
	armor = 0,
	resists = {0,0,0,0,0,0,0,-1,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = NONE,
	creatureBitmask = NONE,
	optionsBitmask = AIENABLED + INTERESTING + INVULNERABLE,
	diet = HERBIVORE,

	templates = {
		"object/mobile/dressed_dathomir_prisoner_05.iff",
		"object/mobile/dressed_dathomir_prisoner_04.iff",
		"object/mobile/dressed_dathomir_prisoner_03.iff",
		"object/mobile/dressed_dathomir_prisoner_02.iff",
		"object/mobile/dressed_dathomir_prisoner_01.iff"},
	lootGroups = {},
	weapons = {},
	conversationTemplate = "",
	attacks = {}
}

CreatureTemplates:addCreatureTemplate(corvette_prisoner, "corvette_prisoner")