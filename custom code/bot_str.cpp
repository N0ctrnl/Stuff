// Strength Buff - N0ctrnl
	if ((!strcasecmp(sep->arg[1], "buff") && !strcasecmp(sep->arg[2], "ds")) && (c->IsGrouped())) {
		Mob *STRCaster;
		uint32 STRClass = 0;
		Group *g = c->GetGroup();
		Mob *target = c->GetTarget();
		if(g) {
			for(int i = 0; i < MAX_GROUP_MEMBERS; i++){
				if(g->members[i] && g->members[i]->IsBot()) {
					switch(g->members[i]->GetClass()) {
						case SHAMAN:
							STRCaster = g->members[i];
							STRClass = SHAMAN;
							break;
						case BEASTLORD:
							if(STRClass != SHAMAN){
								STRCaster = g->members[i];
								STRClass = BEASTLORD;
							}
							break;
						case DRUID:
							if(STRClass == 0){
								STRCaster = g->members[i];
								STRClass = DRUID;
							break:
						case RANGER:
							if(STRClass == 0){
								STRCaster = g->members[i];
								STRClass = RANGER;
							break:
					default:
						break;
					}
				}
			}
			switch(STRClass) {
                                case SHAMAN:
                                        if (c->GetLevel() >= 57) { STRCaster->CastToBot()->SpellOnTarget(1593, target); }
                                        else if (c->GetLevel() >= 46) { STRCaster->CastToBot()->SpellOnTarget(159, target); }
                                        else if (c->GetLevel() >= 39) { STRCaster->CastToBot()->SpellOnTarget(153, target); }
                                        else if (c->GetLevel() >= 28) { STRCaster->CastToBot()->SpellOnTarget(151, target); }
                                        else if (c->GetLevel() >= 18) { STRCaster->CastToBot()->SpellOnTarget(147, target); }
                                        else if (c->GetLevel() >= 1) { STRCaster->CastToBot()->SpellOnTarget(40, target); }
					break;
						
				case BEASTLORD:
                                        if (c->GetLevel() >= 54) { STRCaster->CastToBot()->SpellOnTarget(153, target); }
                                        else if (c->GetLevel() >= 41) { STRCaster->CastToBot()->SpellOnTarget(151, target); }
                                        else if (c->GetLevel() >= 28) { STRCaster->CastToBot()->SpellOnTarget(147, target); }
                                        else if (c->GetLevel() >= 14) { STRCaster->CastToBot()->SpellOnTarget(40, target); }
					else if (c->GetLevel() <= 13) { STRCaster->CastToBot()->BotGroupSay(STRCaster->CastToBot(), "I must reach level 6 before casting a strength buff."); }
                                        break;

				case DRUID:
                                        if (c->GetLevel() >= 44) { STRCaster->CastToBot()->SpellOnTarget(430, target); }
					else if (c->GetLevel() <= 43) { STRCaster->CastToBot()->BotGroupSay(STRCaster->CastToBot(), "I must reach level 44 before casting a strength buff."); }

				case DRUID:
                                        if (c->GetLevel() >= 53) { STRCaster->CastToBot()->SpellOnTarget(430, target); }
					else if (c->GetLevel() <= 52) { STRCaster->CastToBot()->BotGroupSay(STRCaster->CastToBot(), "I must reach level 53 before casting a strength buff."); }

                        }
		}
	}

