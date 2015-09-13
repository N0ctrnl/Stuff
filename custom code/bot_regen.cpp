// Regen Buff - N0ctrnl
	if ((!strcasecmp(sep->arg[1], "buff") && !strcasecmp(sep->arg[2], "regen")) && (c->IsGrouped())) {
		Mob *RegenCaster;
		uint32 RegenClass = 0;
		Group *g = c->GetGroup();
		Mob *target = c->GetTarget();
		if(g) {
			for(int i = 0; i < MAX_GROUP_MEMBERS; i++){
				if(g->members[i] && g->members[i]->IsBot()) {
					switch(g->members[i]->GetClass()) {
						case DRUID:
							RegenCaster = g->members[i];
							RegenClass = DRUID;
							break;
						case SHAMAN:
							if(RegenClass != DRUID){
								RegenCaster = g->members[i];
								RegenClass = SHAMAN;
							}
							break;
						case BEASTLORD:
							if (RegenClass == 0){
								RegenCaster = g->members[i];
								RegenClass = BEASTLORD;
							}
							break;
						case RANGER:
							if (RegenClass == 0){
								RegenCaster = g->members[i];
								RegenClass = RANGER;
							}
							break;
					default:
						break;
					}
				}
			}
			switch(RegenClass) {
                                case DRUID:
                                        if (c->GetLevel() >= 54) { RegenCaster->CastToBot()->SpellOnTarget(1568, target); }
                                        else if (c->GetLevel() >= 42) { RegenCaster->CastToBot()->SpellOnTarget(145, target); }
                                        else if (c->GetLevel() >= 34) { RegenCaster->CastToBot()->SpellOnTarget(144, target); }
					else if (c->GetLevel() <= 33) { RegenCaster->CastToBot()->BotGroupSay(RegenCaster->CastToBot(), "I must reach level 34 before casting a regeneration buff."); }
					break;
						
				case SHAMAN:
                                        if (c->GetLevel() >= 52) { RegenCaster->CastToBot()->SpellOnTarget(1568, target); }
                                        else if (c->GetLevel() >= 39) { RegenCaster->CastToBot()->SpellOnTarget(145, target); }
                                        else if (c->GetLevel() >= 23) { RegenCaster->CastToBot()->SpellOnTarget(144, target); }
                                        else if (c->GetLevel() <= 22) { RegenCaster->CastToBot()->BotGroupSay(RegenCaster->CastToBot(), "I must reach level 23 before casting a regeneration buff."); }
                                        break;

				case BEASTLORD:
                                        if (c->GetLevel() >= 55) { RegenCaster->CastToBot()->SpellOnTarget(145, target); }
                                        else if (c->GetLevel() <= 54) { RegenCaster->CastToBot()->BotGroupSay(RegenCaster->CastToBot(), "I must reach level 55 before casting a regeneration buff."); }

				case RANGER:
                                        if (c->GetLevel() >= 55) { RegenCaster->CastToBot()->SpellOnTarget(145, target); }
                                        else if (c->GetLevel() <= 54) { RegenCaster->CastToBot()->BotGroupSay(RegenCaster->CastToBot(), "I must reach level 55 before casting a regeneration buff."); }
                        }
		}
	}

