// Divine HP Buff - N0ctrnl
	if ((!strcasecmp(sep->arg[1], "buff") && !strcasecmp(sep->arg[2], "di")) && (c->IsGrouped())) {
		Mob *DivineCaster;
		uint32 DivineClass = 0;
		Group *g = c->GetGroup();
		Mob *target = c->GetTarget();
		if(g) {
			for(int i = 0; i < MAX_GROUP_MEMBERS; i++){
				if(g->members[i] && g->members[i]->IsBot()) {
					switch(g->members[i]->GetClass()) {
						case PALADIN:
							DivineCaster = g->members[i];
							DivineClass = PALADIN;
							break;
					default:
						break;
					}
				}
			}
			switch(DivineClass) {
                                case PALADIN:
                                        if (c->GetLevel() >= 60) { DivineCaster->CastToBot()->SpellOnTarget(2590, target); }
                                        else if (c->GetLevel() >= 49) { DivineCaster->CastToBot()->SpellOnTarget(3578, target); }
                                        else if (c->GetLevel() >= 35) { DivineCaster->CastToBot()->SpellOnTarget(2584, target); }
					else if (c->GetLevel() <= 34) { DivineCaster->CastToBot()->BotGroupSay(DivineCaster->CastToBot(), "I must reach level 35 before casting a paladin hitpoint buff."); }
					break;
                        }
		}
	}

