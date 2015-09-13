// Dexterity Buff - N0ctrnl
	if ((!strcasecmp(sep->arg[1], "buff") && !strcasecmp(sep->arg[2], "dex")) && (c->IsGrouped())) {
		Mob *DexCaster;
		uint32 DexClass = 0;
		Group *g = c->GetGroup();
		Mob *target = c->GetTarget();
		if(g) {
			for(int i = 0; i < MAX_GROUP_MEMBERS; i++){
				if(g->members[i] && g->members[i]->IsBot()) {
					switch(g->members[i]->GetClass()) {
						case SHAMAN:
							DexCaster = g->members[i];
							DexClass = SHAMAN;
							break;
						case BEASTLORD:
							if(DexClass != SHAMAN){
								DexCaster = g->members[i];
								DexClass = BEASTLORD;
							}
							break;
					default:
						break;
					}
				}
			}
			switch(DexClass) {
                                case SHAMAN:
                                        if (c->GetLevel() >= 58) { DexCaster->CastToBot()->SpellOnTarget(1596, target); }
                                        else if (c->GetLevel() >= 48) { DexCaster->CastToBot()->SpellOnTarget(157, target); }
                                        else if (c->GetLevel() >= 39) { DexCaster->CastToBot()->SpellOnTarget(152, target); }
                                        else if (c->GetLevel() >= 21) { DexCaster->CastToBot()->SpellOnTarget(146, target); }
                                        else if (c->GetLevel() >= 1) { DexCaster->CastToBot()->SpellOnTarget(266, target); }
					break;
						
				case BEASTLORD:
                                        if (c->GetLevel() >= 57) { DexCaster->CastToBot()->SpellOnTarget(157, target); }
                                        else if (c->GetLevel() >= 53) { DexCaster->CastToBot()->SpellOnTarget(152, target); }
                                        else if (c->GetLevel() >= 38) { DexCaster->CastToBot()->SpellOnTarget(146, target); }
					else if (c->GetLevel() <= 37) { DexCaster->CastToBot()->BotGroupSay(DexCaster->CastToBot(), "I must reach level 38 before casting a dexterity buff."); }
                                        break;
                        }
		}
	}

