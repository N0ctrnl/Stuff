// Mana Regen Buff - N0ctrnl
	if ((!strcasecmp(sep->arg[1], "manaregen")) && (c->IsGrouped())) {
		Mob *ManaRegenCaster;
		uint32 ManaRegenClass = 0;
		Group *g = c->GetGroup();
		Mob *target = c->GetTarget();
		if(g) {
			for(int i = 0; i < MAX_GROUP_MEMBERS; i++){
				if(g->members[i] && g->members[i]->IsBot()) {
					switch(g->members[i]->GetClass()) {
						case CLERIC:
							ManaRegenCaster = g->members[i];
							ManaRegenClass = ENCHANTER;
							break;
					}
				}
			}
			switch(ManaRegenClass) {
                                case ENCHANTER:
                                        if (c->GetLevel() >= 60) {
                                                ManaRegenCaster->CastToBot()->BotGroupSay(ManaRegenCaster->CastToBot(), "Casting Koadic's Endless Intellect.");
                                                ManaRegenCaster->CastToBot()->SpellOnTarget(2570, target);
                                        }
                                        else if (c->GetLevel() >= 52) {
                                                ManaRegenCaster->CastToBot()->BotGroupSay(ManaRegenCaster->CastToBot(), "Casting Clarity II.");
                                                ManaRegenCaster->CastToBot()->SpellOnTarget(1693, target);
					}
                                        else if (c->GetLevel() >= 26) {
                                                ManaRegenCaster->CastToBot()->BotGroupSay(ManaRegenCaster->CastToBot(), "Casting Clarity.");
                                                ManaRegenCaster->CastToBot()->SpellOnTarget(174, target);
					}
                                        else if (c->GetLevel() >= 14) {
                                                ManaRegenCaster->CastToBot()->BotGroupSay(ManaRegenCaster->CastToBot(), "Casting Breeze.");
                                                ManaRegenCaster->CastToBot()->SpellOnTarget(697, target);
					}
                                        else if (c->GetLevel() <= 13) {
                                                ManaRegenCaster->CastToBot()->BotGroupSay(ManaRegenCaster->CastToBot(), "I must reach level 14 before casting a mana regen buff.");
                                        }
					break;
                        }
		}
	}
