// Stamina Buff - N0ctrnl
	if ((!strcasecmp(sep->arg[1], "buff") && !strcasecmp(sep->arg[2], "sta")) && (c->IsGrouped())) {
		Mob *StaminaCaster;
		uint32 StaminaClass = 0;
		Group *g = c->GetGroup();
		Mob *target = c->GetTarget();
		if(g) {
			for(int i = 0; i < MAX_GROUP_MEMBERS; i++){
				if(g->members[i] && g->members[i]->IsBot()) {
					switch(g->members[i]->GetClass()) {
						case SHAMAN:
							StaminaCaster = g->members[i];
							StaminaClass = SHAMAN;
							break;
						case BEASTLORD:
							if(StaminaClass != SHAMAN){
								StaminaCaster = g->members[i];
								StaminaClass = BEASTLORD;
							}
							break;
						default:
							break;
					}
				}
			}
			switch(StaminaClass) {
                                case SHAMAN:
                                        if (c->GetLevel() >= 54) { StaminaCaster->CastToBot()->SpellOnTarget(1595, target); }
                                        else if (c->GetLevel() >= 43) { StaminaCaster->CastToBot()->SpellOnTarget(158, target); }
                                        else if (c->GetLevel() >= 30) { StaminaCaster->CastToBot()->SpellOnTarget(161, target); }
					else if (c->GetLevel() <= 29) { StaminaCaster->CastToBot()->BotGroupSay(StaminaCaster->CastToBot(), "I must reach level 30 before casting a stamina buff."); }
					break;
						
				case BEASTLORD:
                                        if (c->GetLevel() >= 57) { StaminaCaster->CastToBot()->SpellOnTarget(158, target); }
                                        else if (c->GetLevel() >= 52) { StaminaCaster->CastToBot()->SpellOnTarget(161, target); }
                                        else if (c->GetLevel() <= 51) { StaminaCaster->CastToBot()->BotGroupSay(StaminaCaster->CastToBot(), "I must reach level 53 before casting a focus buff."); }
                                        break;
                        }
		}
	}

