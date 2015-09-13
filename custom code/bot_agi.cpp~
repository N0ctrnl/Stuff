// Agility Buff - N0ctrnl
	if ((!strcasecmp(sep->arg[1], "buff") && !strcasecmp(sep->arg[2], "agi")) && (c->IsGrouped())) {
		Mob *AgiCaster;
		uint32 AgiClass = 0;
		Group *g = c->GetGroup();
		Mob *target = c->GetTarget();
		if(g) {
			for(int i = 0; i < MAX_GROUP_MEMBERS; i++){
				if(g->members[i] && g->members[i]->IsBot()) {
					switch(g->members[i]->GetClass()) {
						case SHAMAN:
							AgiCaster = g->members[i];
							AgiClass = SHAMAN;
							break;
						case RANGER:
							if(AgiClass != SHAMAN){
								AgiCaster = g->members[i];
								AgiClass = RANGER;
							}
							break;
					default:
						break;
					}
				}
			}
			switch(AgiClass) {
                                case SHAMAN:
                                        if (c->GetLevel() >= 53) { AgiCaster->CastToBot()->SpellOnTarget(1594, target); }
                                        else if (c->GetLevel() >= 41) { AgiCaster->CastToBot()->SpellOnTarget(154, target); }
                                        else if (c->GetLevel() >= 31) { AgiCaster->CastToBot()->SpellOnTarget(160, target); }
                                        else if (c->GetLevel() >= 18) { AgiCaster->CastToBot()->SpellOnTarget(148, target); }
                                        else if (c->GetLevel() >= 3) { AgiCaster->CastToBot()->SpellOnTarget(269, target); }
					else if (c->GetLevel() <= 2) { AgiCaster->CastToBot()->BotGroupSay(AgiCaster->CastToBot(), "I must reach level 3 before casting an agility buff."); }
					break;
						
				case RANGER:
                                        if (c->GetLevel() >= 12) { AgiCaster->CastToBot()->SpellOnTarget(269, target); }
					else if (c->GetLevel() <= 11) { AgiCaster->CastToBot()->BotGroupSay(AgiCaster->CastToBot(), "I must reach level 12 before casting an agility buff."); }
                                        break;
                        }
		}
	}

