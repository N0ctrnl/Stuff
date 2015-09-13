// Damage Shield Buff - N0ctrnl
	if ((!strcasecmp(sep->arg[1], "buff") && !strcasecmp(sep->arg[2], "ds")) && (c->IsGrouped())) {
		Mob *DSCaster;
		uint32 DSClass = 0;
		Group *g = c->GetGroup();
		Mob *target = c->GetTarget();
		if(g) {
			for(int i = 0; i < MAX_GROUP_MEMBERS; i++){
				if(g->members[i] && g->members[i]->IsBot()) {
					switch(g->members[i]->GetClass()) {
						case DRUID:
							DSCaster = g->members[i];
							DSClass = DRUID;
							break;
						case MAGICIAN:
							if(DSClass != DRUID){
								DSCaster = g->members[i];
								DSClass = MAGICIAN;
							}
							break;
						case RANGER:
							if(DSClass == 0){
								DSCaster = g->members[i];
								DSClass = RANGER;
							break:
					default:
						break;
					}
				}
			}
			switch(DSClass) {
                                case DRUID:
                                        if (c->GetLevel() >= 58) { DSCaster->CastToBot()->SpellOnTarget(1560, target); }
                                        else if (c->GetLevel() >= 47) { DSCaster->CastToBot()->SpellOnTarget(356, target); }
                                        else if (c->GetLevel() >= 37) { DSCaster->CastToBot()->SpellOnTarget(432, target); }
                                        else if (c->GetLevel() >= 27) { DSCaster->CastToBot()->SpellOnTarget(129, target); }
                                        else if (c->GetLevel() >= 17) { DSCaster->CastToBot()->SpellOnTarget(273, target); }
                                        else if (c->GetLevel() >= 7) { DSCaster->CastToBot()->SpellOnTarget(256, target); }
					else if (c->GetLevel() <= 6) { DSCaster->CastToBot()->BotGroupSay(DSCaster->CastToBot(), "I must reach level 6 before casting a damage shield buff."); }
					break;
						
				case MAGICIAN:
                                        if (c->GetLevel() >= 56) { DSCaster->CastToBot()->SpellOnTarget(1667, target); }
                                        else if (c->GetLevel() >= 45) { DSCaster->CastToBot()->SpellOnTarget(412, target); }
                                        else if (c->GetLevel() >= 28) { DSCaster->CastToBot()->SpellOnTarget(479, target); }
                                        else if (c->GetLevel() >= 19) { DSCaster->CastToBot()->SpellOnTarget(411, target); }
                                        else if (c->GetLevel() >= 7) { DSCaster->CastToBot()->SpellOnTarget(332, target); }
					else if (c->GetLevel() <= 6) { DSCaster->CastToBot()->BotGroupSay(DSCaster->CastToBot(), "I must reach level 6 before casting a damage shield buff."); }
                                        break;

				case RANGER:
                                        if (c->GetLevel() >= 58) { DSCaster->CastToBot()->SpellOnTarget(432, target); }
                                        if (c->GetLevel() >= 43) { DSCaster->CastToBot()->SpellOnTarget(129, target); }
                                        if (c->GetLevel() >= 24) { DSCaster->CastToBot()->SpellOnTarget(256, target); }
					else if (c->GetLevel() <= 23) { DSCaster->CastToBot()->BotGroupSay(DSCaster->CastToBot(), "I must reach level 23 before casting a damage shield buff."); }

                        }
		}
	}

